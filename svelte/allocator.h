#ifndef ZA_ALLOCATOR_H
#define ZA_ALLOCATOR_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ------------------- ALLOCATOR ----------------------
// 默认每次内存翻倍
#ifndef za_Delta
#define za_Delta 2
#endif

#ifndef za_INIT_SIZE
#define za_INIT_SIZE (1024 * 128)
#endif

#ifndef za_BIN_LEVEL
#define za_BIN_LEVEL 5
#endif

#ifndef za_BIN_LEVEL_SIZE
#define za_BIN_LEVEL_SIZE 16
#endif

#ifndef za_BIN_MIN_CHUNK
#define za_BIN_MIN_CHUNK 8
#endif

#if defined(__GNUC__) || defined(__clang__)
#define za_LIKELY(x) __builtin_expect(x, 1)
#define za_UNLIKELY(x) __builtin_expect(x, 0)
#else
#define za_LIKELY(x) x
#define za_UNLIKELY(x) x
#endif

// 内存基本单元链表
typedef struct za_binNode {
  void *Ptr;
  struct za_binNode *Next;

} za_binNode;

typedef struct za_bin {
  size_t ChunkSize;
  za_binNode *Head;
  za_binNode *FreeHead;

} za_bin;

// 内存分配器的节点
typedef struct za_allocatorNode {
  void *Data;
  size_t Pos;
  size_t Size;
  struct za_allocatorNode *Next;
} za_allocatorNode;

// 内存分配器
typedef struct za_Allocator {
  za_allocatorNode *Head;
  za_allocatorNode *End;
  za_bin Bins[za_BIN_LEVEL * za_BIN_LEVEL_SIZE];
  size_t LevelMins[za_BIN_LEVEL];
  size_t LevelMaxs[za_BIN_LEVEL];
#ifdef za_ALLOCTOR_DEBUG
  size_t AllocSize;
  size_t FreeSize;
#endif
} za_Allocator;

void *za_innerNew(size_t size);
void za_innerFree(void *pointer);

// 新建一个Allocator
za_Allocator *za_New() {
  // 分配大块内存
  void *ptr = za_innerNew(sizeof(za_Allocator) + sizeof(za_allocatorNode) +
                          za_INIT_SIZE);
  if (za_UNLIKELY(ptr == 0))
    return 0;
  za_Allocator *allocator = (za_Allocator *)ptr;
  allocator->Head = (za_allocatorNode *)((char *)ptr + sizeof(za_Allocator));
  allocator->End = allocator->Head;
#ifdef za_ALLOCTOR_DEBUG
  allocator->AllocSize = 0;
  allocator->FreeSize = 0;
#endif
  memset(allocator->Bins, 0, sizeof(allocator->Bins));
  size_t chunk_size = za_BIN_MIN_CHUNK;
  for (size_t i = 0; i < za_BIN_LEVEL; ++i) {
    allocator->LevelMins[i] = chunk_size;
    for (size_t j = 0; j < za_BIN_LEVEL_SIZE;) {
      za_bin *b = allocator->Bins + i * za_BIN_LEVEL_SIZE + j;
      b->Head = 0;
      b->ChunkSize = chunk_size * (++j);
    }
    allocator->LevelMaxs[i] = chunk_size * za_BIN_LEVEL_SIZE;
    chunk_size = chunk_size * za_BIN_LEVEL_SIZE * 2;
  }

  allocator->Head->Size = za_INIT_SIZE;
  allocator->Head->Data =
      (char *)ptr + sizeof(za_Allocator) + sizeof(za_allocatorNode);
  allocator->Head->Pos = 0;
  allocator->Head->Next = 0;
  return allocator;
}

// 释放一个Allocator
void za_Release(za_Allocator *allocator) {
  // 遍历整个链表，每次释放一块内存
  za_allocatorNode *next = allocator->Head->Next;
  while (za_LIKELY(next != 0)) {
    za_allocatorNode *nn = next->Next;
    za_innerFree((void *)next);
    next = nn;
  }
  // 最后释放第一块内存
  za_innerFree((void *)allocator);
}

za_bin *za_findBin(za_Allocator *allocator, size_t size);
void *za_alloc(za_Allocator *allocator, size_t size);
void za_Free(za_Allocator *allocator, void *ptr);
// 分配内存
void *za_Alloc(za_Allocator *allocator, size_t size) {
  if (za_UNLIKELY(size == 0))
    return 0;
  za_bin *bin = za_findBin(allocator, size);
  size_t *s;
  if (za_UNLIKELY(bin == 0)) {
    s = (size_t *)za_innerNew(sizeof(size_t) + size);
    if (za_UNLIKELY(s == 0))
      return 0;
    *s = size;
#ifdef za_ALLOCTOR_DEBUG
    allocator->AllocSize += size;
#endif
    return (void *)(s + 1);
  }
  if (bin->Head != 0) {
    s = (size_t *)bin->Head->Ptr;
    *s = size;

    za_binNode *bn = bin->Head;
    bin->Head = bin->Head->Next;

    bn->Next = bin->FreeHead;
    bin->FreeHead = bn;
#ifdef za_ALLOCTOR_DEBUG
    allocator->AllocSize += size;
#endif
    return (void *)(s + 1);
  }
  s = (size_t *)za_alloc(allocator, sizeof(size_t) + bin->ChunkSize);
  if (za_UNLIKELY(s == 0))
    return 0;
  *s = size;
#ifdef za_ALLOCTOR_DEBUG
  allocator->AllocSize += size;
#endif
  return (void *)(s + 1);
}
void *za_ReAlloc(za_Allocator *allocator, void *addr, size_t size) {
  void *ret = za_Alloc(allocator, size);
  size_t *addr_size = (size_t *)addr - 1;
  if (za_UNLIKELY(*addr_size > size)) {
    memcpy(ret, addr, size);
  } else {
    memcpy(ret, addr, *addr_size);
  }
  za_Free(allocator, addr);
  return ret;
}

// 释放内存
void za_Free(za_Allocator *allocator, void *ptr) {
  size_t *s = (size_t *)ptr - 1;
  if (za_UNLIKELY(*s == 0))
    return;
#ifdef za_ALLOCTOR_DEBUG
  allocator->FreeSize += *s;
#endif
  za_bin *bin = za_findBin(allocator, *s);
  if (za_UNLIKELY(bin == 0)) {
    za_innerFree(s);
    return;
  }
  *s = 0;
  za_binNode *bn;
  if (bin->FreeHead != 0) {
    bn = bin->FreeHead;
    bin->FreeHead = bin->FreeHead->Next;
  } else {
    bn = (za_binNode *)za_alloc(allocator, sizeof(za_binNode));
    if (za_UNLIKELY(bn == 0)) {
      return;
    }
  }

  bn->Ptr = (void *)s;
  bn->Next = bin->Head;
  bin->Head = bn;
  return;
}
// 找到合适的Bin
za_bin *za_findBin(za_Allocator *allocator, size_t size) {
  for (size_t i = 0; i < za_BIN_LEVEL; ++i) {
    if (za_LIKELY(size <= allocator->LevelMaxs[i])) {
      return allocator->Bins + ((size - 1) / allocator->LevelMins[i]) +
             za_BIN_LEVEL_SIZE * i;
    }
  }
  return 0;
}
// 追加一个Allocator
bool za_appendChild(size_t init_size, struct za_Allocator *allocator) {
  // 每次分配一大块内存，避免多次分配
  void *ptr = za_innerNew(sizeof(za_allocatorNode) + init_size);
  if (za_UNLIKELY(ptr == 0))
    return false;
  za_allocatorNode *node = (za_allocatorNode *)ptr;
  node->Size = init_size;
  node->Data = (char *)ptr + sizeof(za_allocatorNode);
  node->Pos = 0;
  node->Next = 0;
  // 在ANode组成的链表最后加一个ANode
  allocator->End->Next = node;
  allocator->End = node;
  return true;
}

// 分配大小为size的内存
void *za_alloc(za_Allocator *allocator, size_t size) {
  za_allocatorNode *cur_node = allocator->End;
  size_t s = cur_node->Size;
  if (za_UNLIKELY(cur_node->Pos + size > s)) {
    s *= za_Delta;
    // 通过循环计算最终需要的空间大小
    // 这里应该有更好的方法，就是直接通过计算所得
    while (za_UNLIKELY(size > s))
      s *= za_Delta; // 每次分配内存的大小是上次的za_Delta倍
    if (za_UNLIKELY(za_appendChild(s, allocator) == false))
      return 0;
    cur_node = allocator->End;
  }
  void *ret = (char *)(cur_node->Data) + cur_node->Pos;
  cur_node->Pos += size;
  return ret;
}

void *za_innerNew(size_t size) { return malloc(size); }
void za_innerFree(void *pointer) { free(pointer); }

#endif
