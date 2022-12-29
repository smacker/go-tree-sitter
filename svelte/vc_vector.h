#ifndef VC_VECTOR_H
#define VC_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>
#include "allocator.h"

// ------------------ VECTORS ------------------------
#define GROWTH_FACTOR 1.5
#define DEFAULT_COUNT_OF_ELEMENTS 8
#define MINIMUM_COUNT_OF_ELEMENTS 2

// vc_vector structure
typedef void(vc_vector_deleter)(void *, za_Allocator *);

typedef struct vc_vector {
  size_t count;
  size_t element_size;
  size_t reserved_size;
  char *data;
  vc_vector_deleter *deleter;
  za_Allocator *A;
} vc_vector;
// Constructs an empty vector with an reserver size for count_elements.
vc_vector *vc_vector_create(za_Allocator *A, size_t count_elements,
                            size_t size_of_element,
                            vc_vector_deleter *deleter) {
  vc_vector *v = (vc_vector *)za_Alloc(A, sizeof(vc_vector));

  if (count_elements < MINIMUM_COUNT_OF_ELEMENTS) {
    count_elements = DEFAULT_COUNT_OF_ELEMENTS;
  }

  if (v != NULL) {
    v->data = za_Alloc(A, size_of_element * count_elements);
    v->count = 0;
    v->element_size = size_of_element;
    v->deleter = deleter;
    v->A = A;
    v->reserved_size = count_elements * size_of_element;
  }

  return v;
}

void *vc_vector_at(vc_vector *vector, size_t index) {
  return vector->data + index * vector->element_size;
}

size_t vc_vector_count(const vc_vector *vector) { return vector->count; }

// [first_index, last_index)
void vc_vector_call_deleter(vc_vector *vector, size_t first_index,
                            size_t last_index) {
  for (size_t i = first_index; i < last_index; ++i) {
    vector->deleter(vc_vector_at(vector, i), vector->A);
  }
}

// delete all data
void vc_vector_call_deleter_all(vc_vector *vector) {
  vc_vector_call_deleter(vector, 0, vc_vector_count(vector));
}
// clear all data
void vc_vector_clear(vc_vector *vector) {
  if (vector->deleter != NULL) {
    vc_vector_call_deleter_all(vector);
  }

  vector->count = 0;
}

// Returns the last item in the vector.
void *vc_vector_back(vc_vector *vector) {
  return vector->data + (vector->count - 1) * vector->element_size;
}

bool vc_vector_realloc(vc_vector *vector, size_t new_count) {
  const size_t new_size = new_count * vector->element_size;
  char *new_data = (char *)za_ReAlloc(vector->A, vector->data, new_size);
  if (!new_data) {
    return false;
  }

  vector->reserved_size = new_size;
  vector->data = new_data;
  return true;
}

bool vc_vector_resize(vc_vector *vector, size_t new_count, void *defaultValue) {
  // trim or append elements, provide strong guarantee
  const size_t old_count = vector->count;

  if (new_count == old_count)
    return true;

  if (new_count < old_count) { // trim
    for (size_t i = new_count; i < old_count; i++)
      vector->deleter(vc_vector_at(vector, i), vector->A);
    return true;
  }

  // new_count > old_count
  const size_t old_capacity = vector->reserved_size;
  if (new_count > old_capacity) { // reallocate
    vc_vector_realloc(vector, new_count);
  }

  for (size_t i = old_count; i < new_count; i++)
    memcpy(vector->data + i, defaultValue, vector->element_size);

  vector->count = new_count;

  return true;
}

size_t vc_vector_max_count(const vc_vector *vector) {
  return vector->reserved_size / vector->element_size;
}

bool vc_vector_append(vc_vector *vector, const void *values, size_t count) {
  /* #define GROWTH_FACTOR 1.5 */
  const size_t count_new = count + vc_vector_count(vector);

  if (vc_vector_max_count(vector) < count_new) {
    size_t max_count_to_reserved = vc_vector_max_count(vector) * GROWTH_FACTOR;
    while (count_new > max_count_to_reserved) {
      max_count_to_reserved *= GROWTH_FACTOR;
    }

    if (!vc_vector_realloc(vector, max_count_to_reserved)) {
      return false;
    }
  }

  if (memcpy(vector->data + vector->count * vector->element_size, values,
             vector->element_size * count) == NULL) {
    return false;
  }

  vector->count = count_new;
  return true;
}

bool vc_vector_push_back(vc_vector *vector, const void *value) {
  if (!vc_vector_append(vector, value, 1)) {
    return false;
  }
  return true;
}

bool vc_vector_pop_back(vc_vector *vector) {
  if (vector->deleter != NULL) {
    vector->deleter(vc_vector_back(vector), vector->A);
  }

  vector->count--;
  return true;
}
// ----------------------------------------------------------


#endif
