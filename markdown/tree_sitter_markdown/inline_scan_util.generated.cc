#include "./inline_scan_util.generated.h"

namespace tree_sitter_markdown {

void adv_inl_ent_ref_nam(Lexer &lxr, LexedLength &ent_ref_len) {
  if (lxr.adv_if('A')) {
    if (lxr.adv_if('E')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*AElig*/
          }
        }
      }
    }
    else if (lxr.adv_if('M')) {
      if (lxr.adv_if('P')) {
        ent_ref_len = 3; /*AMP*/
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Aacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Abreve*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Acirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Acy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Afr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Agrave*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('h')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*Alpha*/
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*Amacr*/
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('d')) {
        ent_ref_len = 3; /*And*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*Aogon*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Aopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('y')) {
            if (lxr.adv_if('F')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('c')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('n')) {
                            ent_ref_len = 13; /*ApplyFunction*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*Aring*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Ascr*/
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Assign*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Atilde*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*Auml*/
        }
      }
    }
  }
  else if (lxr.adv_if('B')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('k')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('s')) {
                  if (lxr.adv_if('h')) {
                    ent_ref_len = 9; /*Backslash*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('v')) {
          ent_ref_len = 4; /*Barv*/
        }
        else if (lxr.adv_if('w')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*Barwed*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Bcy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*Because*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('s')) {
                      ent_ref_len = 10; /*Bernoullis*/
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*Beta*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Bfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Bopf*/
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('v')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*Breve*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Bscr*/
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('q')) {
              ent_ref_len = 6; /*Bumpeq*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('C')) {
    if (lxr.adv_if('H')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*CHcy*/
        }
      }
    }
    else if (lxr.adv_if('O')) {
      if (lxr.adv_if('P')) {
        if (lxr.adv_if('Y')) {
          ent_ref_len = 4; /*COPY*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Cacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*Cap*/
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('D')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('f')) {
                      if (lxr.adv_if('f')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('e')) {
                              if (lxr.adv_if('n')) {
                                if (lxr.adv_if('t')) {
                                  if (lxr.adv_if('i')) {
                                    if (lxr.adv_if('a')) {
                                      if (lxr.adv_if('l')) {
                                        if (lxr.adv_if('D')) {
                                          ent_ref_len = 20; /*CapitalDifferentialD*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('y')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*Cayleys*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Ccaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Ccedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Ccirc*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*Cconint*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*Cdot*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('a')) {
                ent_ref_len = 7; /*Cedilla*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('D')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*CenterDot*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Cfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('i')) {
        ent_ref_len = 3; /*Chi*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('D')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*CircleDot*/
                  }
                }
              }
              else if (lxr.adv_if('M')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('u')) {
                      if (lxr.adv_if('s')) {
                        ent_ref_len = 11; /*CircleMinus*/
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('P')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('u')) {
                    if (lxr.adv_if('s')) {
                      ent_ref_len = 10; /*CirclePlus*/
                    }
                  }
                }
              }
              else if (lxr.adv_if('T')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('m')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('s')) {
                        ent_ref_len = 11; /*CircleTimes*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('k')) {
            if (lxr.adv_if('w')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('s')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('C')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('n')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('u')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('I')) {
                                    if (lxr.adv_if('n')) {
                                      if (lxr.adv_if('t')) {
                                        if (lxr.adv_if('e')) {
                                          if (lxr.adv_if('g')) {
                                            if (lxr.adv_if('r')) {
                                              if (lxr.adv_if('a')) {
                                                if (lxr.adv_if('l')) {
                                                  ent_ref_len = 24; /*ClockwiseContourIntegral*/
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('C')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('y')) {
                      if (lxr.adv_if('D')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('u')) {
                            if (lxr.adv_if('b')) {
                              if (lxr.adv_if('l')) {
                                if (lxr.adv_if('e')) {
                                  if (lxr.adv_if('Q')) {
                                    if (lxr.adv_if('u')) {
                                      if (lxr.adv_if('o')) {
                                        if (lxr.adv_if('t')) {
                                          if (lxr.adv_if('e')) {
                                            ent_ref_len = 21; /*CloseCurlyDoubleQuote*/
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('Q')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('t')) {
                              if (lxr.adv_if('e')) {
                                ent_ref_len = 15; /*CloseCurlyQuote*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*Colon*/
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Colone*/
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*Congruent*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*Conint*/
            }
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('I')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('g')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('l')) {
                                ent_ref_len = 15; /*ContourIntegral*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Copf*/
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('d')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('c')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*Coproduct*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('C')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('c')) {
                        if (lxr.adv_if('k')) {
                          if (lxr.adv_if('w')) {
                            if (lxr.adv_if('i')) {
                              if (lxr.adv_if('s')) {
                                if (lxr.adv_if('e')) {
                                  if (lxr.adv_if('C')) {
                                    if (lxr.adv_if('o')) {
                                      if (lxr.adv_if('n')) {
                                        if (lxr.adv_if('t')) {
                                          if (lxr.adv_if('o')) {
                                            if (lxr.adv_if('u')) {
                                              if (lxr.adv_if('r')) {
                                                if (lxr.adv_if('I')) {
                                                  if (lxr.adv_if('n')) {
                                                    if (lxr.adv_if('t')) {
                                                      if (lxr.adv_if('e')) {
                                                        if (lxr.adv_if('g')) {
                                                          if (lxr.adv_if('r')) {
                                                            if (lxr.adv_if('a')) {
                                                              if (lxr.adv_if('l')) {
                                                                ent_ref_len = 31; /*CounterClockwiseContourIntegral*/
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*Cross*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Cscr*/
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*Cup*/
        if (lxr.adv_if('C')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*CupCap*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('D')) {
    if (lxr.adv_if('D')) {
      ent_ref_len = 2; /*DD*/
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('h')) {
                if (lxr.adv_if('d')) {
                  ent_ref_len = 8; /*DDotrahd*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('J')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*DJcy*/
        }
      }
    }
    else if (lxr.adv_if('S')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*DScy*/
        }
      }
    }
    else if (lxr.adv_if('Z')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*DZcy*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*Dagger*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Darr*/
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('h')) {
          if (lxr.adv_if('v')) {
            ent_ref_len = 5; /*Dashv*/
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Dcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Dcy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('l')) {
        ent_ref_len = 3; /*Del*/
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*Delta*/
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Dfr*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('c')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('A')) {
                          if (lxr.adv_if('c')) {
                            if (lxr.adv_if('u')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('e')) {
                                  ent_ref_len = 16; /*DiacriticalAcute*/
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('D')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('t')) {
                              ent_ref_len = 14; /*DiacriticalDot*/
                            }
                            else if (lxr.adv_if('u')) {
                              if (lxr.adv_if('b')) {
                                if (lxr.adv_if('l')) {
                                  if (lxr.adv_if('e')) {
                                    if (lxr.adv_if('A')) {
                                      if (lxr.adv_if('c')) {
                                        if (lxr.adv_if('u')) {
                                          if (lxr.adv_if('t')) {
                                            if (lxr.adv_if('e')) {
                                              ent_ref_len = 22; /*DiacriticalDoubleAcute*/
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('G')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('v')) {
                                if (lxr.adv_if('e')) {
                                  ent_ref_len = 16; /*DiacriticalGrave*/
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('T')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('d')) {
                                if (lxr.adv_if('e')) {
                                  ent_ref_len = 16; /*DiacriticalTilde*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('d')) {
                ent_ref_len = 7; /*Diamond*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('f')) {
        if (lxr.adv_if('f')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('D')) {
                            ent_ref_len = 13; /*DifferentialD*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Dopf*/
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*Dot*/
        if (lxr.adv_if('D')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*DotDot*/
            }
          }
        }
        else if (lxr.adv_if('E')) {
          if (lxr.adv_if('q')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('l')) {
                  ent_ref_len = 8; /*DotEqual*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('C')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('I')) {
                              if (lxr.adv_if('n')) {
                                if (lxr.adv_if('t')) {
                                  if (lxr.adv_if('e')) {
                                    if (lxr.adv_if('g')) {
                                      if (lxr.adv_if('r')) {
                                        if (lxr.adv_if('a')) {
                                          if (lxr.adv_if('l')) {
                                            ent_ref_len = 21; /*DoubleContourIntegral*/
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('D')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*DoubleDot*/
                  }
                  else if (lxr.adv_if('w')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('A')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                ent_ref_len = 15; /*DoubleDownArrow*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('L')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('f')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('A')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                ent_ref_len = 15; /*DoubleLeftArrow*/
                              }
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('R')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('g')) {
                            if (lxr.adv_if('h')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('A')) {
                                  if (lxr.adv_if('r')) {
                                    if (lxr.adv_if('r')) {
                                      if (lxr.adv_if('o')) {
                                        if (lxr.adv_if('w')) {
                                          ent_ref_len = 20; /*DoubleLeftRightArrow*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('T')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*DoubleLeftTee*/
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('o')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('g')) {
                      if (lxr.adv_if('L')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('f')) {
                            if (lxr.adv_if('t')) {
                              if (lxr.adv_if('A')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('r')) {
                                    if (lxr.adv_if('o')) {
                                      if (lxr.adv_if('w')) {
                                        ent_ref_len = 19; /*DoubleLongLeftArrow*/
                                      }
                                    }
                                  }
                                }
                              }
                              else if (lxr.adv_if('R')) {
                                if (lxr.adv_if('i')) {
                                  if (lxr.adv_if('g')) {
                                    if (lxr.adv_if('h')) {
                                      if (lxr.adv_if('t')) {
                                        if (lxr.adv_if('A')) {
                                          if (lxr.adv_if('r')) {
                                            if (lxr.adv_if('r')) {
                                              if (lxr.adv_if('o')) {
                                                if (lxr.adv_if('w')) {
                                                  ent_ref_len = 24; /*DoubleLongLeftRightArrow*/
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('R')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('g')) {
                            if (lxr.adv_if('h')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('A')) {
                                  if (lxr.adv_if('r')) {
                                    if (lxr.adv_if('r')) {
                                      if (lxr.adv_if('o')) {
                                        if (lxr.adv_if('w')) {
                                          ent_ref_len = 20; /*DoubleLongRightArrow*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('R')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('g')) {
                    if (lxr.adv_if('h')) {
                      if (lxr.adv_if('t')) {
                        if (lxr.adv_if('A')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('r')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('w')) {
                                  ent_ref_len = 16; /*DoubleRightArrow*/
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('T')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('e')) {
                              ent_ref_len = 14; /*DoubleRightTee*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('U')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('A')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('w')) {
                            ent_ref_len = 13; /*DoubleUpArrow*/
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('D')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        if (lxr.adv_if('n')) {
                          if (lxr.adv_if('A')) {
                            if (lxr.adv_if('r')) {
                              if (lxr.adv_if('r')) {
                                if (lxr.adv_if('o')) {
                                  if (lxr.adv_if('w')) {
                                    ent_ref_len = 17; /*DoubleUpDownArrow*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('V')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('c')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('B')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('r')) {
                                    ent_ref_len = 17; /*DoubleVerticalBar*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('w')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('A')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    ent_ref_len = 9; /*DownArrow*/
                    if (lxr.adv_if('B')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('r')) {
                          ent_ref_len = 12; /*DownArrowBar*/
                        }
                      }
                    }
                    else if (lxr.adv_if('U')) {
                      if (lxr.adv_if('p')) {
                        if (lxr.adv_if('A')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('r')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('w')) {
                                  ent_ref_len = 16; /*DownArrowUpArrow*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('B')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('v')) {
                  if (lxr.adv_if('e')) {
                    ent_ref_len = 9; /*DownBreve*/
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('L')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('f')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('R')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('h')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('V')) {
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('c')) {
                                  if (lxr.adv_if('t')) {
                                    if (lxr.adv_if('o')) {
                                      if (lxr.adv_if('r')) {
                                        ent_ref_len = 19; /*DownLeftRightVector*/
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('T')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('V')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('c')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('o')) {
                                  if (lxr.adv_if('r')) {
                                    ent_ref_len = 17; /*DownLeftTeeVector*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('V')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('c')) {
                        if (lxr.adv_if('t')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('r')) {
                              ent_ref_len = 14; /*DownLeftVector*/
                              if (lxr.adv_if('B')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('r')) {
                                    ent_ref_len = 17; /*DownLeftVectorBar*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('R')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('h')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('T')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('V')) {
                            if (lxr.adv_if('e')) {
                              if (lxr.adv_if('c')) {
                                if (lxr.adv_if('t')) {
                                  if (lxr.adv_if('o')) {
                                    if (lxr.adv_if('r')) {
                                      ent_ref_len = 18; /*DownRightTeeVector*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('V')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('c')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('r')) {
                                ent_ref_len = 15; /*DownRightVector*/
                                if (lxr.adv_if('B')) {
                                  if (lxr.adv_if('a')) {
                                    if (lxr.adv_if('r')) {
                                      ent_ref_len = 18; /*DownRightVectorBar*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('T')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*DownTee*/
                if (lxr.adv_if('A')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('w')) {
                          ent_ref_len = 12; /*DownTeeArrow*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    ent_ref_len = 9; /*Downarrow*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Dscr*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*Dstrok*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('E')) {
    if (lxr.adv_if('N')) {
      if (lxr.adv_if('G')) {
        ent_ref_len = 3; /*ENG*/
      }
    }
    else if (lxr.adv_if('T')) {
      if (lxr.adv_if('H')) {
        ent_ref_len = 3; /*ETH*/
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Eacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Ecaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Ecirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Ecy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*Edot*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Efr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Egrave*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*Element*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*Emacr*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('y')) {
            if (lxr.adv_if('S')) {
              if (lxr.adv_if('m')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('S')) {
                        if (lxr.adv_if('q')) {
                          if (lxr.adv_if('u')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('r')) {
                                if (lxr.adv_if('e')) {
                                  ent_ref_len = 16; /*EmptySmallSquare*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('V')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('y')) {
                    if (lxr.adv_if('S')) {
                      if (lxr.adv_if('m')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('l')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('S')) {
                                if (lxr.adv_if('q')) {
                                  if (lxr.adv_if('u')) {
                                    if (lxr.adv_if('a')) {
                                      if (lxr.adv_if('r')) {
                                        if (lxr.adv_if('e')) {
                                          ent_ref_len = 20; /*EmptyVerySmallSquare*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*Eogon*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Eopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*Epsilon*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('q')) {
      if (lxr.adv_if('u')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*Equal*/
            if (lxr.adv_if('T')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('d')) {
                    if (lxr.adv_if('e')) {
                      ent_ref_len = 10; /*EqualTilde*/
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('b')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('u')) {
                      if (lxr.adv_if('m')) {
                        ent_ref_len = 11; /*Equilibrium*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Escr*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          ent_ref_len = 4; /*Esim*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('a')) {
        ent_ref_len = 3; /*Eta*/
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*Euml*/
        }
      }
    }
    else if (lxr.adv_if('x')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*Exists*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('E')) {
                          ent_ref_len = 12; /*ExponentialE*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('F')) {
    if (lxr.adv_if('c')) {
      if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Fcy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Ffr*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('d')) {
              if (lxr.adv_if('S')) {
                if (lxr.adv_if('m')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('S')) {
                          if (lxr.adv_if('q')) {
                            if (lxr.adv_if('u')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('e')) {
                                    ent_ref_len = 17; /*FilledSmallSquare*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('V')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('y')) {
                      if (lxr.adv_if('S')) {
                        if (lxr.adv_if('m')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('l')) {
                                if (lxr.adv_if('S')) {
                                  if (lxr.adv_if('q')) {
                                    if (lxr.adv_if('u')) {
                                      if (lxr.adv_if('a')) {
                                        if (lxr.adv_if('r')) {
                                          if (lxr.adv_if('e')) {
                                            ent_ref_len = 21; /*FilledVerySmallSquare*/
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Fopf*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('A')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*ForAll*/
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('f')) {
                      ent_ref_len = 10; /*Fouriertrf*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Fscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('G')) {
    if (lxr.adv_if('J')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*GJcy*/
        }
      }
    }
    else if (lxr.adv_if('T')) {
      ent_ref_len = 2; /*GT*/
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*Gamma*/
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*Gammad*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Gbreve*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Gcedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Gcirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Gcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*Gdot*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Gfr*/
      }
    }
    else if (lxr.adv_if('g')) {
      ent_ref_len = 2; /*Gg*/
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Gopf*/
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('E')) {
                  if (lxr.adv_if('q')) {
                    if (lxr.adv_if('u')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('l')) {
                          ent_ref_len = 12; /*GreaterEqual*/
                          if (lxr.adv_if('L')) {
                            if (lxr.adv_if('e')) {
                              if (lxr.adv_if('s')) {
                                if (lxr.adv_if('s')) {
                                  ent_ref_len = 16; /*GreaterEqualLess*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('F')) {
                  if (lxr.adv_if('u')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('E')) {
                          if (lxr.adv_if('q')) {
                            if (lxr.adv_if('u')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('l')) {
                                  ent_ref_len = 16; /*GreaterFullEqual*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('G')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('t')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('r')) {
                              ent_ref_len = 14; /*GreaterGreater*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('L')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('s')) {
                      if (lxr.adv_if('s')) {
                        ent_ref_len = 11; /*GreaterLess*/
                      }
                    }
                  }
                }
                else if (lxr.adv_if('S')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('t')) {
                          if (lxr.adv_if('E')) {
                            if (lxr.adv_if('q')) {
                              if (lxr.adv_if('u')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('l')) {
                                    ent_ref_len = 17; /*GreaterSlantEqual*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('T')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('d')) {
                        if (lxr.adv_if('e')) {
                          ent_ref_len = 12; /*GreaterTilde*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Gscr*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      ent_ref_len = 2; /*Gt*/
    }
  }
  else if (lxr.adv_if('H')) {
    if (lxr.adv_if('A')) {
      if (lxr.adv_if('R')) {
        if (lxr.adv_if('D')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*HARDcy*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*Hacek*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*Hat*/
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Hcirc*/
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Hfr*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('S')) {
                  if (lxr.adv_if('p')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('c')) {
                        if (lxr.adv_if('e')) {
                          ent_ref_len = 12; /*HilbertSpace*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Hopf*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('z')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('L')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('n')) {
                            if (lxr.adv_if('e')) {
                              ent_ref_len = 14; /*HorizontalLine*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Hscr*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*Hstrok*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('D')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('H')) {
                    if (lxr.adv_if('u')) {
                      if (lxr.adv_if('m')) {
                        if (lxr.adv_if('p')) {
                          ent_ref_len = 12; /*HumpDownHump*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('E')) {
            if (lxr.adv_if('q')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('l')) {
                    ent_ref_len = 9; /*HumpEqual*/
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('I')) {
    if (lxr.adv_if('E')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*IEcy*/
        }
      }
    }
    else if (lxr.adv_if('J')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*IJlig*/
          }
        }
      }
    }
    else if (lxr.adv_if('O')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*IOcy*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Iacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Icirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Icy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*Idot*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Ifr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Igrave*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      ent_ref_len = 2; /*Im*/
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*Imacr*/
          }
        }
        else if (lxr.adv_if('g')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('y')) {
                    if (lxr.adv_if('I')) {
                      ent_ref_len = 10; /*ImaginaryI*/
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*Implies*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*Int*/
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('g')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('l')) {
                  ent_ref_len = 8; /*Integral*/
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('c')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('n')) {
                          ent_ref_len = 12; /*Intersection*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('v')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('b')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('C')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('m')) {
                          if (lxr.adv_if('m')) {
                            if (lxr.adv_if('a')) {
                              ent_ref_len = 14; /*InvisibleComma*/
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('T')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('m')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('s')) {
                              ent_ref_len = 14; /*InvisibleTimes*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*Iogon*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Iopf*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*Iota*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Iscr*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Itilde*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('k')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*Iukcy*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*Iuml*/
        }
      }
    }
  }
  else if (lxr.adv_if('J')) {
    if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Jcirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Jcy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Jfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Jopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Jscr*/
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*Jsercy*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('k')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*Jukcy*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('K')) {
    if (lxr.adv_if('H')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*KHcy*/
        }
      }
    }
    else if (lxr.adv_if('J')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*KJcy*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*Kappa*/
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Kcedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Kcy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Kfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Kopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Kscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('L')) {
    if (lxr.adv_if('J')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*LJcy*/
        }
      }
    }
    else if (lxr.adv_if('T')) {
      ent_ref_len = 2; /*LT*/
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Lacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('a')) {
              ent_ref_len = 6; /*Lambda*/
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*Lang*/
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('f')) {
                      ent_ref_len = 10; /*Laplacetrf*/
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Larr*/
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Lcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Lcedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Lcy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('f')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('A')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('B')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('c')) {
                            if (lxr.adv_if('k')) {
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('t')) {
                                  ent_ref_len = 16; /*LeftAngleBracket*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    ent_ref_len = 9; /*LeftArrow*/
                    if (lxr.adv_if('B')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('r')) {
                          ent_ref_len = 12; /*LeftArrowBar*/
                        }
                      }
                    }
                    else if (lxr.adv_if('R')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('g')) {
                          if (lxr.adv_if('h')) {
                            if (lxr.adv_if('t')) {
                              if (lxr.adv_if('A')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('r')) {
                                    if (lxr.adv_if('o')) {
                                      if (lxr.adv_if('w')) {
                                        ent_ref_len = 19; /*LeftArrowRightArrow*/
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('C')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('g')) {
                        ent_ref_len = 11; /*LeftCeiling*/
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('D')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('b')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('B')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('c')) {
                              if (lxr.adv_if('k')) {
                                if (lxr.adv_if('e')) {
                                  if (lxr.adv_if('t')) {
                                    ent_ref_len = 17; /*LeftDoubleBracket*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('w')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('T')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('V')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('c')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('o')) {
                                  if (lxr.adv_if('r')) {
                                    ent_ref_len = 17; /*LeftDownTeeVector*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('V')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('c')) {
                        if (lxr.adv_if('t')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('r')) {
                              ent_ref_len = 14; /*LeftDownVector*/
                              if (lxr.adv_if('B')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('r')) {
                                    ent_ref_len = 17; /*LeftDownVectorBar*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('F')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('r')) {
                    ent_ref_len = 9; /*LeftFloor*/
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('R')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('h')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('A')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*LeftRightArrow*/
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('V')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('c')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('r')) {
                                ent_ref_len = 15; /*LeftRightVector*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('T')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*LeftTee*/
                if (lxr.adv_if('A')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('w')) {
                          ent_ref_len = 12; /*LeftTeeArrow*/
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('V')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('c')) {
                      if (lxr.adv_if('t')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('r')) {
                            ent_ref_len = 13; /*LeftTeeVector*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('r')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('g')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('e')) {
                          ent_ref_len = 12; /*LeftTriangle*/
                          if (lxr.adv_if('B')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('r')) {
                                ent_ref_len = 15; /*LeftTriangleBar*/
                              }
                            }
                          }
                          else if (lxr.adv_if('E')) {
                            if (lxr.adv_if('q')) {
                              if (lxr.adv_if('u')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('l')) {
                                    ent_ref_len = 17; /*LeftTriangleEqual*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('U')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('D')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('V')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('c')) {
                            if (lxr.adv_if('t')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('r')) {
                                  ent_ref_len = 16; /*LeftUpDownVector*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('T')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('V')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('c')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('r')) {
                                ent_ref_len = 15; /*LeftUpTeeVector*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('V')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('c')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('r')) {
                          ent_ref_len = 12; /*LeftUpVector*/
                          if (lxr.adv_if('B')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('r')) {
                                ent_ref_len = 15; /*LeftUpVectorBar*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('V')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('c')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('r')) {
                      ent_ref_len = 10; /*LeftVector*/
                      if (lxr.adv_if('B')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('r')) {
                            ent_ref_len = 13; /*LeftVectorBar*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    ent_ref_len = 9; /*Leftarrow*/
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('h')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*Leftrightarrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('E')) {
            if (lxr.adv_if('q')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('G')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('t')) {
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('r')) {
                                  ent_ref_len = 16; /*LessEqualGreater*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('F')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('E')) {
                    if (lxr.adv_if('q')) {
                      if (lxr.adv_if('u')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('l')) {
                            ent_ref_len = 13; /*LessFullEqual*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('G')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('r')) {
                        ent_ref_len = 11; /*LessGreater*/
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('L')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('s')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*LessLess*/
                }
              }
            }
          }
          else if (lxr.adv_if('S')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('E')) {
                      if (lxr.adv_if('q')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('l')) {
                              ent_ref_len = 14; /*LessSlantEqual*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('T')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('d')) {
                  if (lxr.adv_if('e')) {
                    ent_ref_len = 9; /*LessTilde*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Lfr*/
      }
    }
    else if (lxr.adv_if('l')) {
      ent_ref_len = 2; /*Ll*/
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('f')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      ent_ref_len = 10; /*Lleftarrow*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*Lmidot*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('L')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('f')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('A')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('w')) {
                            ent_ref_len = 13; /*LongLeftArrow*/
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('R')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('h')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('A')) {
                              if (lxr.adv_if('r')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('o')) {
                                    if (lxr.adv_if('w')) {
                                      ent_ref_len = 18; /*LongLeftRightArrow*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('R')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('h')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('A')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*LongRightArrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('f')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('w')) {
                            ent_ref_len = 13; /*Longleftarrow*/
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('r')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('h')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('r')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('o')) {
                                    if (lxr.adv_if('w')) {
                                      ent_ref_len = 18; /*Longleftrightarrow*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('h')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*Longrightarrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Lopf*/
        }
      }
      else if (lxr.adv_if('w')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('L')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('f')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('A')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*LowerLeftArrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('R')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('A')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                ent_ref_len = 15; /*LowerRightArrow*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Lscr*/
        }
      }
      else if (lxr.adv_if('h')) {
        ent_ref_len = 3; /*Lsh*/
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*Lstrok*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      ent_ref_len = 2; /*Lt*/
    }
  }
  else if (lxr.adv_if('M')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*Map*/
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Mcy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('m')) {
              if (lxr.adv_if('S')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('c')) {
                      if (lxr.adv_if('e')) {
                        ent_ref_len = 11; /*MediumSpace*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('f')) {
                    ent_ref_len = 9; /*Mellintrf*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Mfr*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('n')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('P')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('u')) {
                  if (lxr.adv_if('s')) {
                    ent_ref_len = 9; /*MinusPlus*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Mopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Mscr*/
        }
      }
    }
    else if (lxr.adv_if('u')) {
      ent_ref_len = 2; /*Mu*/
    }
  }
  else if (lxr.adv_if('N')) {
    if (lxr.adv_if('J')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*NJcy*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Nacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Ncaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Ncedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Ncy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('v')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('M')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('d')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('u')) {
                            if (lxr.adv_if('m')) {
                              if (lxr.adv_if('S')) {
                                if (lxr.adv_if('p')) {
                                  if (lxr.adv_if('a')) {
                                    if (lxr.adv_if('c')) {
                                      if (lxr.adv_if('e')) {
                                        ent_ref_len = 19; /*NegativeMediumSpace*/
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('T')) {
                    if (lxr.adv_if('h')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('c')) {
                          if (lxr.adv_if('k')) {
                            if (lxr.adv_if('S')) {
                              if (lxr.adv_if('p')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('c')) {
                                    if (lxr.adv_if('e')) {
                                      ent_ref_len = 18; /*NegativeThickSpace*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('n')) {
                          if (lxr.adv_if('S')) {
                            if (lxr.adv_if('p')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('c')) {
                                  if (lxr.adv_if('e')) {
                                    ent_ref_len = 17; /*NegativeThinSpace*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('V')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('y')) {
                          if (lxr.adv_if('T')) {
                            if (lxr.adv_if('h')) {
                              if (lxr.adv_if('i')) {
                                if (lxr.adv_if('n')) {
                                  if (lxr.adv_if('S')) {
                                    if (lxr.adv_if('p')) {
                                      if (lxr.adv_if('a')) {
                                        if (lxr.adv_if('c')) {
                                          if (lxr.adv_if('e')) {
                                            ent_ref_len = 21; /*NegativeVeryThinSpace*/
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('d')) {
              if (lxr.adv_if('G')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('t')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('G')) {
                              if (lxr.adv_if('r')) {
                                if (lxr.adv_if('e')) {
                                  if (lxr.adv_if('a')) {
                                    if (lxr.adv_if('t')) {
                                      if (lxr.adv_if('e')) {
                                        if (lxr.adv_if('r')) {
                                          ent_ref_len = 20; /*NestedGreaterGreater*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('L')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('s')) {
                    if (lxr.adv_if('s')) {
                      if (lxr.adv_if('L')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('s')) {
                            if (lxr.adv_if('s')) {
                              ent_ref_len = 14; /*NestedLessLess*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('w')) {
        if (lxr.adv_if('L')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*NewLine*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Nfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('B')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('k')) {
                ent_ref_len = 7; /*NoBreak*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('B')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('k')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('S')) {
                          if (lxr.adv_if('p')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('c')) {
                                if (lxr.adv_if('e')) {
                                  ent_ref_len = 16; /*NonBreakingSpace*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Nopf*/
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*Not*/
        if (lxr.adv_if('C')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('u')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('t')) {
                          ent_ref_len = 12; /*NotCongruent*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('u')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('C')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('p')) {
                    ent_ref_len = 9; /*NotCupCap*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('D')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('b')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('V')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('i')) {
                              if (lxr.adv_if('c')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('l')) {
                                    if (lxr.adv_if('B')) {
                                      if (lxr.adv_if('a')) {
                                        if (lxr.adv_if('r')) {
                                          ent_ref_len = 20; /*NotDoubleVerticalBar*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('E')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('m')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('t')) {
                      ent_ref_len = 10; /*NotElement*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('q')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('l')) {
                  ent_ref_len = 8; /*NotEqual*/
                  if (lxr.adv_if('T')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('d')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*NotEqualTilde*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('x')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('s')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('s')) {
                    ent_ref_len = 9; /*NotExists*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('G')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('r')) {
                      ent_ref_len = 10; /*NotGreater*/
                      if (lxr.adv_if('E')) {
                        if (lxr.adv_if('q')) {
                          if (lxr.adv_if('u')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('l')) {
                                ent_ref_len = 15; /*NotGreaterEqual*/
                              }
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('F')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('l')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('E')) {
                                if (lxr.adv_if('q')) {
                                  if (lxr.adv_if('u')) {
                                    if (lxr.adv_if('a')) {
                                      if (lxr.adv_if('l')) {
                                        ent_ref_len = 19; /*NotGreaterFullEqual*/
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('G')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('e')) {
                                  if (lxr.adv_if('r')) {
                                    ent_ref_len = 17; /*NotGreaterGreater*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('L')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('s')) {
                            if (lxr.adv_if('s')) {
                              ent_ref_len = 14; /*NotGreaterLess*/
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('S')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('n')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('E')) {
                                  if (lxr.adv_if('q')) {
                                    if (lxr.adv_if('u')) {
                                      if (lxr.adv_if('a')) {
                                        if (lxr.adv_if('l')) {
                                          ent_ref_len = 20; /*NotGreaterSlantEqual*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('T')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('l')) {
                            if (lxr.adv_if('d')) {
                              if (lxr.adv_if('e')) {
                                ent_ref_len = 15; /*NotGreaterTilde*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('H')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('m')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('D')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('H')) {
                          if (lxr.adv_if('u')) {
                            if (lxr.adv_if('m')) {
                              if (lxr.adv_if('p')) {
                                ent_ref_len = 15; /*NotHumpDownHump*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('E')) {
                  if (lxr.adv_if('q')) {
                    if (lxr.adv_if('u')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('l')) {
                          ent_ref_len = 12; /*NotHumpEqual*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('L')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('f')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('T')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('n')) {
                          if (lxr.adv_if('g')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('e')) {
                                ent_ref_len = 15; /*NotLeftTriangle*/
                                if (lxr.adv_if('B')) {
                                  if (lxr.adv_if('a')) {
                                    if (lxr.adv_if('r')) {
                                      ent_ref_len = 18; /*NotLeftTriangleBar*/
                                    }
                                  }
                                }
                                else if (lxr.adv_if('E')) {
                                  if (lxr.adv_if('q')) {
                                    if (lxr.adv_if('u')) {
                                      if (lxr.adv_if('a')) {
                                        if (lxr.adv_if('l')) {
                                          ent_ref_len = 20; /*NotLeftTriangleEqual*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('s')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*NotLess*/
                if (lxr.adv_if('E')) {
                  if (lxr.adv_if('q')) {
                    if (lxr.adv_if('u')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('l')) {
                          ent_ref_len = 12; /*NotLessEqual*/
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('G')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('t')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('r')) {
                              ent_ref_len = 14; /*NotLessGreater*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('L')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('s')) {
                      if (lxr.adv_if('s')) {
                        ent_ref_len = 11; /*NotLessLess*/
                      }
                    }
                  }
                }
                else if (lxr.adv_if('S')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('t')) {
                          if (lxr.adv_if('E')) {
                            if (lxr.adv_if('q')) {
                              if (lxr.adv_if('u')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('l')) {
                                    ent_ref_len = 17; /*NotLessSlantEqual*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('T')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('d')) {
                        if (lxr.adv_if('e')) {
                          ent_ref_len = 12; /*NotLessTilde*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('N')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('d')) {
                    if (lxr.adv_if('G')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('t')) {
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('G')) {
                                    if (lxr.adv_if('r')) {
                                      if (lxr.adv_if('e')) {
                                        if (lxr.adv_if('a')) {
                                          if (lxr.adv_if('t')) {
                                            if (lxr.adv_if('e')) {
                                              if (lxr.adv_if('r')) {
                                                ent_ref_len = 23; /*NotNestedGreaterGreater*/
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('L')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('s')) {
                          if (lxr.adv_if('s')) {
                            if (lxr.adv_if('L')) {
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('s')) {
                                  if (lxr.adv_if('s')) {
                                    ent_ref_len = 17; /*NotNestedLessLess*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('P')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('c')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('d')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('s')) {
                        ent_ref_len = 11; /*NotPrecedes*/
                        if (lxr.adv_if('E')) {
                          if (lxr.adv_if('q')) {
                            if (lxr.adv_if('u')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('l')) {
                                  ent_ref_len = 16; /*NotPrecedesEqual*/
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('S')) {
                          if (lxr.adv_if('l')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('n')) {
                                if (lxr.adv_if('t')) {
                                  if (lxr.adv_if('E')) {
                                    if (lxr.adv_if('q')) {
                                      if (lxr.adv_if('u')) {
                                        if (lxr.adv_if('a')) {
                                          if (lxr.adv_if('l')) {
                                            ent_ref_len = 21; /*NotPrecedesSlantEqual*/
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('R')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('v')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('s')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('E')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('m')) {
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('n')) {
                                  if (lxr.adv_if('t')) {
                                    ent_ref_len = 17; /*NotReverseElement*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('i')) {
            if (lxr.adv_if('g')) {
              if (lxr.adv_if('h')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('T')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('n')) {
                            if (lxr.adv_if('g')) {
                              if (lxr.adv_if('l')) {
                                if (lxr.adv_if('e')) {
                                  ent_ref_len = 16; /*NotRightTriangle*/
                                  if (lxr.adv_if('B')) {
                                    if (lxr.adv_if('a')) {
                                      if (lxr.adv_if('r')) {
                                        ent_ref_len = 19; /*NotRightTriangleBar*/
                                      }
                                    }
                                  }
                                  else if (lxr.adv_if('E')) {
                                    if (lxr.adv_if('q')) {
                                      if (lxr.adv_if('u')) {
                                        if (lxr.adv_if('a')) {
                                          if (lxr.adv_if('l')) {
                                            ent_ref_len = 21; /*NotRightTriangleEqual*/
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('S')) {
          if (lxr.adv_if('q')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('S')) {
                      if (lxr.adv_if('u')) {
                        if (lxr.adv_if('b')) {
                          if (lxr.adv_if('s')) {
                            if (lxr.adv_if('e')) {
                              if (lxr.adv_if('t')) {
                                ent_ref_len = 15; /*NotSquareSubset*/
                                if (lxr.adv_if('E')) {
                                  if (lxr.adv_if('q')) {
                                    if (lxr.adv_if('u')) {
                                      if (lxr.adv_if('a')) {
                                        if (lxr.adv_if('l')) {
                                          ent_ref_len = 20; /*NotSquareSubsetEqual*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('p')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('r')) {
                              if (lxr.adv_if('s')) {
                                if (lxr.adv_if('e')) {
                                  if (lxr.adv_if('t')) {
                                    ent_ref_len = 17; /*NotSquareSuperset*/
                                    if (lxr.adv_if('E')) {
                                      if (lxr.adv_if('q')) {
                                        if (lxr.adv_if('u')) {
                                          if (lxr.adv_if('a')) {
                                            if (lxr.adv_if('l')) {
                                              ent_ref_len = 22; /*NotSquareSupersetEqual*/
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('u')) {
            if (lxr.adv_if('b')) {
              if (lxr.adv_if('s')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*NotSubset*/
                    if (lxr.adv_if('E')) {
                      if (lxr.adv_if('q')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('l')) {
                              ent_ref_len = 14; /*NotSubsetEqual*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('c')) {
              if (lxr.adv_if('c')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('d')) {
                      if (lxr.adv_if('s')) {
                        ent_ref_len = 11; /*NotSucceeds*/
                        if (lxr.adv_if('E')) {
                          if (lxr.adv_if('q')) {
                            if (lxr.adv_if('u')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('l')) {
                                  ent_ref_len = 16; /*NotSucceedsEqual*/
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('S')) {
                          if (lxr.adv_if('l')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('n')) {
                                if (lxr.adv_if('t')) {
                                  if (lxr.adv_if('E')) {
                                    if (lxr.adv_if('q')) {
                                      if (lxr.adv_if('u')) {
                                        if (lxr.adv_if('a')) {
                                          if (lxr.adv_if('l')) {
                                            ent_ref_len = 21; /*NotSucceedsSlantEqual*/
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('T')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('d')) {
                                if (lxr.adv_if('e')) {
                                  ent_ref_len = 16; /*NotSucceedsTilde*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('p')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('s')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('t')) {
                        ent_ref_len = 11; /*NotSuperset*/
                        if (lxr.adv_if('E')) {
                          if (lxr.adv_if('q')) {
                            if (lxr.adv_if('u')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('l')) {
                                  ent_ref_len = 16; /*NotSupersetEqual*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('T')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('d')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*NotTilde*/
                  if (lxr.adv_if('E')) {
                    if (lxr.adv_if('q')) {
                      if (lxr.adv_if('u')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('l')) {
                            ent_ref_len = 13; /*NotTildeEqual*/
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('F')) {
                    if (lxr.adv_if('u')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('E')) {
                            if (lxr.adv_if('q')) {
                              if (lxr.adv_if('u')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('l')) {
                                    ent_ref_len = 17; /*NotTildeFullEqual*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('T')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('d')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*NotTildeTilde*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('V')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('c')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('B')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('r')) {
                              ent_ref_len = 14; /*NotVerticalBar*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Nscr*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Ntilde*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      ent_ref_len = 2; /*Nu*/
    }
  }
  else if (lxr.adv_if('O')) {
    if (lxr.adv_if('E')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*OElig*/
          }
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Oacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Ocirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Ocy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('b')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('c')) {
              ent_ref_len = 6; /*Odblac*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Ofr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Ograve*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*Omacr*/
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*Omega*/
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*Omicron*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Oopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('C')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('y')) {
                    if (lxr.adv_if('D')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('b')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('Q')) {
                                  if (lxr.adv_if('u')) {
                                    if (lxr.adv_if('o')) {
                                      if (lxr.adv_if('t')) {
                                        if (lxr.adv_if('e')) {
                                          ent_ref_len = 20; /*OpenCurlyDoubleQuote*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('Q')) {
                      if (lxr.adv_if('u')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('e')) {
                              ent_ref_len = 14; /*OpenCurlyQuote*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      ent_ref_len = 2; /*Or*/
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Oscr*/
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*Oslash*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Otilde*/
            }
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*Otimes*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*Ouml*/
        }
      }
    }
    else if (lxr.adv_if('v')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('B')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*OverBar*/
              }
            }
            else if (lxr.adv_if('r')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('c')) {
                  if (lxr.adv_if('e')) {
                    ent_ref_len = 9; /*OverBrace*/
                  }
                  else if (lxr.adv_if('k')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('t')) {
                        ent_ref_len = 11; /*OverBracket*/
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('P')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('h')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('s')) {
                            if (lxr.adv_if('i')) {
                              if (lxr.adv_if('s')) {
                                ent_ref_len = 15; /*OverParenthesis*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('P')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('D')) {
                  ent_ref_len = 8; /*PartialD*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Pcy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Pfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('i')) {
        ent_ref_len = 3; /*Phi*/
      }
    }
    else if (lxr.adv_if('i')) {
      ent_ref_len = 2; /*Pi*/
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('u')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('M')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('u')) {
                  if (lxr.adv_if('s')) {
                    ent_ref_len = 9; /*PlusMinus*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('p')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('n')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*Poincareplane*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Popf*/
        }
      }
    }
    else if (lxr.adv_if('r')) {
      ent_ref_len = 2; /*Pr*/
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('d')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*Precedes*/
                  if (lxr.adv_if('E')) {
                    if (lxr.adv_if('q')) {
                      if (lxr.adv_if('u')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('l')) {
                            ent_ref_len = 13; /*PrecedesEqual*/
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('S')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('n')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('E')) {
                              if (lxr.adv_if('q')) {
                                if (lxr.adv_if('u')) {
                                  if (lxr.adv_if('a')) {
                                    if (lxr.adv_if('l')) {
                                      ent_ref_len = 18; /*PrecedesSlantEqual*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('T')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('d')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*PrecedesTilde*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*Prime*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*Product*/
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('n')) {
                      ent_ref_len = 10; /*Proportion*/
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('l')) {
                          ent_ref_len = 12; /*Proportional*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Pscr*/
        }
      }
      else if (lxr.adv_if('i')) {
        ent_ref_len = 3; /*Psi*/
      }
    }
  }
  else if (lxr.adv_if('Q')) {
    if (lxr.adv_if('U')) {
      if (lxr.adv_if('O')) {
        if (lxr.adv_if('T')) {
          ent_ref_len = 4; /*QUOT*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Qfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Qopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Qscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('R')) {
    if (lxr.adv_if('B')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*RBarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('E')) {
      if (lxr.adv_if('G')) {
        ent_ref_len = 3; /*REG*/
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Racute*/
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*Rang*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Rarr*/
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Rarrtl*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Rcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Rcedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Rcy*/
      }
    }
    else if (lxr.adv_if('e')) {
      ent_ref_len = 2; /*Re*/
      if (lxr.adv_if('v')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('E')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('m')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('n')) {
                            if (lxr.adv_if('t')) {
                              ent_ref_len = 14; /*ReverseElement*/
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('q')) {
                    if (lxr.adv_if('u')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('b')) {
                              if (lxr.adv_if('r')) {
                                if (lxr.adv_if('i')) {
                                  if (lxr.adv_if('u')) {
                                    if (lxr.adv_if('m')) {
                                      ent_ref_len = 18; /*ReverseEquilibrium*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('U')) {
                  if (lxr.adv_if('p')) {
                    if (lxr.adv_if('E')) {
                      if (lxr.adv_if('q')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('l')) {
                              if (lxr.adv_if('i')) {
                                if (lxr.adv_if('b')) {
                                  if (lxr.adv_if('r')) {
                                    if (lxr.adv_if('i')) {
                                      if (lxr.adv_if('u')) {
                                        if (lxr.adv_if('m')) {
                                          ent_ref_len = 20; /*ReverseUpEquilibrium*/
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Rfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('o')) {
        ent_ref_len = 3; /*Rho*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('h')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('A')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('B')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('c')) {
                              if (lxr.adv_if('k')) {
                                if (lxr.adv_if('e')) {
                                  if (lxr.adv_if('t')) {
                                    ent_ref_len = 17; /*RightAngleBracket*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      ent_ref_len = 10; /*RightArrow*/
                      if (lxr.adv_if('B')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('r')) {
                            ent_ref_len = 13; /*RightArrowBar*/
                          }
                        }
                      }
                      else if (lxr.adv_if('L')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('f')) {
                            if (lxr.adv_if('t')) {
                              if (lxr.adv_if('A')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('r')) {
                                    if (lxr.adv_if('o')) {
                                      if (lxr.adv_if('w')) {
                                        ent_ref_len = 19; /*RightArrowLeftArrow*/
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('C')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('g')) {
                          ent_ref_len = 12; /*RightCeiling*/
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('D')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('u')) {
                  if (lxr.adv_if('b')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('B')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('c')) {
                                if (lxr.adv_if('k')) {
                                  if (lxr.adv_if('e')) {
                                    if (lxr.adv_if('t')) {
                                      ent_ref_len = 18; /*RightDoubleBracket*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('w')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('T')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('V')) {
                            if (lxr.adv_if('e')) {
                              if (lxr.adv_if('c')) {
                                if (lxr.adv_if('t')) {
                                  if (lxr.adv_if('o')) {
                                    if (lxr.adv_if('r')) {
                                      ent_ref_len = 18; /*RightDownTeeVector*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('V')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('c')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('r')) {
                                ent_ref_len = 15; /*RightDownVector*/
                                if (lxr.adv_if('B')) {
                                  if (lxr.adv_if('a')) {
                                    if (lxr.adv_if('r')) {
                                      ent_ref_len = 18; /*RightDownVectorBar*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('F')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('r')) {
                      ent_ref_len = 10; /*RightFloor*/
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('T')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*RightTee*/
                  if (lxr.adv_if('A')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('w')) {
                            ent_ref_len = 13; /*RightTeeArrow*/
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('V')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('c')) {
                        if (lxr.adv_if('t')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('r')) {
                              ent_ref_len = 14; /*RightTeeVector*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('r')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*RightTriangle*/
                            if (lxr.adv_if('B')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('r')) {
                                  ent_ref_len = 16; /*RightTriangleBar*/
                                }
                              }
                            }
                            else if (lxr.adv_if('E')) {
                              if (lxr.adv_if('q')) {
                                if (lxr.adv_if('u')) {
                                  if (lxr.adv_if('a')) {
                                    if (lxr.adv_if('l')) {
                                      ent_ref_len = 18; /*RightTriangleEqual*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('U')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('D')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('V')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('c')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('o')) {
                                  if (lxr.adv_if('r')) {
                                    ent_ref_len = 17; /*RightUpDownVector*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('T')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('V')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('c')) {
                            if (lxr.adv_if('t')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('r')) {
                                  ent_ref_len = 16; /*RightUpTeeVector*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('V')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('c')) {
                      if (lxr.adv_if('t')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('r')) {
                            ent_ref_len = 13; /*RightUpVector*/
                            if (lxr.adv_if('B')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('r')) {
                                  ent_ref_len = 16; /*RightUpVectorBar*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('V')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('c')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('r')) {
                        ent_ref_len = 11; /*RightVector*/
                        if (lxr.adv_if('B')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('r')) {
                              ent_ref_len = 14; /*RightVectorBar*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      ent_ref_len = 10; /*Rightarrow*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Ropf*/
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('I')) {
              if (lxr.adv_if('m')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('s')) {
                          ent_ref_len = 12; /*RoundImplies*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        ent_ref_len = 11; /*Rrightarrow*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Rscr*/
        }
      }
      else if (lxr.adv_if('h')) {
        ent_ref_len = 3; /*Rsh*/
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('D')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('y')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('d')) {
                        ent_ref_len = 11; /*RuleDelayed*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('S')) {
    if (lxr.adv_if('H')) {
      if (lxr.adv_if('C')) {
        if (lxr.adv_if('H')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*SHCHcy*/
            }
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*SHcy*/
        }
      }
    }
    else if (lxr.adv_if('O')) {
      if (lxr.adv_if('F')) {
        if (lxr.adv_if('T')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*SOFTcy*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Sacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      ent_ref_len = 2; /*Sc*/
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Scaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Scedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Scirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Scy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Sfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('D')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('w')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('A')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*ShortDownArrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('L')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('f')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('A')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*ShortLeftArrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('R')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('A')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                ent_ref_len = 15; /*ShortRightArrow*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('U')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('A')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('w')) {
                          ent_ref_len = 12; /*ShortUpArrow*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*Sigma*/
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('C')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('c')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('e')) {
                        ent_ref_len = 11; /*SmallCircle*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Sopf*/
        }
      }
    }
    else if (lxr.adv_if('q')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*Sqrt*/
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Square*/
              if (lxr.adv_if('I')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('s')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('c')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('i')) {
                                  if (lxr.adv_if('o')) {
                                    if (lxr.adv_if('n')) {
                                      ent_ref_len = 18; /*SquareIntersection*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('S')) {
                if (lxr.adv_if('u')) {
                  if (lxr.adv_if('b')) {
                    if (lxr.adv_if('s')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('t')) {
                          ent_ref_len = 12; /*SquareSubset*/
                          if (lxr.adv_if('E')) {
                            if (lxr.adv_if('q')) {
                              if (lxr.adv_if('u')) {
                                if (lxr.adv_if('a')) {
                                  if (lxr.adv_if('l')) {
                                    ent_ref_len = 17; /*SquareSubsetEqual*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('p')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('s')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('t')) {
                              ent_ref_len = 14; /*SquareSuperset*/
                              if (lxr.adv_if('E')) {
                                if (lxr.adv_if('q')) {
                                  if (lxr.adv_if('u')) {
                                    if (lxr.adv_if('a')) {
                                      if (lxr.adv_if('l')) {
                                        ent_ref_len = 19; /*SquareSupersetEqual*/
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('U')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('n')) {
                        ent_ref_len = 11; /*SquareUnion*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Sscr*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Star*/
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('b')) {
        ent_ref_len = 3; /*Sub*/
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*Subset*/
              if (lxr.adv_if('E')) {
                if (lxr.adv_if('q')) {
                  if (lxr.adv_if('u')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('l')) {
                        ent_ref_len = 11; /*SubsetEqual*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('d')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*Succeeds*/
                  if (lxr.adv_if('E')) {
                    if (lxr.adv_if('q')) {
                      if (lxr.adv_if('u')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('l')) {
                            ent_ref_len = 13; /*SucceedsEqual*/
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('S')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('n')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('E')) {
                              if (lxr.adv_if('q')) {
                                if (lxr.adv_if('u')) {
                                  if (lxr.adv_if('a')) {
                                    if (lxr.adv_if('l')) {
                                      ent_ref_len = 18; /*SucceedsSlantEqual*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('T')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('d')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*SucceedsTilde*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('h')) {
          if (lxr.adv_if('T')) {
            if (lxr.adv_if('h')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*SuchThat*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        ent_ref_len = 3; /*Sum*/
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*Sup*/
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*Superset*/
                  if (lxr.adv_if('E')) {
                    if (lxr.adv_if('q')) {
                      if (lxr.adv_if('u')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('l')) {
                            ent_ref_len = 13; /*SupersetEqual*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*Supset*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('T')) {
    if (lxr.adv_if('H')) {
      if (lxr.adv_if('O')) {
        if (lxr.adv_if('R')) {
          if (lxr.adv_if('N')) {
            ent_ref_len = 5; /*THORN*/
          }
        }
      }
    }
    else if (lxr.adv_if('R')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('D')) {
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*TRADE*/
          }
        }
      }
    }
    else if (lxr.adv_if('S')) {
      if (lxr.adv_if('H')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*TSHcy*/
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*TScy*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('b')) {
        ent_ref_len = 3; /*Tab*/
      }
      else if (lxr.adv_if('u')) {
        ent_ref_len = 3; /*Tau*/
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Tcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Tcedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Tcy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Tfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('f')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('e')) {
                    ent_ref_len = 9; /*Therefore*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*Theta*/
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('k')) {
            if (lxr.adv_if('S')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('c')) {
                    if (lxr.adv_if('e')) {
                      ent_ref_len = 10; /*ThickSpace*/
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('S')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('c')) {
                  if (lxr.adv_if('e')) {
                    ent_ref_len = 9; /*ThinSpace*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*Tilde*/
            if (lxr.adv_if('E')) {
              if (lxr.adv_if('q')) {
                if (lxr.adv_if('u')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('l')) {
                      ent_ref_len = 10; /*TildeEqual*/
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('F')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('E')) {
                      if (lxr.adv_if('q')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('l')) {
                              ent_ref_len = 14; /*TildeFullEqual*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('T')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('d')) {
                    if (lxr.adv_if('e')) {
                      ent_ref_len = 10; /*TildeTilde*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Topf*/
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('D')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*TripleDot*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Tscr*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*Tstrok*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('U')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Uacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Uarr*/
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*Uarrocir*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*Ubrcy*/
          }
        }
        else if (lxr.adv_if('e')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Ubreve*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Ucirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Ucy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('b')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('c')) {
              ent_ref_len = 6; /*Udblac*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Ufr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Ugrave*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*Umacr*/
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('B')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*UnderBar*/
                }
              }
              else if (lxr.adv_if('r')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('c')) {
                    if (lxr.adv_if('e')) {
                      ent_ref_len = 10; /*UnderBrace*/
                    }
                    else if (lxr.adv_if('k')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('t')) {
                          ent_ref_len = 12; /*UnderBracket*/
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('P')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('t')) {
                        if (lxr.adv_if('h')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('s')) {
                              if (lxr.adv_if('i')) {
                                if (lxr.adv_if('s')) {
                                  ent_ref_len = 16; /*UnderParenthesis*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*Union*/
            if (lxr.adv_if('P')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('u')) {
                  if (lxr.adv_if('s')) {
                    ent_ref_len = 9; /*UnionPlus*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*Uogon*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Uopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                ent_ref_len = 7; /*UpArrow*/
                if (lxr.adv_if('B')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('r')) {
                      ent_ref_len = 10; /*UpArrowBar*/
                    }
                  }
                }
                else if (lxr.adv_if('D')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('A')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('r')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('w')) {
                                  ent_ref_len = 16; /*UpArrowDownArrow*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('D')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('w')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('A')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        ent_ref_len = 11; /*UpDownArrow*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('E')) {
        if (lxr.adv_if('q')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('b')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('m')) {
                            ent_ref_len = 13; /*UpEquilibrium*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('T')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*UpTee*/
            if (lxr.adv_if('A')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      ent_ref_len = 10; /*UpTeeArrow*/
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                ent_ref_len = 7; /*Uparrow*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('w')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        ent_ref_len = 11; /*Updownarrow*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('L')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('f')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('A')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*UpperLeftArrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('R')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('A')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                ent_ref_len = 15; /*UpperRightArrow*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          ent_ref_len = 4; /*Upsi*/
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*Upsilon*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*Uring*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Uscr*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Utilde*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*Uuml*/
        }
      }
    }
  }
  else if (lxr.adv_if('V')) {
    if (lxr.adv_if('D')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*VDash*/
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Vbar*/
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Vcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*Vdash*/
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*Vdashl*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*Vee*/
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*Verbar*/
            }
          }
        }
        else if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*Vert*/
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('B')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('r')) {
                        ent_ref_len = 11; /*VerticalBar*/
                      }
                    }
                  }
                  else if (lxr.adv_if('L')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('e')) {
                          ent_ref_len = 12; /*VerticalLine*/
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('S')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('p')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('t')) {
                                if (lxr.adv_if('o')) {
                                  if (lxr.adv_if('r')) {
                                    ent_ref_len = 17; /*VerticalSeparator*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('T')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('d')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*VerticalTilde*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('y')) {
          if (lxr.adv_if('T')) {
            if (lxr.adv_if('h')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('S')) {
                    if (lxr.adv_if('p')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('c')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*VeryThinSpace*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Vfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Vopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Vscr*/
        }
      }
    }
    else if (lxr.adv_if('v')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*Vvdash*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('W')) {
    if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Wcirc*/
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*Wedge*/
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Wfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Wopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Wscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('X')) {
    if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Xfr*/
      }
    }
    else if (lxr.adv_if('i')) {
      ent_ref_len = 2; /*Xi*/
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Xopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Xscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('Y')) {
    if (lxr.adv_if('A')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*YAcy*/
        }
      }
    }
    else if (lxr.adv_if('I')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*YIcy*/
        }
      }
    }
    else if (lxr.adv_if('U')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*YUcy*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Yacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*Ycirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Ycy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Yfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Yopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Yscr*/
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*Yuml*/
        }
      }
    }
  }
  else if (lxr.adv_if('Z')) {
    if (lxr.adv_if('H')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*ZHcy*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*Zacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*Zcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*Zcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*Zdot*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('W')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('d')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('S')) {
                      if (lxr.adv_if('p')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('c')) {
                            if (lxr.adv_if('e')) {
                              ent_ref_len = 14; /*ZeroWidthSpace*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*Zeta*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*Zfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*Zopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*Zscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('a')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*aacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*abreve*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      ent_ref_len = 2; /*ac*/
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*acE*/
      }
      else if (lxr.adv_if('d')) {
        ent_ref_len = 3; /*acd*/
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*acirc*/
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*acute*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*acy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*aelig*/
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      ent_ref_len = 2; /*af*/
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*afr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*agrave*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('f')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('y')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*alefsym*/
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*aleph*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('h')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*alpha*/
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*amacr*/
          }
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*amalg*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*amp*/
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('d')) {
        ent_ref_len = 3; /*and*/
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*andand*/
            }
          }
        }
        else if (lxr.adv_if('d')) {
          ent_ref_len = 4; /*andd*/
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*andslope*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('v')) {
          ent_ref_len = 4; /*andv*/
        }
      }
      else if (lxr.adv_if('g')) {
        ent_ref_len = 3; /*ang*/
        if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*ange*/
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*angle*/
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*angmsd*/
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('a')) {
                  ent_ref_len = 8; /*angmsdaa*/
                }
                else if (lxr.adv_if('b')) {
                  ent_ref_len = 8; /*angmsdab*/
                }
                else if (lxr.adv_if('c')) {
                  ent_ref_len = 8; /*angmsdac*/
                }
                else if (lxr.adv_if('d')) {
                  ent_ref_len = 8; /*angmsdad*/
                }
                else if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*angmsdae*/
                }
                else if (lxr.adv_if('f')) {
                  ent_ref_len = 8; /*angmsdaf*/
                }
                else if (lxr.adv_if('g')) {
                  ent_ref_len = 8; /*angmsdag*/
                }
                else if (lxr.adv_if('h')) {
                  ent_ref_len = 8; /*angmsdah*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*angrt*/
            if (lxr.adv_if('v')) {
              if (lxr.adv_if('b')) {
                ent_ref_len = 7; /*angrtvb*/
                if (lxr.adv_if('d')) {
                  ent_ref_len = 8; /*angrtvbd*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('p')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*angsph*/
            }
          }
          else if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*angst*/
          }
        }
        else if (lxr.adv_if('z')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*angzarr*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*aogon*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*aopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      ent_ref_len = 2; /*ap*/
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*apE*/
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*apacir*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*ape*/
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('d')) {
          ent_ref_len = 4; /*apid*/
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('s')) {
          ent_ref_len = 4; /*apos*/
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('x')) {
              ent_ref_len = 6; /*approx*/
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('q')) {
                  ent_ref_len = 8; /*approxeq*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*aring*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*ascr*/
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*ast*/
      }
      else if (lxr.adv_if('y')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*asymp*/
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('q')) {
                ent_ref_len = 7; /*asympeq*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*atilde*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*auml*/
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*awconint*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*awint*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('b')) {
    if (lxr.adv_if('N')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*bNot*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('k')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('g')) {
                  ent_ref_len = 8; /*backcong*/
                }
              }
            }
          }
          else if (lxr.adv_if('e')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('s')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('l')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('n')) {
                        ent_ref_len = 11; /*backepsilon*/
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('p')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('m')) {
                  if (lxr.adv_if('e')) {
                    ent_ref_len = 9; /*backprime*/
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*backsim*/
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*backsimeq*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('v')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*barvee*/
            }
          }
        }
        else if (lxr.adv_if('w')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*barwed*/
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*barwedge*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('k')) {
          ent_ref_len = 4; /*bbrk*/
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('b')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('k')) {
                  ent_ref_len = 8; /*bbrktbrk*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*bcong*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*bcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*bdquo*/
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*becaus*/
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*because*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('y')) {
              if (lxr.adv_if('v')) {
                ent_ref_len = 7; /*bemptyv*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*bepsi*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('u')) {
              ent_ref_len = 6; /*bernou*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*beta*/
        }
        else if (lxr.adv_if('h')) {
          ent_ref_len = 4; /*beth*/
        }
        else if (lxr.adv_if('w')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*between*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*bfr*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*bigcap*/
            }
          }
          else if (lxr.adv_if('i')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('c')) {
                ent_ref_len = 7; /*bigcirc*/
              }
            }
          }
          else if (lxr.adv_if('u')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*bigcup*/
            }
          }
        }
        else if (lxr.adv_if('o')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*bigodot*/
              }
            }
          }
          else if (lxr.adv_if('p')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*bigoplus*/
                }
              }
            }
          }
          else if (lxr.adv_if('t')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('m')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('s')) {
                    ent_ref_len = 9; /*bigotimes*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('q')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('p')) {
                  ent_ref_len = 8; /*bigsqcup*/
                }
              }
            }
          }
          else if (lxr.adv_if('t')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*bigstar*/
              }
            }
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('g')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('d')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              if (lxr.adv_if('n')) {
                                ent_ref_len = 15; /*bigtriangledown*/
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('u')) {
                          if (lxr.adv_if('p')) {
                            ent_ref_len = 13; /*bigtriangleup*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('u')) {
          if (lxr.adv_if('p')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*biguplus*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('v')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*bigvee*/
            }
          }
        }
        else if (lxr.adv_if('w')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('d')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*bigwedge*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('k')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('w')) {
              ent_ref_len = 6; /*bkarow*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('k')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('z')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('e')) {
                          ent_ref_len = 12; /*blacklozenge*/
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('s')) {
              if (lxr.adv_if('q')) {
                if (lxr.adv_if('u')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('e')) {
                        ent_ref_len = 11; /*blacksquare*/
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('t')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*blacktriangle*/
                            if (lxr.adv_if('d')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('w')) {
                                  if (lxr.adv_if('n')) {
                                    ent_ref_len = 17; /*blacktriangledown*/
                                  }
                                }
                              }
                            }
                            else if (lxr.adv_if('l')) {
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('f')) {
                                  if (lxr.adv_if('t')) {
                                    ent_ref_len = 17; /*blacktriangleleft*/
                                  }
                                }
                              }
                            }
                            else if (lxr.adv_if('r')) {
                              if (lxr.adv_if('i')) {
                                if (lxr.adv_if('g')) {
                                  if (lxr.adv_if('h')) {
                                    if (lxr.adv_if('t')) {
                                      ent_ref_len = 18; /*blacktriangleright*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*blank*/
          }
        }
      }
      else if (lxr.adv_if('k')) {
        if (lxr.adv_if('1')) {
          if (lxr.adv_if('2')) {
            ent_ref_len = 5; /*blk12*/
          }
          else if (lxr.adv_if('4')) {
            ent_ref_len = 5; /*blk14*/
          }
        }
        else if (lxr.adv_if('3')) {
          if (lxr.adv_if('4')) {
            ent_ref_len = 5; /*blk34*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*block*/
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*bne*/
        if (lxr.adv_if('q')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('v')) {
                ent_ref_len = 7; /*bnequiv*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*bnot*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*bopf*/
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*bot*/
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('m')) {
              ent_ref_len = 6; /*bottom*/
            }
          }
        }
      }
      else if (lxr.adv_if('w')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*bowtie*/
            }
          }
        }
      }
      else if (lxr.adv_if('x')) {
        if (lxr.adv_if('D')) {
          if (lxr.adv_if('L')) {
            ent_ref_len = 5; /*boxDL*/
          }
          else if (lxr.adv_if('R')) {
            ent_ref_len = 5; /*boxDR*/
          }
          else if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*boxDl*/
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*boxDr*/
          }
        }
        else if (lxr.adv_if('H')) {
          ent_ref_len = 4; /*boxH*/
          if (lxr.adv_if('D')) {
            ent_ref_len = 5; /*boxHD*/
          }
          else if (lxr.adv_if('U')) {
            ent_ref_len = 5; /*boxHU*/
          }
          else if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*boxHd*/
          }
          else if (lxr.adv_if('u')) {
            ent_ref_len = 5; /*boxHu*/
          }
        }
        else if (lxr.adv_if('U')) {
          if (lxr.adv_if('L')) {
            ent_ref_len = 5; /*boxUL*/
          }
          else if (lxr.adv_if('R')) {
            ent_ref_len = 5; /*boxUR*/
          }
          else if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*boxUl*/
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*boxUr*/
          }
        }
        else if (lxr.adv_if('V')) {
          ent_ref_len = 4; /*boxV*/
          if (lxr.adv_if('H')) {
            ent_ref_len = 5; /*boxVH*/
          }
          else if (lxr.adv_if('L')) {
            ent_ref_len = 5; /*boxVL*/
          }
          else if (lxr.adv_if('R')) {
            ent_ref_len = 5; /*boxVR*/
          }
          else if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*boxVh*/
          }
          else if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*boxVl*/
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*boxVr*/
          }
        }
        else if (lxr.adv_if('b')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('x')) {
              ent_ref_len = 6; /*boxbox*/
            }
          }
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('L')) {
            ent_ref_len = 5; /*boxdL*/
          }
          else if (lxr.adv_if('R')) {
            ent_ref_len = 5; /*boxdR*/
          }
          else if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*boxdl*/
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*boxdr*/
          }
        }
        else if (lxr.adv_if('h')) {
          ent_ref_len = 4; /*boxh*/
          if (lxr.adv_if('D')) {
            ent_ref_len = 5; /*boxhD*/
          }
          else if (lxr.adv_if('U')) {
            ent_ref_len = 5; /*boxhU*/
          }
          else if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*boxhd*/
          }
          else if (lxr.adv_if('u')) {
            ent_ref_len = 5; /*boxhu*/
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*boxminus*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*boxplus*/
              }
            }
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*boxtimes*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('u')) {
          if (lxr.adv_if('L')) {
            ent_ref_len = 5; /*boxuL*/
          }
          else if (lxr.adv_if('R')) {
            ent_ref_len = 5; /*boxuR*/
          }
          else if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*boxul*/
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*boxur*/
          }
        }
        else if (lxr.adv_if('v')) {
          ent_ref_len = 4; /*boxv*/
          if (lxr.adv_if('H')) {
            ent_ref_len = 5; /*boxvH*/
          }
          else if (lxr.adv_if('L')) {
            ent_ref_len = 5; /*boxvL*/
          }
          else if (lxr.adv_if('R')) {
            ent_ref_len = 5; /*boxvR*/
          }
          else if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*boxvh*/
          }
          else if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*boxvl*/
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*boxvr*/
          }
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*bprime*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('v')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*breve*/
          }
        }
      }
      else if (lxr.adv_if('v')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*brvbar*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*bscr*/
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*bsemi*/
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          ent_ref_len = 4; /*bsim*/
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*bsime*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*bsol*/
          if (lxr.adv_if('b')) {
            ent_ref_len = 5; /*bsolb*/
          }
          else if (lxr.adv_if('h')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('b')) {
                  ent_ref_len = 8; /*bsolhsub*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*bull*/
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*bullet*/
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*bump*/
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*bumpE*/
          }
          else if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*bumpe*/
            if (lxr.adv_if('q')) {
              ent_ref_len = 6; /*bumpeq*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('c')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*cacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*cap*/
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*capand*/
            }
          }
        }
        else if (lxr.adv_if('b')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('p')) {
                  ent_ref_len = 8; /*capbrcup*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('c')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*capcap*/
            }
          }
          else if (lxr.adv_if('u')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*capcup*/
            }
          }
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*capdot*/
            }
          }
        }
        else if (lxr.adv_if('s')) {
          ent_ref_len = 4; /*caps*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*caret*/
          }
        }
        else if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*caron*/
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*ccaps*/
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*ccaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*ccedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*ccirc*/
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*ccups*/
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*ccupssm*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*cdot*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*cedil*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('y')) {
              if (lxr.adv_if('v')) {
                ent_ref_len = 7; /*cemptyv*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*cent*/
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('d')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*centerdot*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*cfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*chcy*/
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*check*/
            if (lxr.adv_if('m')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('k')) {
                    ent_ref_len = 9; /*checkmark*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        ent_ref_len = 3; /*chi*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*cir*/
        if (lxr.adv_if('E')) {
          ent_ref_len = 4; /*cirE*/
        }
        else if (lxr.adv_if('c')) {
          ent_ref_len = 4; /*circ*/
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('q')) {
              ent_ref_len = 6; /*circeq*/
            }
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('f')) {
                              if (lxr.adv_if('t')) {
                                ent_ref_len = 15; /*circlearrowleft*/
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('r')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('g')) {
                              if (lxr.adv_if('h')) {
                                if (lxr.adv_if('t')) {
                                  ent_ref_len = 16; /*circlearrowright*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if (lxr.adv_if('d')) {
                if (lxr.adv_if('R')) {
                  ent_ref_len = 8; /*circledR*/
                }
                else if (lxr.adv_if('S')) {
                  ent_ref_len = 8; /*circledS*/
                }
                else if (lxr.adv_if('a')) {
                  if (lxr.adv_if('s')) {
                    if (lxr.adv_if('t')) {
                      ent_ref_len = 10; /*circledast*/
                    }
                  }
                }
                else if (lxr.adv_if('c')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('c')) {
                        ent_ref_len = 11; /*circledcirc*/
                      }
                    }
                  }
                }
                else if (lxr.adv_if('d')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('s')) {
                      if (lxr.adv_if('h')) {
                        ent_ref_len = 11; /*circleddash*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*cire*/
        }
        else if (lxr.adv_if('f')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*cirfnint*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*cirmid*/
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*cirscir*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('u')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*clubs*/
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*clubsuit*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*colon*/
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*colone*/
              if (lxr.adv_if('q')) {
                ent_ref_len = 7; /*coloneq*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*comma*/
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*commat*/
            }
          }
        }
        else if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*comp*/
          if (lxr.adv_if('f')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*compfn*/
            }
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('m')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('t')) {
                      ent_ref_len = 10; /*complement*/
                    }
                  }
                }
              }
              else if (lxr.adv_if('x')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('s')) {
                    ent_ref_len = 9; /*complexes*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*cong*/
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*congdot*/
              }
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*conint*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*copf*/
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*coprod*/
            }
          }
        }
        else if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*copy*/
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*copysr*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*crarr*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*cross*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*cscr*/
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('b')) {
          ent_ref_len = 4; /*csub*/
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*csube*/
          }
        }
        else if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*csup*/
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*csupe*/
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*ctdot*/
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('l')) {
                ent_ref_len = 7; /*cudarrl*/
              }
              else if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*cudarrr*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*cuepr*/
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*cuesc*/
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*cularr*/
              if (lxr.adv_if('p')) {
                ent_ref_len = 7; /*cularrp*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*cup*/
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('p')) {
                  ent_ref_len = 8; /*cupbrcap*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('c')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*cupcap*/
            }
          }
          else if (lxr.adv_if('u')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*cupcup*/
            }
          }
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*cupdot*/
            }
          }
        }
        else if (lxr.adv_if('o')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*cupor*/
          }
        }
        else if (lxr.adv_if('s')) {
          ent_ref_len = 4; /*cups*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*curarr*/
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*curarrm*/
              }
            }
          }
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('y')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('q')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('c')) {
                        ent_ref_len = 11; /*curlyeqprec*/
                      }
                    }
                  }
                }
                else if (lxr.adv_if('s')) {
                  if (lxr.adv_if('u')) {
                    if (lxr.adv_if('c')) {
                      if (lxr.adv_if('c')) {
                        ent_ref_len = 11; /*curlyeqsucc*/
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('v')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*curlyvee*/
                }
              }
            }
            else if (lxr.adv_if('w')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('d')) {
                  if (lxr.adv_if('g')) {
                    if (lxr.adv_if('e')) {
                      ent_ref_len = 10; /*curlywedge*/
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*curren*/
            }
          }
        }
        else if (lxr.adv_if('v')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('f')) {
                            if (lxr.adv_if('t')) {
                              ent_ref_len = 14; /*curvearrowleft*/
                            }
                          }
                        }
                      }
                      else if (lxr.adv_if('r')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('g')) {
                            if (lxr.adv_if('h')) {
                              if (lxr.adv_if('t')) {
                                ent_ref_len = 15; /*curvearrowright*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('v')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*cuvee*/
          }
        }
      }
      else if (lxr.adv_if('w')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*cuwed*/
          }
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*cwconint*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*cwint*/
          }
        }
      }
    }
    else if (lxr.adv_if('y')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*cylcty*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('d')) {
    if (lxr.adv_if('A')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*dArr*/
        }
      }
    }
    else if (lxr.adv_if('H')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*dHar*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*dagger*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*daleth*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*darr*/
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('h')) {
          ent_ref_len = 4; /*dash*/
          if (lxr.adv_if('v')) {
            ent_ref_len = 5; /*dashv*/
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('k')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                ent_ref_len = 7; /*dbkarow*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*dblac*/
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*dcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*dcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      ent_ref_len = 2; /*dd*/
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('g')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*ddagger*/
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*ddarr*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('q')) {
                ent_ref_len = 7; /*ddotseq*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('g')) {
        ent_ref_len = 3; /*deg*/
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*delta*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('y')) {
              if (lxr.adv_if('v')) {
                ent_ref_len = 7; /*demptyv*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*dfisht*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*dfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*dharl*/
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*dharr*/
          }
        }
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('m')) {
          ent_ref_len = 4; /*diam*/
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('d')) {
                ent_ref_len = 7; /*diamond*/
                if (lxr.adv_if('s')) {
                  if (lxr.adv_if('u')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('t')) {
                        ent_ref_len = 11; /*diamondsuit*/
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*diams*/
          }
        }
      }
      else if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*die*/
      }
      else if (lxr.adv_if('g')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('m')) {
              if (lxr.adv_if('a')) {
                ent_ref_len = 7; /*digamma*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*disin*/
          }
        }
      }
      else if (lxr.adv_if('v')) {
        ent_ref_len = 3; /*div*/
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*divide*/
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('m')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('s')) {
                            ent_ref_len = 13; /*divideontimes*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('x')) {
              ent_ref_len = 6; /*divonx*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('j')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*djcy*/
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*dlcorn*/
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*dlcrop*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*dollar*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*dopf*/
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*dot*/
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('q')) {
            ent_ref_len = 5; /*doteq*/
            if (lxr.adv_if('d')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*doteqdot*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*dotminus*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*dotplus*/
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('q')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('e')) {
                    ent_ref_len = 9; /*dotsquare*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('b')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('w')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('d')) {
                          if (lxr.adv_if('g')) {
                            if (lxr.adv_if('e')) {
                              ent_ref_len = 14; /*doublebarwedge*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('w')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    ent_ref_len = 9; /*downarrow*/
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('d')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('w')) {
                            if (lxr.adv_if('s')) {
                              ent_ref_len = 14; /*downdownarrows*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('h')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('f')) {
                              if (lxr.adv_if('t')) {
                                ent_ref_len = 15; /*downharpoonleft*/
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('r')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('g')) {
                              if (lxr.adv_if('h')) {
                                if (lxr.adv_if('t')) {
                                  ent_ref_len = 16; /*downharpoonright*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('b')) {
        if (lxr.adv_if('k')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('w')) {
                  ent_ref_len = 8; /*drbkarow*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*drcorn*/
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*drcrop*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*dscr*/
        }
        else if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*dscy*/
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*dsol*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*dstrok*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*dtdot*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('i')) {
          ent_ref_len = 4; /*dtri*/
          if (lxr.adv_if('f')) {
            ent_ref_len = 5; /*dtrif*/
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*duarr*/
          }
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*duhar*/
          }
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*dwangle*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('z')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*dzcy*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*dzigrarr*/
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('e')) {
    if (lxr.adv_if('D')) {
      if (lxr.adv_if('D')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*eDDot*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*eDot*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*eacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*easter*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*ecaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*ecir*/
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*ecirc*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*ecolon*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*ecy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*edot*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      ent_ref_len = 2; /*ee*/
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('D')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*efDot*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*efr*/
      }
    }
    else if (lxr.adv_if('g')) {
      ent_ref_len = 2; /*eg*/
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*egrave*/
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        ent_ref_len = 3; /*egs*/
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*egsdot*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      ent_ref_len = 2; /*el*/
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*elinters*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        ent_ref_len = 3; /*ell*/
      }
      else if (lxr.adv_if('s')) {
        ent_ref_len = 3; /*els*/
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*elsdot*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*emacr*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*empty*/
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*emptyset*/
                }
              }
            }
            else if (lxr.adv_if('v')) {
              ent_ref_len = 6; /*emptyv*/
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*emsp*/
          if (lxr.adv_if('1')) {
            if (lxr.adv_if('3')) {
              ent_ref_len = 6; /*emsp13*/
            }
            else if (lxr.adv_if('4')) {
              ent_ref_len = 6; /*emsp14*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('g')) {
        ent_ref_len = 3; /*eng*/
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*ensp*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*eogon*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*eopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*epar*/
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*eparsl*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*eplus*/
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          ent_ref_len = 4; /*epsi*/
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*epsilon*/
              }
            }
          }
          else if (lxr.adv_if('v')) {
            ent_ref_len = 5; /*epsiv*/
          }
        }
      }
    }
    else if (lxr.adv_if('q')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('c')) {
              ent_ref_len = 6; /*eqcirc*/
            }
          }
        }
        else if (lxr.adv_if('o')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*eqcolon*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*eqsim*/
          }
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('r')) {
                      ent_ref_len = 10; /*eqslantgtr*/
                    }
                  }
                }
                else if (lxr.adv_if('l')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('s')) {
                      if (lxr.adv_if('s')) {
                        ent_ref_len = 11; /*eqslantless*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*equals*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*equest*/
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('v')) {
            ent_ref_len = 5; /*equiv*/
            if (lxr.adv_if('D')) {
              if (lxr.adv_if('D')) {
                ent_ref_len = 7; /*equivDD*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('v')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('s')) {
                if (lxr.adv_if('l')) {
                  ent_ref_len = 8; /*eqvparsl*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('D')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*erDot*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*erarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*escr*/
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*esdot*/
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          ent_ref_len = 4; /*esim*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('a')) {
        ent_ref_len = 3; /*eta*/
      }
      else if (lxr.adv_if('h')) {
        ent_ref_len = 3; /*eth*/
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*euml*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('o')) {
          ent_ref_len = 4; /*euro*/
        }
      }
    }
    else if (lxr.adv_if('x')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*excl*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*exist*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('n')) {
                        ent_ref_len = 11; /*expectation*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('e')) {
                          ent_ref_len = 12; /*exponentiale*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('f')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('d')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('s')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('q')) {
                            ent_ref_len = 13; /*fallingdotseq*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*fcy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*female*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('g')) {
              ent_ref_len = 6; /*ffilig*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*fflig*/
          }
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('g')) {
              ent_ref_len = 6; /*ffllig*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*ffr*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*filig*/
          }
        }
      }
    }
    else if (lxr.adv_if('j')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*fjlig*/
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*flat*/
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*fllig*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*fltns*/
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*fnof*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*fopf*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*forall*/
            }
          }
        }
        else if (lxr.adv_if('k')) {
          ent_ref_len = 4; /*fork*/
          if (lxr.adv_if('v')) {
            ent_ref_len = 5; /*forkv*/
          }
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*fpartint*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('1')) {
            if (lxr.adv_if('2')) {
              ent_ref_len = 6; /*frac12*/
            }
            else if (lxr.adv_if('3')) {
              ent_ref_len = 6; /*frac13*/
            }
            else if (lxr.adv_if('4')) {
              ent_ref_len = 6; /*frac14*/
            }
            else if (lxr.adv_if('5')) {
              ent_ref_len = 6; /*frac15*/
            }
            else if (lxr.adv_if('6')) {
              ent_ref_len = 6; /*frac16*/
            }
            else if (lxr.adv_if('8')) {
              ent_ref_len = 6; /*frac18*/
            }
          }
          else if (lxr.adv_if('2')) {
            if (lxr.adv_if('3')) {
              ent_ref_len = 6; /*frac23*/
            }
            else if (lxr.adv_if('5')) {
              ent_ref_len = 6; /*frac25*/
            }
          }
          else if (lxr.adv_if('3')) {
            if (lxr.adv_if('4')) {
              ent_ref_len = 6; /*frac34*/
            }
            else if (lxr.adv_if('5')) {
              ent_ref_len = 6; /*frac35*/
            }
            else if (lxr.adv_if('8')) {
              ent_ref_len = 6; /*frac38*/
            }
          }
          else if (lxr.adv_if('4')) {
            if (lxr.adv_if('5')) {
              ent_ref_len = 6; /*frac45*/
            }
          }
          else if (lxr.adv_if('5')) {
            if (lxr.adv_if('6')) {
              ent_ref_len = 6; /*frac56*/
            }
            else if (lxr.adv_if('8')) {
              ent_ref_len = 6; /*frac58*/
            }
          }
          else if (lxr.adv_if('7')) {
            if (lxr.adv_if('8')) {
              ent_ref_len = 6; /*frac78*/
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*frasl*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('w')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*frown*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*fscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('g')) {
    if (lxr.adv_if('E')) {
      ent_ref_len = 2; /*gE*/
      if (lxr.adv_if('l')) {
        ent_ref_len = 3; /*gEl*/
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*gacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*gamma*/
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*gammad*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*gap*/
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*gbreve*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*gcirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*gcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*gdot*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      ent_ref_len = 2; /*ge*/
      if (lxr.adv_if('l')) {
        ent_ref_len = 3; /*gel*/
      }
      else if (lxr.adv_if('q')) {
        ent_ref_len = 3; /*geq*/
        if (lxr.adv_if('q')) {
          ent_ref_len = 4; /*geqq*/
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*geqslant*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        ent_ref_len = 3; /*ges*/
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*gescc*/
          }
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*gesdot*/
              if (lxr.adv_if('o')) {
                ent_ref_len = 7; /*gesdoto*/
                if (lxr.adv_if('l')) {
                  ent_ref_len = 8; /*gesdotol*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*gesl*/
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*gesles*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*gfr*/
      }
    }
    else if (lxr.adv_if('g')) {
      ent_ref_len = 2; /*gg*/
      if (lxr.adv_if('g')) {
        ent_ref_len = 3; /*ggg*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*gimel*/
          }
        }
      }
    }
    else if (lxr.adv_if('j')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*gjcy*/
        }
      }
    }
    else if (lxr.adv_if('l')) {
      ent_ref_len = 2; /*gl*/
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*glE*/
      }
      else if (lxr.adv_if('a')) {
        ent_ref_len = 3; /*gla*/
      }
      else if (lxr.adv_if('j')) {
        ent_ref_len = 3; /*glj*/
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*gnE*/
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*gnap*/
          if (lxr.adv_if('p')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('x')) {
                  ent_ref_len = 8; /*gnapprox*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*gne*/
        if (lxr.adv_if('q')) {
          ent_ref_len = 4; /*gneq*/
          if (lxr.adv_if('q')) {
            ent_ref_len = 5; /*gneqq*/
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*gnsim*/
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*gopf*/
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('v')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*grave*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*gscr*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          ent_ref_len = 4; /*gsim*/
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*gsime*/
          }
          else if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*gsiml*/
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      ent_ref_len = 2; /*gt*/
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('c')) {
          ent_ref_len = 4; /*gtcc*/
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*gtcir*/
          }
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*gtdot*/
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('P')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*gtlPar*/
            }
          }
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*gtquest*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('p')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('x')) {
                    ent_ref_len = 9; /*gtrapprox*/
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*gtrarr*/
            }
          }
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*gtrdot*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          if (lxr.adv_if('q')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('s')) {
                  if (lxr.adv_if('s')) {
                    ent_ref_len = 9; /*gtreqless*/
                  }
                }
              }
            }
            else if (lxr.adv_if('q')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('s')) {
                    if (lxr.adv_if('s')) {
                      ent_ref_len = 10; /*gtreqqless*/
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*gtrless*/
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              ent_ref_len = 6; /*gtrsim*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('v')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('q')) {
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*gvertneqq*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('E')) {
          ent_ref_len = 4; /*gvnE*/
        }
      }
    }
  }
  else if (lxr.adv_if('h')) {
    if (lxr.adv_if('A')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*hArr*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*hairsp*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*half*/
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*hamilt*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*hardcy*/
            }
          }
        }
        else if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*harr*/
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*harrcir*/
              }
            }
          }
          else if (lxr.adv_if('w')) {
            ent_ref_len = 5; /*harrw*/
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*hbar*/
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*hcirc*/
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*hearts*/
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*heartsuit*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*hellip*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*hercon*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*hfr*/
      }
    }
    else if (lxr.adv_if('k')) {
      if (lxr.adv_if('s')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('w')) {
                  ent_ref_len = 8; /*hksearow*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('w')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('w')) {
                  ent_ref_len = 8; /*hkswarow*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*hoarr*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*homtht*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('k')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('f')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('w')) {
                            ent_ref_len = 13; /*hookleftarrow*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('h')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*hookrightarrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*hopf*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*horbar*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*hscr*/
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*hslash*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*hstrok*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('y')) {
      if (lxr.adv_if('b')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*hybull*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('h')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*hyphen*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('i')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*iacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      ent_ref_len = 2; /*ic*/
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*icirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*icy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*iecy*/
        }
      }
      else if (lxr.adv_if('x')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*iexcl*/
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('f')) {
        ent_ref_len = 3; /*iff*/
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*ifr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*igrave*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('i')) {
      ent_ref_len = 2; /*ii*/
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*iiiint*/
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*iiint*/
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('f')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*iinfin*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*iiota*/
          }
        }
      }
    }
    else if (lxr.adv_if('j')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*ijlig*/
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*imacr*/
          }
        }
        else if (lxr.adv_if('g')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*image*/
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*imagline*/
                }
              }
            }
          }
          else if (lxr.adv_if('p')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*imagpart*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*imath*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*imof*/
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*imped*/
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      ent_ref_len = 2; /*in*/
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*incare*/
            }
          }
        }
      }
      else if (lxr.adv_if('f')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*infin*/
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*infintie*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*inodot*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*int*/
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*intcal*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          if (lxr.adv_if('g')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*integers*/
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('l')) {
                  ent_ref_len = 8; /*intercal*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('h')) {
                if (lxr.adv_if('k')) {
                  ent_ref_len = 8; /*intlarhk*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('d')) {
                ent_ref_len = 7; /*intprod*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*iocy*/
        }
      }
      else if (lxr.adv_if('g')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*iogon*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*iopf*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*iota*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*iprod*/
          }
        }
      }
    }
    else if (lxr.adv_if('q')) {
      if (lxr.adv_if('u')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*iquest*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*iscr*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          ent_ref_len = 4; /*isin*/
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*isinE*/
          }
          else if (lxr.adv_if('d')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*isindot*/
              }
            }
          }
          else if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*isins*/
            if (lxr.adv_if('v')) {
              ent_ref_len = 6; /*isinsv*/
            }
          }
          else if (lxr.adv_if('v')) {
            ent_ref_len = 5; /*isinv*/
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      ent_ref_len = 2; /*it*/
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*itilde*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('k')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*iukcy*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*iuml*/
        }
      }
    }
  }
  else if (lxr.adv_if('j')) {
    if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*jcirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*jcy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*jfr*/
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*jmath*/
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*jopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*jscr*/
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*jsercy*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('k')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*jukcy*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('k')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*kappa*/
            if (lxr.adv_if('v')) {
              ent_ref_len = 6; /*kappav*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*kcedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*kcy*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*kfr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*kgreen*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*khcy*/
        }
      }
    }
    else if (lxr.adv_if('j')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*kjcy*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*kopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*kscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('l')) {
    if (lxr.adv_if('A')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*lAarr*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*lArr*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*lAtail*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('B')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*lBarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('E')) {
      ent_ref_len = 2; /*lE*/
      if (lxr.adv_if('g')) {
        ent_ref_len = 3; /*lEg*/
      }
    }
    else if (lxr.adv_if('H')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*lHar*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*lacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('p')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('y')) {
                if (lxr.adv_if('v')) {
                  ent_ref_len = 8; /*laemptyv*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('g')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*lagran*/
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('a')) {
              ent_ref_len = 6; /*lambda*/
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*lang*/
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*langd*/
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*langle*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*lap*/
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*laquo*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*larr*/
          if (lxr.adv_if('b')) {
            ent_ref_len = 5; /*larrb*/
            if (lxr.adv_if('f')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*larrbfs*/
              }
            }
          }
          else if (lxr.adv_if('f')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*larrfs*/
            }
          }
          else if (lxr.adv_if('h')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*larrhk*/
            }
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*larrlp*/
            }
          }
          else if (lxr.adv_if('p')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*larrpl*/
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*larrsim*/
              }
            }
          }
          else if (lxr.adv_if('t')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*larrtl*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*lat*/
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*latail*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*late*/
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*lates*/
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*lbarr*/
          }
        }
      }
      else if (lxr.adv_if('b')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*lbbrk*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*lbrace*/
            }
            else if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*lbrack*/
            }
          }
        }
        else if (lxr.adv_if('k')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*lbrke*/
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('d')) {
                ent_ref_len = 7; /*lbrksld*/
              }
              else if (lxr.adv_if('u')) {
                ent_ref_len = 7; /*lbrkslu*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*lcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*lcedil*/
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*lceil*/
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('b')) {
          ent_ref_len = 4; /*lcub*/
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*lcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*ldca*/
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*ldquo*/
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*ldquor*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*ldrdhar*/
              }
            }
          }
        }
        else if (lxr.adv_if('u')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*ldrushar*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('h')) {
          ent_ref_len = 4; /*ldsh*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      ent_ref_len = 2; /*le*/
      if (lxr.adv_if('f')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    ent_ref_len = 9; /*leftarrow*/
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('l')) {
                            ent_ref_len = 13; /*leftarrowtail*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('h')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('d')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              if (lxr.adv_if('n')) {
                                ent_ref_len = 15; /*leftharpoondown*/
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('u')) {
                          if (lxr.adv_if('p')) {
                            ent_ref_len = 13; /*leftharpoonup*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('f')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('w')) {
                            if (lxr.adv_if('s')) {
                              ent_ref_len = 14; /*leftleftarrows*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('h')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*leftrightarrow*/
                              if (lxr.adv_if('s')) {
                                ent_ref_len = 15; /*leftrightarrows*/
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('h')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('p')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('n')) {
                                  if (lxr.adv_if('s')) {
                                    ent_ref_len = 17; /*leftrightharpoons*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('s')) {
                      if (lxr.adv_if('q')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('g')) {
                              if (lxr.adv_if('a')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('r')) {
                                    if (lxr.adv_if('o')) {
                                      if (lxr.adv_if('w')) {
                                        ent_ref_len = 19; /*leftrightsquigarrow*/
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('t')) {
            if (lxr.adv_if('h')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('m')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('s')) {
                              ent_ref_len = 14; /*leftthreetimes*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('g')) {
        ent_ref_len = 3; /*leg*/
      }
      else if (lxr.adv_if('q')) {
        ent_ref_len = 3; /*leq*/
        if (lxr.adv_if('q')) {
          ent_ref_len = 4; /*leqq*/
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*leqslant*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        ent_ref_len = 3; /*les*/
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*lescc*/
          }
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*lesdot*/
              if (lxr.adv_if('o')) {
                ent_ref_len = 7; /*lesdoto*/
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*lesdotor*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*lesg*/
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*lesges*/
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('x')) {
                      ent_ref_len = 10; /*lessapprox*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('d')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*lessdot*/
              }
            }
          }
          else if (lxr.adv_if('e')) {
            if (lxr.adv_if('q')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('r')) {
                    ent_ref_len = 9; /*lesseqgtr*/
                  }
                }
              }
              else if (lxr.adv_if('q')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('r')) {
                      ent_ref_len = 10; /*lesseqqgtr*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('g')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*lessgtr*/
              }
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*lesssim*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*lfisht*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*lfloor*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*lfr*/
      }
    }
    else if (lxr.adv_if('g')) {
      ent_ref_len = 2; /*lg*/
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*lgE*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*lhard*/
          }
          else if (lxr.adv_if('u')) {
            ent_ref_len = 5; /*lharu*/
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*lharul*/
            }
          }
        }
      }
      else if (lxr.adv_if('b')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*lhblk*/
          }
        }
      }
    }
    else if (lxr.adv_if('j')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*ljcy*/
        }
      }
    }
    else if (lxr.adv_if('l')) {
      ent_ref_len = 2; /*ll*/
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*llarr*/
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*llcorner*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*llhard*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*lltri*/
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*lmidot*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*lmoust*/
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('c')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('e')) {
                      ent_ref_len = 10; /*lmoustache*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*lnE*/
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*lnap*/
          if (lxr.adv_if('p')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('x')) {
                  ent_ref_len = 8; /*lnapprox*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*lne*/
        if (lxr.adv_if('q')) {
          ent_ref_len = 4; /*lneq*/
          if (lxr.adv_if('q')) {
            ent_ref_len = 5; /*lneqq*/
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*lnsim*/
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*loang*/
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*loarr*/
          }
        }
      }
      else if (lxr.adv_if('b')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*lobrk*/
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('f')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('r')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('o')) {
                          if (lxr.adv_if('w')) {
                            ent_ref_len = 13; /*longleftarrow*/
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('r')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('h')) {
                          if (lxr.adv_if('t')) {
                            if (lxr.adv_if('a')) {
                              if (lxr.adv_if('r')) {
                                if (lxr.adv_if('r')) {
                                  if (lxr.adv_if('o')) {
                                    if (lxr.adv_if('w')) {
                                      ent_ref_len = 18; /*longleftrightarrow*/
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('m')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('s')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('o')) {
                      ent_ref_len = 10; /*longmapsto*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('h')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              ent_ref_len = 14; /*longrightarrow*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('f')) {
                          if (lxr.adv_if('t')) {
                            ent_ref_len = 13; /*looparrowleft*/
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('r')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('g')) {
                          if (lxr.adv_if('h')) {
                            if (lxr.adv_if('t')) {
                              ent_ref_len = 14; /*looparrowright*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*lopar*/
          }
        }
        else if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*lopf*/
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*loplus*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*lotimes*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('w')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*lowast*/
            }
          }
        }
        else if (lxr.adv_if('b')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*lowbar*/
            }
          }
        }
      }
      else if (lxr.adv_if('z')) {
        ent_ref_len = 3; /*loz*/
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('g')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*lozenge*/
              }
            }
          }
        }
        else if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*lozf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*lpar*/
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*lparlt*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*lrarr*/
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*lrcorner*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*lrhar*/
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*lrhard*/
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        ent_ref_len = 3; /*lrm*/
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*lrtri*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('q')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('o')) {
              ent_ref_len = 6; /*lsaquo*/
            }
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*lscr*/
        }
      }
      else if (lxr.adv_if('h')) {
        ent_ref_len = 3; /*lsh*/
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          ent_ref_len = 4; /*lsim*/
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*lsime*/
          }
          else if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*lsimg*/
          }
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('b')) {
          ent_ref_len = 4; /*lsqb*/
        }
        else if (lxr.adv_if('u')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*lsquo*/
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*lsquor*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*lstrok*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      ent_ref_len = 2; /*lt*/
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('c')) {
          ent_ref_len = 4; /*ltcc*/
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*ltcir*/
          }
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*ltdot*/
          }
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*lthree*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*ltimes*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*ltlarr*/
            }
          }
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*ltquest*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('P')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*ltrPar*/
            }
          }
        }
        else if (lxr.adv_if('i')) {
          ent_ref_len = 4; /*ltri*/
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*ltrie*/
          }
          else if (lxr.adv_if('f')) {
            ent_ref_len = 5; /*ltrif*/
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*lurdshar*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('u')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*luruhar*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('v')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('q')) {
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*lvertneqq*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('E')) {
          ent_ref_len = 4; /*lvnE*/
        }
      }
    }
  }
  else if (lxr.adv_if('m')) {
    if (lxr.adv_if('D')) {
      if (lxr.adv_if('D')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*mDDot*/
          }
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*macr*/
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*male*/
        }
        else if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*malt*/
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*maltese*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*map*/
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('o')) {
              ent_ref_len = 6; /*mapsto*/
              if (lxr.adv_if('d')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    if (lxr.adv_if('n')) {
                      ent_ref_len = 10; /*mapstodown*/
                    }
                  }
                }
              }
              else if (lxr.adv_if('l')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('f')) {
                    if (lxr.adv_if('t')) {
                      ent_ref_len = 10; /*mapstoleft*/
                    }
                  }
                }
              }
              else if (lxr.adv_if('u')) {
                if (lxr.adv_if('p')) {
                  ent_ref_len = 8; /*mapstoup*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('k')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*marker*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('a')) {
              ent_ref_len = 6; /*mcomma*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*mcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*mdash*/
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('d')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('e')) {
                            ent_ref_len = 13; /*measuredangle*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*mfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('o')) {
        ent_ref_len = 3; /*mho*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*micro*/
          }
        }
      }
      else if (lxr.adv_if('d')) {
        ent_ref_len = 3; /*mid*/
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*midast*/
            }
          }
        }
        else if (lxr.adv_if('c')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*midcir*/
            }
          }
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*middot*/
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*minus*/
            if (lxr.adv_if('b')) {
              ent_ref_len = 6; /*minusb*/
            }
            else if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*minusd*/
              if (lxr.adv_if('u')) {
                ent_ref_len = 7; /*minusdu*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*mlcp*/
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*mldr*/
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*mnplus*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*models*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*mopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      ent_ref_len = 2; /*mp*/
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*mscr*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*mstpos*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      ent_ref_len = 2; /*mu*/
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('p')) {
                  ent_ref_len = 8; /*multimap*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*mumap*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('n')) {
    if (lxr.adv_if('G')) {
      if (lxr.adv_if('g')) {
        ent_ref_len = 3; /*nGg*/
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*nGt*/
        if (lxr.adv_if('v')) {
          ent_ref_len = 4; /*nGtv*/
        }
      }
    }
    else if (lxr.adv_if('L')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('f')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      ent_ref_len = 10; /*nLeftarrow*/
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('r')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                ent_ref_len = 15; /*nLeftrightarrow*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        ent_ref_len = 3; /*nLl*/
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*nLt*/
        if (lxr.adv_if('v')) {
          ent_ref_len = 4; /*nLtv*/
        }
      }
    }
    else if (lxr.adv_if('R')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        ent_ref_len = 11; /*nRightarrow*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('V')) {
      if (lxr.adv_if('D')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*nVDash*/
            }
          }
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*nVdash*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('b')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*nabla*/
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*nacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*nang*/
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*nap*/
        if (lxr.adv_if('E')) {
          ent_ref_len = 4; /*napE*/
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*napid*/
          }
        }
        else if (lxr.adv_if('o')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*napos*/
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('x')) {
                ent_ref_len = 7; /*napprox*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*natur*/
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('l')) {
                ent_ref_len = 7; /*natural*/
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*naturals*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('s')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*nbsp*/
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*nbump*/
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*nbumpe*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*ncap*/
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*ncaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*ncedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*ncong*/
            if (lxr.adv_if('d')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*ncongdot*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*ncup*/
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*ncy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*ndash*/
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      ent_ref_len = 2; /*ne*/
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*neArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*nearhk*/
            }
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nearr*/
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                ent_ref_len = 7; /*nearrow*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*nedot*/
          }
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('v')) {
              ent_ref_len = 6; /*nequiv*/
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*nesear*/
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*nesim*/
          }
        }
      }
      else if (lxr.adv_if('x')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*nexist*/
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*nexists*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*nfr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*ngE*/
      }
      else if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*nge*/
        if (lxr.adv_if('q')) {
          ent_ref_len = 4; /*ngeq*/
          if (lxr.adv_if('q')) {
            ent_ref_len = 5; /*ngeqq*/
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*ngeqslant*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          ent_ref_len = 4; /*nges*/
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*ngsim*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*ngt*/
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*ngtr*/
        }
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nhArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nharr*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nhpar*/
          }
        }
      }
    }
    else if (lxr.adv_if('i')) {
      ent_ref_len = 2; /*ni*/
      if (lxr.adv_if('s')) {
        ent_ref_len = 3; /*nis*/
        if (lxr.adv_if('d')) {
          ent_ref_len = 4; /*nisd*/
        }
      }
      else if (lxr.adv_if('v')) {
        ent_ref_len = 3; /*niv*/
      }
    }
    else if (lxr.adv_if('j')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*njcy*/
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nlArr*/
          }
        }
      }
      else if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*nlE*/
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nlarr*/
          }
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*nldr*/
        }
      }
      else if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*nle*/
        if (lxr.adv_if('f')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      ent_ref_len = 10; /*nleftarrow*/
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('r')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                ent_ref_len = 15; /*nleftrightarrow*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('q')) {
          ent_ref_len = 4; /*nleq*/
          if (lxr.adv_if('q')) {
            ent_ref_len = 5; /*nleqq*/
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*nleqslant*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          ent_ref_len = 4; /*nles*/
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*nless*/
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*nlsim*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*nlt*/
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*nltri*/
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*nltrie*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('d')) {
          ent_ref_len = 4; /*nmid*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*nopf*/
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*not*/
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*notin*/
            if (lxr.adv_if('E')) {
              ent_ref_len = 6; /*notinE*/
            }
            else if (lxr.adv_if('d')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*notindot*/
                }
              }
            }
            else if (lxr.adv_if('v')) {
              if (lxr.adv_if('a')) {
                ent_ref_len = 7; /*notinva*/
              }
              else if (lxr.adv_if('b')) {
                ent_ref_len = 7; /*notinvb*/
              }
              else if (lxr.adv_if('c')) {
                ent_ref_len = 7; /*notinvc*/
              }
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*notni*/
            if (lxr.adv_if('v')) {
              if (lxr.adv_if('a')) {
                ent_ref_len = 7; /*notniva*/
              }
              else if (lxr.adv_if('b')) {
                ent_ref_len = 7; /*notnivb*/
              }
              else if (lxr.adv_if('c')) {
                ent_ref_len = 7; /*notnivc*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*npar*/
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('l')) {
                    ent_ref_len = 9; /*nparallel*/
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*nparsl*/
            }
          }
          else if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*npart*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*npolint*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*npr*/
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*nprcue*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*npre*/
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*nprec*/
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('q')) {
                ent_ref_len = 7; /*npreceq*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nrArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nrarr*/
            if (lxr.adv_if('c')) {
              ent_ref_len = 6; /*nrarrc*/
            }
            else if (lxr.adv_if('w')) {
              ent_ref_len = 6; /*nrarrw*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        ent_ref_len = 11; /*nrightarrow*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*nrtri*/
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*nrtrie*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        ent_ref_len = 3; /*nsc*/
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*nsccue*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*nsce*/
        }
        else if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*nscr*/
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('m')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('d')) {
                    ent_ref_len = 9; /*nshortmid*/
                  }
                }
              }
              else if (lxr.adv_if('p')) {
                if (lxr.adv_if('a')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('l')) {
                              ent_ref_len = 14; /*nshortparallel*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          ent_ref_len = 4; /*nsim*/
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*nsime*/
            if (lxr.adv_if('q')) {
              ent_ref_len = 6; /*nsimeq*/
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*nsmid*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nspar*/
          }
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('b')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*nsqsube*/
              }
            }
            else if (lxr.adv_if('p')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*nsqsupe*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('b')) {
          ent_ref_len = 4; /*nsub*/
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*nsubE*/
          }
          else if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*nsube*/
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*nsubset*/
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*nsubseteq*/
                    if (lxr.adv_if('q')) {
                      ent_ref_len = 10; /*nsubseteqq*/
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('c')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*nsucc*/
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('q')) {
                ent_ref_len = 7; /*nsucceq*/
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*nsup*/
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*nsupE*/
          }
          else if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*nsupe*/
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*nsupset*/
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*nsupseteq*/
                    if (lxr.adv_if('q')) {
                      ent_ref_len = 10; /*nsupseteqq*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*ntgl*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*ntilde*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*ntlg*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('g')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('f')) {
                          if (lxr.adv_if('t')) {
                            ent_ref_len = 13; /*ntriangleleft*/
                            if (lxr.adv_if('e')) {
                              if (lxr.adv_if('q')) {
                                ent_ref_len = 15; /*ntrianglelefteq*/
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('r')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('g')) {
                          if (lxr.adv_if('h')) {
                            if (lxr.adv_if('t')) {
                              ent_ref_len = 14; /*ntriangleright*/
                              if (lxr.adv_if('e')) {
                                if (lxr.adv_if('q')) {
                                  ent_ref_len = 16; /*ntrianglerighteq*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      ent_ref_len = 2; /*nu*/
      if (lxr.adv_if('m')) {
        ent_ref_len = 3; /*num*/
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              ent_ref_len = 6; /*numero*/
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*numsp*/
          }
        }
      }
    }
    else if (lxr.adv_if('v')) {
      if (lxr.adv_if('D')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*nvDash*/
            }
          }
        }
      }
      else if (lxr.adv_if('H')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*nvHarr*/
            }
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*nvap*/
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*nvdash*/
            }
          }
        }
      }
      else if (lxr.adv_if('g')) {
        if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*nvge*/
        }
        else if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*nvgt*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('f')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*nvinfin*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('A')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*nvlArr*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*nvle*/
        }
        else if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*nvlt*/
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*nvltrie*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('A')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*nvrArr*/
            }
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*nvrtrie*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*nvsim*/
          }
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nwArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*nwarhk*/
            }
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*nwarr*/
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                ent_ref_len = 7; /*nwarrow*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*nwnear*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('o')) {
    if (lxr.adv_if('S')) {
      ent_ref_len = 2; /*oS*/
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*oacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*oast*/
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*ocir*/
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*ocirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*ocy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*odash*/
          }
        }
      }
      else if (lxr.adv_if('b')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('c')) {
              ent_ref_len = 6; /*odblac*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('v')) {
          ent_ref_len = 4; /*odiv*/
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*odot*/
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*odsold*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*oelig*/
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*ofcir*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*ofr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('n')) {
          ent_ref_len = 4; /*ogon*/
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*ograve*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*ogt*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('b')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*ohbar*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        ent_ref_len = 3; /*ohm*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('n')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*oint*/
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*olarr*/
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*olcir*/
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*olcross*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*oline*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*olt*/
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*omacr*/
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*omega*/
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*omicron*/
              }
            }
          }
        }
        else if (lxr.adv_if('d')) {
          ent_ref_len = 4; /*omid*/
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*ominus*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*oopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*opar*/
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*operp*/
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*oplus*/
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      ent_ref_len = 2; /*or*/
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*orarr*/
          }
        }
      }
      else if (lxr.adv_if('d')) {
        ent_ref_len = 3; /*ord*/
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*order*/
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('f')) {
                ent_ref_len = 7; /*orderof*/
              }
            }
          }
        }
        else if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*ordf*/
        }
        else if (lxr.adv_if('m')) {
          ent_ref_len = 4; /*ordm*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('f')) {
              ent_ref_len = 6; /*origof*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*oror*/
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*orslope*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('v')) {
        ent_ref_len = 3; /*orv*/
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*oscr*/
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*oslash*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*osol*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*otilde*/
            }
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*otimes*/
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*otimesas*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*ouml*/
        }
      }
    }
    else if (lxr.adv_if('v')) {
      if (lxr.adv_if('b')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*ovbar*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('p')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*par*/
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*para*/
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('l')) {
                  ent_ref_len = 8; /*parallel*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              ent_ref_len = 6; /*parsim*/
            }
          }
          else if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*parsl*/
          }
        }
        else if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*part*/
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*pcy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*percnt*/
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*period*/
            }
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*permil*/
            }
          }
        }
        else if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*perp*/
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('k')) {
                ent_ref_len = 7; /*pertenk*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*pfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('i')) {
        ent_ref_len = 3; /*phi*/
        if (lxr.adv_if('v')) {
          ent_ref_len = 4; /*phiv*/
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*phmmat*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*phone*/
          }
        }
      }
    }
    else if (lxr.adv_if('i')) {
      ent_ref_len = 2; /*pi*/
      if (lxr.adv_if('t')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('f')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('k')) {
                    ent_ref_len = 9; /*pitchfork*/
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('v')) {
        ent_ref_len = 3; /*piv*/
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*planck*/
              if (lxr.adv_if('h')) {
                ent_ref_len = 7; /*planckh*/
              }
            }
          }
          else if (lxr.adv_if('k')) {
            if (lxr.adv_if('v')) {
              ent_ref_len = 6; /*plankv*/
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('s')) {
          ent_ref_len = 4; /*plus*/
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('c')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*plusacir*/
                }
              }
            }
          }
          else if (lxr.adv_if('b')) {
            ent_ref_len = 5; /*plusb*/
          }
          else if (lxr.adv_if('c')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*pluscir*/
              }
            }
          }
          else if (lxr.adv_if('d')) {
            if (lxr.adv_if('o')) {
              ent_ref_len = 6; /*plusdo*/
            }
            else if (lxr.adv_if('u')) {
              ent_ref_len = 6; /*plusdu*/
            }
          }
          else if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*pluse*/
          }
          else if (lxr.adv_if('m')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*plusmn*/
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*plussim*/
              }
            }
          }
          else if (lxr.adv_if('t')) {
            if (lxr.adv_if('w')) {
              if (lxr.adv_if('o')) {
                ent_ref_len = 7; /*plustwo*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      ent_ref_len = 2; /*pm*/
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*pointint*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*popf*/
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*pound*/
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      ent_ref_len = 2; /*pr*/
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*prE*/
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*prap*/
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*prcue*/
          }
        }
      }
      else if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*pre*/
        if (lxr.adv_if('c')) {
          ent_ref_len = 4; /*prec*/
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('x')) {
                      ent_ref_len = 10; /*precapprox*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('c')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('y')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('q')) {
                        ent_ref_len = 11; /*preccurlyeq*/
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('e')) {
            if (lxr.adv_if('q')) {
              ent_ref_len = 6; /*preceq*/
            }
          }
          else if (lxr.adv_if('n')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('x')) {
                        ent_ref_len = 11; /*precnapprox*/
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('e')) {
              if (lxr.adv_if('q')) {
                if (lxr.adv_if('q')) {
                  ent_ref_len = 8; /*precneqq*/
                }
              }
            }
            else if (lxr.adv_if('s')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('m')) {
                  ent_ref_len = 8; /*precnsim*/
                }
              }
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*precsim*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*prime*/
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*primes*/
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('E')) {
          ent_ref_len = 4; /*prnE*/
        }
        else if (lxr.adv_if('a')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*prnap*/
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              ent_ref_len = 6; /*prnsim*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('d')) {
          ent_ref_len = 4; /*prod*/
        }
        else if (lxr.adv_if('f')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*profalar*/
                }
              }
            }
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*profline*/
                }
              }
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('f')) {
                  ent_ref_len = 8; /*profsurf*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*prop*/
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('o')) {
              ent_ref_len = 6; /*propto*/
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*prsim*/
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*prurel*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*pscr*/
        }
      }
      else if (lxr.adv_if('i')) {
        ent_ref_len = 3; /*psi*/
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('n')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*puncsp*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('q')) {
    if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*qfr*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('n')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*qint*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*qopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*qprime*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*qscr*/
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('s')) {
                        ent_ref_len = 11; /*quaternions*/
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*quatint*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*quest*/
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('q')) {
                ent_ref_len = 7; /*questeq*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*quot*/
        }
      }
    }
  }
  else if (lxr.adv_if('r')) {
    if (lxr.adv_if('A')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*rAarr*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*rArr*/
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*rAtail*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('B')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*rBarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('H')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*rHar*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*race*/
        }
        else if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*racute*/
            }
          }
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*radic*/
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('p')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('y')) {
                if (lxr.adv_if('v')) {
                  ent_ref_len = 8; /*raemptyv*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*rang*/
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*rangd*/
          }
          else if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*range*/
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*rangle*/
            }
          }
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*raquo*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*rarr*/
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*rarrap*/
            }
          }
          else if (lxr.adv_if('b')) {
            ent_ref_len = 5; /*rarrb*/
            if (lxr.adv_if('f')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*rarrbfs*/
              }
            }
          }
          else if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*rarrc*/
          }
          else if (lxr.adv_if('f')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*rarrfs*/
            }
          }
          else if (lxr.adv_if('h')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*rarrhk*/
            }
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*rarrlp*/
            }
          }
          else if (lxr.adv_if('p')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*rarrpl*/
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*rarrsim*/
              }
            }
          }
          else if (lxr.adv_if('t')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*rarrtl*/
            }
          }
          else if (lxr.adv_if('w')) {
            ent_ref_len = 5; /*rarrw*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*ratail*/
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*ratio*/
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('s')) {
                    ent_ref_len = 9; /*rationals*/
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*rbarr*/
          }
        }
      }
      else if (lxr.adv_if('b')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*rbbrk*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*rbrace*/
            }
            else if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*rbrack*/
            }
          }
        }
        else if (lxr.adv_if('k')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*rbrke*/
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('d')) {
                ent_ref_len = 7; /*rbrksld*/
              }
              else if (lxr.adv_if('u')) {
                ent_ref_len = 7; /*rbrkslu*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*rcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*rcedil*/
            }
          }
        }
        else if (lxr.adv_if('i')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*rceil*/
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('b')) {
          ent_ref_len = 4; /*rcub*/
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*rcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*rdca*/
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*rdldhar*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*rdquo*/
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*rdquor*/
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('h')) {
          ent_ref_len = 4; /*rdsh*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*real*/
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*realine*/
              }
            }
          }
          else if (lxr.adv_if('p')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*realpart*/
                }
              }
            }
          }
          else if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*reals*/
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*rect*/
        }
      }
      else if (lxr.adv_if('g')) {
        ent_ref_len = 3; /*reg*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*rfisht*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*rfloor*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*rfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*rhard*/
          }
          else if (lxr.adv_if('u')) {
            ent_ref_len = 5; /*rharu*/
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*rharul*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        ent_ref_len = 3; /*rho*/
        if (lxr.adv_if('v')) {
          ent_ref_len = 4; /*rhov*/
        }
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('h')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('w')) {
                      ent_ref_len = 10; /*rightarrow*/
                      if (lxr.adv_if('t')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('l')) {
                              ent_ref_len = 14; /*rightarrowtail*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('h')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('p')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('o')) {
                        if (lxr.adv_if('n')) {
                          if (lxr.adv_if('d')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                if (lxr.adv_if('n')) {
                                  ent_ref_len = 16; /*rightharpoondown*/
                                }
                              }
                            }
                          }
                          else if (lxr.adv_if('u')) {
                            if (lxr.adv_if('p')) {
                              ent_ref_len = 14; /*rightharpoonup*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('l')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('f')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('a')) {
                      if (lxr.adv_if('r')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('o')) {
                            if (lxr.adv_if('w')) {
                              if (lxr.adv_if('s')) {
                                ent_ref_len = 15; /*rightleftarrows*/
                              }
                            }
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('h')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('p')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('n')) {
                                  if (lxr.adv_if('s')) {
                                    ent_ref_len = 17; /*rightleftharpoons*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('r')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('g')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('t')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                if (lxr.adv_if('s')) {
                                  ent_ref_len = 16; /*rightrightarrows*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('s')) {
              if (lxr.adv_if('q')) {
                if (lxr.adv_if('u')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('g')) {
                      if (lxr.adv_if('a')) {
                        if (lxr.adv_if('r')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('w')) {
                                ent_ref_len = 15; /*rightsquigarrow*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('t')) {
              if (lxr.adv_if('h')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('t')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('m')) {
                            if (lxr.adv_if('e')) {
                              if (lxr.adv_if('s')) {
                                ent_ref_len = 15; /*rightthreetimes*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*ring*/
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('g')) {
              if (lxr.adv_if('d')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('s')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('q')) {
                          ent_ref_len = 12; /*risingdotseq*/
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*rlarr*/
          }
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*rlhar*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        ent_ref_len = 3; /*rlm*/
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*rmoust*/
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('c')) {
                  if (lxr.adv_if('h')) {
                    if (lxr.adv_if('e')) {
                      ent_ref_len = 10; /*rmoustache*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('m')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('d')) {
            ent_ref_len = 5; /*rnmid*/
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*roang*/
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*roarr*/
          }
        }
      }
      else if (lxr.adv_if('b')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*robrk*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*ropar*/
          }
        }
        else if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*ropf*/
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*roplus*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*rotimes*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*rpar*/
          if (lxr.adv_if('g')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*rpargt*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*rppolint*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*rrarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('q')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('o')) {
              ent_ref_len = 6; /*rsaquo*/
            }
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*rscr*/
        }
      }
      else if (lxr.adv_if('h')) {
        ent_ref_len = 3; /*rsh*/
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('b')) {
          ent_ref_len = 4; /*rsqb*/
        }
        else if (lxr.adv_if('u')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*rsquo*/
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*rsquor*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('h')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*rthree*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*rtimes*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('i')) {
          ent_ref_len = 4; /*rtri*/
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*rtrie*/
          }
          else if (lxr.adv_if('f')) {
            ent_ref_len = 5; /*rtrif*/
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('i')) {
                  ent_ref_len = 8; /*rtriltri*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*ruluhar*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('x')) {
      ent_ref_len = 2; /*rx*/
    }
  }
  else if (lxr.adv_if('s')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*sacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('q')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('o')) {
            ent_ref_len = 5; /*sbquo*/
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      ent_ref_len = 2; /*sc*/
      if (lxr.adv_if('E')) {
        ent_ref_len = 3; /*scE*/
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*scap*/
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*scaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*sccue*/
          }
        }
      }
      else if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*sce*/
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*scedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*scirc*/
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('E')) {
          ent_ref_len = 4; /*scnE*/
        }
        else if (lxr.adv_if('a')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*scnap*/
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              ent_ref_len = 6; /*scnsim*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('n')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*scpolint*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            ent_ref_len = 5; /*scsim*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*scy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*sdot*/
          if (lxr.adv_if('b')) {
            ent_ref_len = 5; /*sdotb*/
          }
          else if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*sdote*/
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*seArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*searhk*/
            }
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*searr*/
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                ent_ref_len = 7; /*searrow*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*sect*/
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('i')) {
          ent_ref_len = 4; /*semi*/
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('w')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*seswar*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*setminus*/
                }
              }
            }
          }
          else if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*setmn*/
          }
        }
      }
      else if (lxr.adv_if('x')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*sext*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*sfr*/
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('w')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*sfrown*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*sharp*/
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('h')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*shchcy*/
            }
          }
        }
        else if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*shcy*/
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('m')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('d')) {
                  ent_ref_len = 8; /*shortmid*/
                }
              }
            }
            else if (lxr.adv_if('p')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('a')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('l')) {
                        if (lxr.adv_if('e')) {
                          if (lxr.adv_if('l')) {
                            ent_ref_len = 13; /*shortparallel*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*shy*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('m')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*sigma*/
            if (lxr.adv_if('f')) {
              ent_ref_len = 6; /*sigmaf*/
            }
            else if (lxr.adv_if('v')) {
              ent_ref_len = 6; /*sigmav*/
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        ent_ref_len = 3; /*sim*/
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*simdot*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*sime*/
          if (lxr.adv_if('q')) {
            ent_ref_len = 5; /*simeq*/
          }
        }
        else if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*simg*/
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*simgE*/
          }
        }
        else if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*siml*/
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*simlE*/
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*simne*/
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*simplus*/
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*simrarr*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*slarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('m')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('n')) {
                        if (lxr.adv_if('u')) {
                          if (lxr.adv_if('s')) {
                            ent_ref_len = 13; /*smallsetminus*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*smashp*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('s')) {
                if (lxr.adv_if('l')) {
                  ent_ref_len = 8; /*smeparsl*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('d')) {
          ent_ref_len = 4; /*smid*/
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*smile*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        ent_ref_len = 3; /*smt*/
        if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*smte*/
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*smtes*/
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('f')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('c')) {
            if (lxr.adv_if('y')) {
              ent_ref_len = 6; /*softcy*/
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        ent_ref_len = 3; /*sol*/
        if (lxr.adv_if('b')) {
          ent_ref_len = 4; /*solb*/
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*solbar*/
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*sopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*spades*/
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('t')) {
                    ent_ref_len = 9; /*spadesuit*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*spar*/
        }
      }
    }
    else if (lxr.adv_if('q')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*sqcap*/
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*sqcaps*/
            }
          }
        }
        else if (lxr.adv_if('u')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*sqcup*/
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*sqcups*/
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('b')) {
            ent_ref_len = 5; /*sqsub*/
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*sqsube*/
            }
            else if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*sqsubset*/
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('q')) {
                      ent_ref_len = 10; /*sqsubseteq*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*sqsup*/
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*sqsupe*/
            }
            else if (lxr.adv_if('s')) {
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('t')) {
                  ent_ref_len = 8; /*sqsupset*/
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('q')) {
                      ent_ref_len = 10; /*sqsupseteq*/
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        ent_ref_len = 3; /*squ*/
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*square*/
            }
            else if (lxr.adv_if('f')) {
              ent_ref_len = 6; /*squarf*/
            }
          }
        }
        else if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*squf*/
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*srarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*sscr*/
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*ssetmn*/
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*ssmile*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('f')) {
              ent_ref_len = 6; /*sstarf*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*star*/
          if (lxr.adv_if('f')) {
            ent_ref_len = 5; /*starf*/
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('g')) {
              if (lxr.adv_if('h')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('p')) {
                      if (lxr.adv_if('s')) {
                        if (lxr.adv_if('i')) {
                          if (lxr.adv_if('l')) {
                            if (lxr.adv_if('o')) {
                              if (lxr.adv_if('n')) {
                                ent_ref_len = 15; /*straightepsilon*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('p')) {
                    if (lxr.adv_if('h')) {
                      if (lxr.adv_if('i')) {
                        ent_ref_len = 11; /*straightphi*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*strns*/
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('b')) {
        ent_ref_len = 3; /*sub*/
        if (lxr.adv_if('E')) {
          ent_ref_len = 4; /*subE*/
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*subdot*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*sube*/
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*subedot*/
              }
            }
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*submult*/
              }
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*subnE*/
          }
          else if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*subne*/
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*subplus*/
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*subrarr*/
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*subset*/
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('q')) {
                  ent_ref_len = 8; /*subseteq*/
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*subseteqq*/
                  }
                }
              }
              else if (lxr.adv_if('n')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*subsetneq*/
                    if (lxr.adv_if('q')) {
                      ent_ref_len = 10; /*subsetneqq*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              ent_ref_len = 6; /*subsim*/
            }
          }
          else if (lxr.adv_if('u')) {
            if (lxr.adv_if('b')) {
              ent_ref_len = 6; /*subsub*/
            }
            else if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*subsup*/
            }
          }
        }
      }
      else if (lxr.adv_if('c')) {
        if (lxr.adv_if('c')) {
          ent_ref_len = 4; /*succ*/
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('x')) {
                      ent_ref_len = 10; /*succapprox*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('c')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('y')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('q')) {
                        ent_ref_len = 11; /*succcurlyeq*/
                      }
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('e')) {
            if (lxr.adv_if('q')) {
              ent_ref_len = 6; /*succeq*/
            }
          }
          else if (lxr.adv_if('n')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('x')) {
                        ent_ref_len = 11; /*succnapprox*/
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('e')) {
              if (lxr.adv_if('q')) {
                if (lxr.adv_if('q')) {
                  ent_ref_len = 8; /*succneqq*/
                }
              }
            }
            else if (lxr.adv_if('s')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('m')) {
                  ent_ref_len = 8; /*succnsim*/
                }
              }
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('m')) {
                ent_ref_len = 7; /*succsim*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('m')) {
        ent_ref_len = 3; /*sum*/
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          ent_ref_len = 4; /*sung*/
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*sup*/
        if (lxr.adv_if('1')) {
          ent_ref_len = 4; /*sup1*/
        }
        else if (lxr.adv_if('2')) {
          ent_ref_len = 4; /*sup2*/
        }
        else if (lxr.adv_if('3')) {
          ent_ref_len = 4; /*sup3*/
        }
        else if (lxr.adv_if('E')) {
          ent_ref_len = 4; /*supE*/
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*supdot*/
            }
          }
          else if (lxr.adv_if('s')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('b')) {
                ent_ref_len = 7; /*supdsub*/
              }
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*supe*/
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*supedot*/
              }
            }
          }
        }
        else if (lxr.adv_if('h')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('l')) {
                ent_ref_len = 7; /*suphsol*/
              }
            }
            else if (lxr.adv_if('u')) {
              if (lxr.adv_if('b')) {
                ent_ref_len = 7; /*suphsub*/
              }
            }
          }
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*suplarr*/
              }
            }
          }
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('t')) {
                ent_ref_len = 7; /*supmult*/
              }
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('E')) {
            ent_ref_len = 5; /*supnE*/
          }
          else if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*supne*/
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*supplus*/
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*supset*/
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('q')) {
                  ent_ref_len = 8; /*supseteq*/
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*supseteqq*/
                  }
                }
              }
              else if (lxr.adv_if('n')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*supsetneq*/
                    if (lxr.adv_if('q')) {
                      ent_ref_len = 10; /*supsetneqq*/
                    }
                  }
                }
              }
            }
          }
          else if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              ent_ref_len = 6; /*supsim*/
            }
          }
          else if (lxr.adv_if('u')) {
            if (lxr.adv_if('b')) {
              ent_ref_len = 6; /*supsub*/
            }
            else if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*supsup*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*swArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*swarhk*/
            }
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*swarr*/
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                ent_ref_len = 7; /*swarrow*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('w')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*swnwar*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('z')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*szlig*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('t')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*target*/
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        ent_ref_len = 3; /*tau*/
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('k')) {
          ent_ref_len = 4; /*tbrk*/
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*tcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('l')) {
              ent_ref_len = 6; /*tcedil*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*tcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*tdot*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('c')) {
              ent_ref_len = 6; /*telrec*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*tfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('4')) {
              ent_ref_len = 6; /*there4*/
            }
            else if (lxr.adv_if('f')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('e')) {
                    ent_ref_len = 9; /*therefore*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('a')) {
            ent_ref_len = 5; /*theta*/
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('y')) {
                if (lxr.adv_if('m')) {
                  ent_ref_len = 8; /*thetasym*/
                }
              }
            }
            else if (lxr.adv_if('v')) {
              ent_ref_len = 6; /*thetav*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('k')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('p')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('x')) {
                        ent_ref_len = 11; /*thickapprox*/
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('s')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('m')) {
                  ent_ref_len = 8; /*thicksim*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('s')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*thinsp*/
            }
          }
        }
      }
      else if (lxr.adv_if('k')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*thkap*/
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              ent_ref_len = 6; /*thksim*/
            }
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*thorn*/
          }
        }
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('l')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*tilde*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*times*/
            if (lxr.adv_if('b')) {
              ent_ref_len = 6; /*timesb*/
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*timesbar*/
                }
              }
            }
            else if (lxr.adv_if('d')) {
              ent_ref_len = 6; /*timesd*/
            }
          }
        }
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*tint*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*toea*/
        }
      }
      else if (lxr.adv_if('p')) {
        ent_ref_len = 3; /*top*/
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*topbot*/
            }
          }
        }
        else if (lxr.adv_if('c')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*topcir*/
            }
          }
        }
        else if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*topf*/
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('k')) {
                ent_ref_len = 7; /*topfork*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*tosa*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*tprime*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*trade*/
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('g')) {
              if (lxr.adv_if('l')) {
                if (lxr.adv_if('e')) {
                  ent_ref_len = 8; /*triangle*/
                  if (lxr.adv_if('d')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        if (lxr.adv_if('n')) {
                          ent_ref_len = 12; /*triangledown*/
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('l')) {
                    if (lxr.adv_if('e')) {
                      if (lxr.adv_if('f')) {
                        if (lxr.adv_if('t')) {
                          ent_ref_len = 12; /*triangleleft*/
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('q')) {
                              ent_ref_len = 14; /*trianglelefteq*/
                            }
                          }
                        }
                      }
                    }
                  }
                  else if (lxr.adv_if('q')) {
                    ent_ref_len = 9; /*triangleq*/
                  }
                  else if (lxr.adv_if('r')) {
                    if (lxr.adv_if('i')) {
                      if (lxr.adv_if('g')) {
                        if (lxr.adv_if('h')) {
                          if (lxr.adv_if('t')) {
                            ent_ref_len = 13; /*triangleright*/
                            if (lxr.adv_if('e')) {
                              if (lxr.adv_if('q')) {
                                ent_ref_len = 15; /*trianglerighteq*/
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('d')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*tridot*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*trie*/
        }
        else if (lxr.adv_if('m')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('s')) {
                  ent_ref_len = 8; /*triminus*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('l')) {
            if (lxr.adv_if('u')) {
              if (lxr.adv_if('s')) {
                ent_ref_len = 7; /*triplus*/
              }
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('b')) {
            ent_ref_len = 5; /*trisb*/
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('m')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*tritime*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('z')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('u')) {
                if (lxr.adv_if('m')) {
                  ent_ref_len = 8; /*trpezium*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*tscr*/
        }
        else if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*tscy*/
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*tshcy*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('k')) {
              ent_ref_len = 6; /*tstrok*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('x')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*twixt*/
          }
        }
      }
      else if (lxr.adv_if('o')) {
        if (lxr.adv_if('h')) {
          if (lxr.adv_if('e')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('d')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('e')) {
                    if (lxr.adv_if('f')) {
                      if (lxr.adv_if('t')) {
                        if (lxr.adv_if('a')) {
                          if (lxr.adv_if('r')) {
                            if (lxr.adv_if('r')) {
                              if (lxr.adv_if('o')) {
                                if (lxr.adv_if('w')) {
                                  ent_ref_len = 16; /*twoheadleftarrow*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                else if (lxr.adv_if('r')) {
                  if (lxr.adv_if('i')) {
                    if (lxr.adv_if('g')) {
                      if (lxr.adv_if('h')) {
                        if (lxr.adv_if('t')) {
                          if (lxr.adv_if('a')) {
                            if (lxr.adv_if('r')) {
                              if (lxr.adv_if('r')) {
                                if (lxr.adv_if('o')) {
                                  if (lxr.adv_if('w')) {
                                    ent_ref_len = 17; /*twoheadrightarrow*/
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('u')) {
    if (lxr.adv_if('A')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*uArr*/
        }
      }
    }
    else if (lxr.adv_if('H')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*uHar*/
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*uacute*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*uarr*/
        }
      }
    }
    else if (lxr.adv_if('b')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('y')) {
            ent_ref_len = 5; /*ubrcy*/
          }
        }
        else if (lxr.adv_if('e')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*ubreve*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*ucirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*ucy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*udarr*/
          }
        }
      }
      else if (lxr.adv_if('b')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('c')) {
              ent_ref_len = 6; /*udblac*/
            }
          }
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*udhar*/
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*ufisht*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*ufr*/
      }
    }
    else if (lxr.adv_if('g')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('v')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*ugrave*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('l')) {
            ent_ref_len = 5; /*uharl*/
          }
          else if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*uharr*/
          }
        }
      }
      else if (lxr.adv_if('b')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('k')) {
            ent_ref_len = 5; /*uhblk*/
          }
        }
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*ulcorn*/
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*ulcorner*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*ulcrop*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*ultri*/
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*umacr*/
          }
        }
      }
      else if (lxr.adv_if('l')) {
        ent_ref_len = 3; /*uml*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('n')) {
            ent_ref_len = 5; /*uogon*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*uopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('w')) {
                ent_ref_len = 7; /*uparrow*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('w')) {
            if (lxr.adv_if('n')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('r')) {
                  if (lxr.adv_if('r')) {
                    if (lxr.adv_if('o')) {
                      if (lxr.adv_if('w')) {
                        ent_ref_len = 11; /*updownarrow*/
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('h')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('o')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('f')) {
                          if (lxr.adv_if('t')) {
                            ent_ref_len = 13; /*upharpoonleft*/
                          }
                        }
                      }
                    }
                    else if (lxr.adv_if('r')) {
                      if (lxr.adv_if('i')) {
                        if (lxr.adv_if('g')) {
                          if (lxr.adv_if('h')) {
                            if (lxr.adv_if('t')) {
                              ent_ref_len = 14; /*upharpoonright*/
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('s')) {
            ent_ref_len = 5; /*uplus*/
          }
        }
      }
      else if (lxr.adv_if('s')) {
        if (lxr.adv_if('i')) {
          ent_ref_len = 4; /*upsi*/
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*upsih*/
          }
          else if (lxr.adv_if('l')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('n')) {
                ent_ref_len = 7; /*upsilon*/
              }
            }
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('p')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                if (lxr.adv_if('o')) {
                  if (lxr.adv_if('w')) {
                    if (lxr.adv_if('s')) {
                      ent_ref_len = 10; /*upuparrows*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*urcorn*/
              if (lxr.adv_if('e')) {
                if (lxr.adv_if('r')) {
                  ent_ref_len = 8; /*urcorner*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*urcrop*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            ent_ref_len = 5; /*uring*/
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*urtri*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*uscr*/
        }
      }
    }
    else if (lxr.adv_if('t')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*utdot*/
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('d')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*utilde*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('i')) {
          ent_ref_len = 4; /*utri*/
          if (lxr.adv_if('f')) {
            ent_ref_len = 5; /*utrif*/
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*uuarr*/
          }
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*uuml*/
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('n')) {
          if (lxr.adv_if('g')) {
            if (lxr.adv_if('l')) {
              if (lxr.adv_if('e')) {
                ent_ref_len = 7; /*uwangle*/
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('v')) {
    if (lxr.adv_if('A')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*vArr*/
        }
      }
    }
    else if (lxr.adv_if('B')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*vBar*/
          if (lxr.adv_if('v')) {
            ent_ref_len = 5; /*vBarv*/
          }
        }
      }
    }
    else if (lxr.adv_if('D')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*vDash*/
          }
        }
      }
    }
    else if (lxr.adv_if('a')) {
      if (lxr.adv_if('n')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('t')) {
              ent_ref_len = 6; /*vangrt*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('p')) {
            if (lxr.adv_if('s')) {
              if (lxr.adv_if('i')) {
                if (lxr.adv_if('l')) {
                  if (lxr.adv_if('o')) {
                    if (lxr.adv_if('n')) {
                      ent_ref_len = 10; /*varepsilon*/
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('k')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('p')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('a')) {
                  ent_ref_len = 8; /*varkappa*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('n')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('t')) {
              if (lxr.adv_if('h')) {
                if (lxr.adv_if('i')) {
                  if (lxr.adv_if('n')) {
                    if (lxr.adv_if('g')) {
                      ent_ref_len = 10; /*varnothing*/
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('i')) {
              ent_ref_len = 6; /*varphi*/
            }
          }
          else if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*varpi*/
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('o')) {
              if (lxr.adv_if('p')) {
                if (lxr.adv_if('t')) {
                  if (lxr.adv_if('o')) {
                    ent_ref_len = 9; /*varpropto*/
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*varr*/
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('o')) {
              ent_ref_len = 6; /*varrho*/
            }
          }
        }
        else if (lxr.adv_if('s')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('g')) {
              if (lxr.adv_if('m')) {
                if (lxr.adv_if('a')) {
                  ent_ref_len = 8; /*varsigma*/
                }
              }
            }
          }
          else if (lxr.adv_if('u')) {
            if (lxr.adv_if('b')) {
              if (lxr.adv_if('s')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('q')) {
                          ent_ref_len = 12; /*varsubsetneq*/
                          if (lxr.adv_if('q')) {
                            ent_ref_len = 13; /*varsubsetneqq*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (lxr.adv_if('p')) {
              if (lxr.adv_if('s')) {
                if (lxr.adv_if('e')) {
                  if (lxr.adv_if('t')) {
                    if (lxr.adv_if('n')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('q')) {
                          ent_ref_len = 12; /*varsupsetneq*/
                          if (lxr.adv_if('q')) {
                            ent_ref_len = 13; /*varsupsetneqq*/
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('t')) {
          if (lxr.adv_if('h')) {
            if (lxr.adv_if('e')) {
              if (lxr.adv_if('t')) {
                if (lxr.adv_if('a')) {
                  ent_ref_len = 8; /*vartheta*/
                }
              }
            }
          }
          else if (lxr.adv_if('r')) {
            if (lxr.adv_if('i')) {
              if (lxr.adv_if('a')) {
                if (lxr.adv_if('n')) {
                  if (lxr.adv_if('g')) {
                    if (lxr.adv_if('l')) {
                      if (lxr.adv_if('e')) {
                        if (lxr.adv_if('l')) {
                          if (lxr.adv_if('e')) {
                            if (lxr.adv_if('f')) {
                              if (lxr.adv_if('t')) {
                                ent_ref_len = 15; /*vartriangleleft*/
                              }
                            }
                          }
                        }
                        else if (lxr.adv_if('r')) {
                          if (lxr.adv_if('i')) {
                            if (lxr.adv_if('g')) {
                              if (lxr.adv_if('h')) {
                                if (lxr.adv_if('t')) {
                                  ent_ref_len = 16; /*vartriangleright*/
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*vcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('s')) {
          if (lxr.adv_if('h')) {
            ent_ref_len = 5; /*vdash*/
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('e')) {
        ent_ref_len = 3; /*vee*/
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*veebar*/
            }
          }
        }
        else if (lxr.adv_if('e')) {
          if (lxr.adv_if('q')) {
            ent_ref_len = 5; /*veeeq*/
          }
        }
      }
      else if (lxr.adv_if('l')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('i')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*vellip*/
            }
          }
        }
      }
      else if (lxr.adv_if('r')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*verbar*/
            }
          }
        }
        else if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*vert*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*vfr*/
      }
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*vltri*/
          }
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('s')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('b')) {
            ent_ref_len = 5; /*vnsub*/
          }
          else if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*vnsup*/
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*vopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      if (lxr.adv_if('r')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('p')) {
            ent_ref_len = 5; /*vprop*/
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*vrtri*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*vscr*/
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('E')) {
              ent_ref_len = 6; /*vsubnE*/
            }
            else if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*vsubne*/
            }
          }
        }
        else if (lxr.adv_if('p')) {
          if (lxr.adv_if('n')) {
            if (lxr.adv_if('E')) {
              ent_ref_len = 6; /*vsupnE*/
            }
            else if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*vsupne*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('z')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('g')) {
          if (lxr.adv_if('z')) {
            if (lxr.adv_if('a')) {
              if (lxr.adv_if('g')) {
                ent_ref_len = 7; /*vzigzag*/
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('w')) {
    if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*wcirc*/
          }
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('b')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              ent_ref_len = 6; /*wedbar*/
            }
          }
        }
        else if (lxr.adv_if('g')) {
          if (lxr.adv_if('e')) {
            ent_ref_len = 5; /*wedge*/
            if (lxr.adv_if('q')) {
              ent_ref_len = 6; /*wedgeq*/
            }
          }
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('e')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*weierp*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*wfr*/
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*wopf*/
        }
      }
    }
    else if (lxr.adv_if('p')) {
      ent_ref_len = 2; /*wp*/
    }
    else if (lxr.adv_if('r')) {
      ent_ref_len = 2; /*wr*/
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('a')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('h')) {
              ent_ref_len = 6; /*wreath*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*wscr*/
        }
      }
    }
  }
  else if (lxr.adv_if('x')) {
    if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*xcap*/
        }
      }
      else if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*xcirc*/
          }
        }
      }
      else if (lxr.adv_if('u')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*xcup*/
        }
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*xdtri*/
          }
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*xfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*xhArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*xharr*/
          }
        }
      }
    }
    else if (lxr.adv_if('i')) {
      ent_ref_len = 2; /*xi*/
    }
    else if (lxr.adv_if('l')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*xlArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*xlarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('m')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('p')) {
          ent_ref_len = 4; /*xmap*/
        }
      }
    }
    else if (lxr.adv_if('n')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('s')) {
          ent_ref_len = 4; /*xnis*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('d')) {
        if (lxr.adv_if('o')) {
          if (lxr.adv_if('t')) {
            ent_ref_len = 5; /*xodot*/
          }
        }
      }
      else if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*xopf*/
        }
        else if (lxr.adv_if('l')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*xoplus*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('i')) {
          if (lxr.adv_if('m')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*xotime*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r')) {
      if (lxr.adv_if('A')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*xrArr*/
          }
        }
      }
      else if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('r')) {
            ent_ref_len = 5; /*xrarr*/
          }
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*xscr*/
        }
      }
      else if (lxr.adv_if('q')) {
        if (lxr.adv_if('c')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('p')) {
              ent_ref_len = 6; /*xsqcup*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('l')) {
          if (lxr.adv_if('u')) {
            if (lxr.adv_if('s')) {
              ent_ref_len = 6; /*xuplus*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('i')) {
            ent_ref_len = 5; /*xutri*/
          }
        }
      }
    }
    else if (lxr.adv_if('v')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('e')) {
          ent_ref_len = 4; /*xvee*/
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('d')) {
          if (lxr.adv_if('g')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*xwedge*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('y')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*yacute*/
            }
          }
        }
        else if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*yacy*/
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('i')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('c')) {
            ent_ref_len = 5; /*ycirc*/
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*ycy*/
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('n')) {
        ent_ref_len = 3; /*yen*/
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*yfr*/
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*yicy*/
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*yopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*yscr*/
        }
      }
    }
    else if (lxr.adv_if('u')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*yucy*/
        }
      }
      else if (lxr.adv_if('m')) {
        if (lxr.adv_if('l')) {
          ent_ref_len = 4; /*yuml*/
        }
      }
    }
  }
  else if (lxr.adv_if('z')) {
    if (lxr.adv_if('a')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('u')) {
          if (lxr.adv_if('t')) {
            if (lxr.adv_if('e')) {
              ent_ref_len = 6; /*zacute*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('c')) {
      if (lxr.adv_if('a')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('o')) {
            if (lxr.adv_if('n')) {
              ent_ref_len = 6; /*zcaron*/
            }
          }
        }
      }
      else if (lxr.adv_if('y')) {
        ent_ref_len = 3; /*zcy*/
      }
    }
    else if (lxr.adv_if('d')) {
      if (lxr.adv_if('o')) {
        if (lxr.adv_if('t')) {
          ent_ref_len = 4; /*zdot*/
        }
      }
    }
    else if (lxr.adv_if('e')) {
      if (lxr.adv_if('e')) {
        if (lxr.adv_if('t')) {
          if (lxr.adv_if('r')) {
            if (lxr.adv_if('f')) {
              ent_ref_len = 6; /*zeetrf*/
            }
          }
        }
      }
      else if (lxr.adv_if('t')) {
        if (lxr.adv_if('a')) {
          ent_ref_len = 4; /*zeta*/
        }
      }
    }
    else if (lxr.adv_if('f')) {
      if (lxr.adv_if('r')) {
        ent_ref_len = 3; /*zfr*/
      }
    }
    else if (lxr.adv_if('h')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('y')) {
          ent_ref_len = 4; /*zhcy*/
        }
      }
    }
    else if (lxr.adv_if('i')) {
      if (lxr.adv_if('g')) {
        if (lxr.adv_if('r')) {
          if (lxr.adv_if('a')) {
            if (lxr.adv_if('r')) {
              if (lxr.adv_if('r')) {
                ent_ref_len = 7; /*zigrarr*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o')) {
      if (lxr.adv_if('p')) {
        if (lxr.adv_if('f')) {
          ent_ref_len = 4; /*zopf*/
        }
      }
    }
    else if (lxr.adv_if('s')) {
      if (lxr.adv_if('c')) {
        if (lxr.adv_if('r')) {
          ent_ref_len = 4; /*zscr*/
        }
      }
    }
    else if (lxr.adv_if('w')) {
      if (lxr.adv_if('j')) {
        ent_ref_len = 3; /*zwj*/
      }
      else if (lxr.adv_if('n')) {
        if (lxr.adv_if('j')) {
          ent_ref_len = 4; /*zwnj*/
        }
      }
    }
  }
}

}
