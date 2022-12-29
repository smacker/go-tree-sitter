#include "./block_scan_util.generated.h"

namespace tree_sitter_markdown {

void adv_blk_htm_tag_nam(Lexer &lxr, LexedLength &scr_len, LexedLength &div_len) {
  if (lxr.adv_if('s') || lxr.adv_if('S')) {
    if (lxr.adv_if('c') || lxr.adv_if('C')) {
      if (lxr.adv_if('r') || lxr.adv_if('R')) {
        if (lxr.adv_if('i') || lxr.adv_if('I')) {
          if (lxr.adv_if('p') || lxr.adv_if('P')) {
            if (lxr.adv_if('t') || lxr.adv_if('T')) {
              scr_len = 6; /*script*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('t') || lxr.adv_if('T')) {
      if (lxr.adv_if('y') || lxr.adv_if('Y')) {
        if (lxr.adv_if('l') || lxr.adv_if('L')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            scr_len = 5; /*style*/
          }
        }
      }
    }
    else if (lxr.adv_if('e') || lxr.adv_if('E')) {
      if (lxr.adv_if('c') || lxr.adv_if('C')) {
        if (lxr.adv_if('t') || lxr.adv_if('T')) {
          if (lxr.adv_if('i') || lxr.adv_if('I')) {
            if (lxr.adv_if('o') || lxr.adv_if('O')) {
              if (lxr.adv_if('n') || lxr.adv_if('N')) {
                div_len = 7; /*section*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o') || lxr.adv_if('O')) {
      if (lxr.adv_if('u') || lxr.adv_if('U')) {
        if (lxr.adv_if('r') || lxr.adv_if('R')) {
          if (lxr.adv_if('c') || lxr.adv_if('C')) {
            if (lxr.adv_if('e') || lxr.adv_if('E')) {
              div_len = 6; /*source*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('u') || lxr.adv_if('U')) {
      if (lxr.adv_if('m') || lxr.adv_if('M')) {
        if (lxr.adv_if('m') || lxr.adv_if('M')) {
          if (lxr.adv_if('a') || lxr.adv_if('A')) {
            if (lxr.adv_if('r') || lxr.adv_if('R')) {
              if (lxr.adv_if('y') || lxr.adv_if('Y')) {
                div_len = 7; /*summary*/
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('p') || lxr.adv_if('P')) {
    div_len = 1; /*p*/
    if (lxr.adv_if('r') || lxr.adv_if('R')) {
      if (lxr.adv_if('e') || lxr.adv_if('E')) {
        scr_len = 3; /*pre*/
      }
    }
    else if (lxr.adv_if('a') || lxr.adv_if('A')) {
      if (lxr.adv_if('r') || lxr.adv_if('R')) {
        if (lxr.adv_if('a') || lxr.adv_if('A')) {
          if (lxr.adv_if('m') || lxr.adv_if('M')) {
            div_len = 5; /*param*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('a') || lxr.adv_if('A')) {
    if (lxr.adv_if('d') || lxr.adv_if('D')) {
      if (lxr.adv_if('d') || lxr.adv_if('D')) {
        if (lxr.adv_if('r') || lxr.adv_if('R')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            if (lxr.adv_if('s') || lxr.adv_if('S')) {
              if (lxr.adv_if('s') || lxr.adv_if('S')) {
                div_len = 7; /*address*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r') || lxr.adv_if('R')) {
      if (lxr.adv_if('t') || lxr.adv_if('T')) {
        if (lxr.adv_if('i') || lxr.adv_if('I')) {
          if (lxr.adv_if('c') || lxr.adv_if('C')) {
            if (lxr.adv_if('l') || lxr.adv_if('L')) {
              if (lxr.adv_if('e') || lxr.adv_if('E')) {
                div_len = 7; /*article*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('s') || lxr.adv_if('S')) {
      if (lxr.adv_if('i') || lxr.adv_if('I')) {
        if (lxr.adv_if('d') || lxr.adv_if('D')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            div_len = 5; /*aside*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('b') || lxr.adv_if('B')) {
    if (lxr.adv_if('a') || lxr.adv_if('A')) {
      if (lxr.adv_if('s') || lxr.adv_if('S')) {
        if (lxr.adv_if('e') || lxr.adv_if('E')) {
          div_len = 4; /*base*/
          if (lxr.adv_if('f') || lxr.adv_if('F')) {
            if (lxr.adv_if('o') || lxr.adv_if('O')) {
              if (lxr.adv_if('n') || lxr.adv_if('N')) {
                if (lxr.adv_if('t') || lxr.adv_if('T')) {
                  div_len = 8; /*basefont*/
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('l') || lxr.adv_if('L')) {
      if (lxr.adv_if('o') || lxr.adv_if('O')) {
        if (lxr.adv_if('c') || lxr.adv_if('C')) {
          if (lxr.adv_if('k') || lxr.adv_if('K')) {
            if (lxr.adv_if('q') || lxr.adv_if('Q')) {
              if (lxr.adv_if('u') || lxr.adv_if('U')) {
                if (lxr.adv_if('o') || lxr.adv_if('O')) {
                  if (lxr.adv_if('t') || lxr.adv_if('T')) {
                    if (lxr.adv_if('e') || lxr.adv_if('E')) {
                      div_len = 10; /*blockquote*/
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o') || lxr.adv_if('O')) {
      if (lxr.adv_if('d') || lxr.adv_if('D')) {
        if (lxr.adv_if('y') || lxr.adv_if('Y')) {
          div_len = 4; /*body*/
        }
      }
    }
  }
  else if (lxr.adv_if('c') || lxr.adv_if('C')) {
    if (lxr.adv_if('a') || lxr.adv_if('A')) {
      if (lxr.adv_if('p') || lxr.adv_if('P')) {
        if (lxr.adv_if('t') || lxr.adv_if('T')) {
          if (lxr.adv_if('i') || lxr.adv_if('I')) {
            if (lxr.adv_if('o') || lxr.adv_if('O')) {
              if (lxr.adv_if('n') || lxr.adv_if('N')) {
                div_len = 7; /*caption*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('e') || lxr.adv_if('E')) {
      if (lxr.adv_if('n') || lxr.adv_if('N')) {
        if (lxr.adv_if('t') || lxr.adv_if('T')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            if (lxr.adv_if('r') || lxr.adv_if('R')) {
              div_len = 6; /*center*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o') || lxr.adv_if('O')) {
      if (lxr.adv_if('l') || lxr.adv_if('L')) {
        div_len = 3; /*col*/
        if (lxr.adv_if('g') || lxr.adv_if('G')) {
          if (lxr.adv_if('r') || lxr.adv_if('R')) {
            if (lxr.adv_if('o') || lxr.adv_if('O')) {
              if (lxr.adv_if('u') || lxr.adv_if('U')) {
                if (lxr.adv_if('p') || lxr.adv_if('P')) {
                  div_len = 8; /*colgroup*/
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('d') || lxr.adv_if('D')) {
    if (lxr.adv_if('d') || lxr.adv_if('D')) {
      div_len = 2; /*dd*/
    }
    else if (lxr.adv_if('e') || lxr.adv_if('E')) {
      if (lxr.adv_if('t') || lxr.adv_if('T')) {
        if (lxr.adv_if('a') || lxr.adv_if('A')) {
          if (lxr.adv_if('i') || lxr.adv_if('I')) {
            if (lxr.adv_if('l') || lxr.adv_if('L')) {
              if (lxr.adv_if('s') || lxr.adv_if('S')) {
                div_len = 7; /*details*/
              }
            }
          }
        }
      }
    }
    else if (lxr.adv_if('i') || lxr.adv_if('I')) {
      if (lxr.adv_if('a') || lxr.adv_if('A')) {
        if (lxr.adv_if('l') || lxr.adv_if('L')) {
          if (lxr.adv_if('o') || lxr.adv_if('O')) {
            if (lxr.adv_if('g') || lxr.adv_if('G')) {
              div_len = 6; /*dialog*/
            }
          }
        }
      }
      else if (lxr.adv_if('r') || lxr.adv_if('R')) {
        div_len = 3; /*dir*/
      }
      else if (lxr.adv_if('v') || lxr.adv_if('V')) {
        div_len = 3; /*div*/
      }
    }
    else if (lxr.adv_if('l') || lxr.adv_if('L')) {
      div_len = 2; /*dl*/
    }
    else if (lxr.adv_if('t') || lxr.adv_if('T')) {
      div_len = 2; /*dt*/
    }
  }
  else if (lxr.adv_if('f') || lxr.adv_if('F')) {
    if (lxr.adv_if('i') || lxr.adv_if('I')) {
      if (lxr.adv_if('e') || lxr.adv_if('E')) {
        if (lxr.adv_if('l') || lxr.adv_if('L')) {
          if (lxr.adv_if('d') || lxr.adv_if('D')) {
            if (lxr.adv_if('s') || lxr.adv_if('S')) {
              if (lxr.adv_if('e') || lxr.adv_if('E')) {
                if (lxr.adv_if('t') || lxr.adv_if('T')) {
                  div_len = 8; /*fieldset*/
                }
              }
            }
          }
        }
      }
      else if (lxr.adv_if('g') || lxr.adv_if('G')) {
        if (lxr.adv_if('c') || lxr.adv_if('C')) {
          if (lxr.adv_if('a') || lxr.adv_if('A')) {
            if (lxr.adv_if('p') || lxr.adv_if('P')) {
              if (lxr.adv_if('t') || lxr.adv_if('T')) {
                if (lxr.adv_if('i') || lxr.adv_if('I')) {
                  if (lxr.adv_if('o') || lxr.adv_if('O')) {
                    if (lxr.adv_if('n') || lxr.adv_if('N')) {
                      div_len = 10; /*figcaption*/
                    }
                  }
                }
              }
            }
          }
        }
        else if (lxr.adv_if('u') || lxr.adv_if('U')) {
          if (lxr.adv_if('r') || lxr.adv_if('R')) {
            if (lxr.adv_if('e') || lxr.adv_if('E')) {
              div_len = 6; /*figure*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('o') || lxr.adv_if('O')) {
      if (lxr.adv_if('o') || lxr.adv_if('O')) {
        if (lxr.adv_if('t') || lxr.adv_if('T')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            if (lxr.adv_if('r') || lxr.adv_if('R')) {
              div_len = 6; /*footer*/
            }
          }
        }
      }
      else if (lxr.adv_if('r') || lxr.adv_if('R')) {
        if (lxr.adv_if('m') || lxr.adv_if('M')) {
          div_len = 4; /*form*/
        }
      }
    }
    else if (lxr.adv_if('r') || lxr.adv_if('R')) {
      if (lxr.adv_if('a') || lxr.adv_if('A')) {
        if (lxr.adv_if('m') || lxr.adv_if('M')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            div_len = 5; /*frame*/
            if (lxr.adv_if('s') || lxr.adv_if('S')) {
              if (lxr.adv_if('e') || lxr.adv_if('E')) {
                if (lxr.adv_if('t') || lxr.adv_if('T')) {
                  div_len = 8; /*frameset*/
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('h') || lxr.adv_if('H')) {
    if (lxr.adv_if('1')) {
      div_len = 2; /*h1*/
    }
    else if (lxr.adv_if('2')) {
      div_len = 2; /*h2*/
    }
    else if (lxr.adv_if('3')) {
      div_len = 2; /*h3*/
    }
    else if (lxr.adv_if('4')) {
      div_len = 2; /*h4*/
    }
    else if (lxr.adv_if('5')) {
      div_len = 2; /*h5*/
    }
    else if (lxr.adv_if('6')) {
      div_len = 2; /*h6*/
    }
    else if (lxr.adv_if('e') || lxr.adv_if('E')) {
      if (lxr.adv_if('a') || lxr.adv_if('A')) {
        if (lxr.adv_if('d') || lxr.adv_if('D')) {
          div_len = 4; /*head*/
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            if (lxr.adv_if('r') || lxr.adv_if('R')) {
              div_len = 6; /*header*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('r') || lxr.adv_if('R')) {
      div_len = 2; /*hr*/
    }
    else if (lxr.adv_if('t') || lxr.adv_if('T')) {
      if (lxr.adv_if('m') || lxr.adv_if('M')) {
        if (lxr.adv_if('l') || lxr.adv_if('L')) {
          div_len = 4; /*html*/
        }
      }
    }
  }
  else if (lxr.adv_if('i') || lxr.adv_if('I')) {
    if (lxr.adv_if('f') || lxr.adv_if('F')) {
      if (lxr.adv_if('r') || lxr.adv_if('R')) {
        if (lxr.adv_if('a') || lxr.adv_if('A')) {
          if (lxr.adv_if('m') || lxr.adv_if('M')) {
            if (lxr.adv_if('e') || lxr.adv_if('E')) {
              div_len = 6; /*iframe*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('l') || lxr.adv_if('L')) {
    if (lxr.adv_if('e') || lxr.adv_if('E')) {
      if (lxr.adv_if('g') || lxr.adv_if('G')) {
        if (lxr.adv_if('e') || lxr.adv_if('E')) {
          if (lxr.adv_if('n') || lxr.adv_if('N')) {
            if (lxr.adv_if('d') || lxr.adv_if('D')) {
              div_len = 6; /*legend*/
            }
          }
        }
      }
    }
    else if (lxr.adv_if('i') || lxr.adv_if('I')) {
      div_len = 2; /*li*/
      if (lxr.adv_if('n') || lxr.adv_if('N')) {
        if (lxr.adv_if('k') || lxr.adv_if('K')) {
          div_len = 4; /*link*/
        }
      }
    }
  }
  else if (lxr.adv_if('m') || lxr.adv_if('M')) {
    if (lxr.adv_if('a') || lxr.adv_if('A')) {
      if (lxr.adv_if('i') || lxr.adv_if('I')) {
        if (lxr.adv_if('n') || lxr.adv_if('N')) {
          div_len = 4; /*main*/
        }
      }
    }
    else if (lxr.adv_if('e') || lxr.adv_if('E')) {
      if (lxr.adv_if('n') || lxr.adv_if('N')) {
        if (lxr.adv_if('u') || lxr.adv_if('U')) {
          div_len = 4; /*menu*/
          if (lxr.adv_if('i') || lxr.adv_if('I')) {
            if (lxr.adv_if('t') || lxr.adv_if('T')) {
              if (lxr.adv_if('e') || lxr.adv_if('E')) {
                if (lxr.adv_if('m') || lxr.adv_if('M')) {
                  div_len = 8; /*menuitem*/
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('n') || lxr.adv_if('N')) {
    if (lxr.adv_if('a') || lxr.adv_if('A')) {
      if (lxr.adv_if('v') || lxr.adv_if('V')) {
        div_len = 3; /*nav*/
      }
    }
    else if (lxr.adv_if('o') || lxr.adv_if('O')) {
      if (lxr.adv_if('f') || lxr.adv_if('F')) {
        if (lxr.adv_if('r') || lxr.adv_if('R')) {
          if (lxr.adv_if('a') || lxr.adv_if('A')) {
            if (lxr.adv_if('m') || lxr.adv_if('M')) {
              if (lxr.adv_if('e') || lxr.adv_if('E')) {
                if (lxr.adv_if('s') || lxr.adv_if('S')) {
                  div_len = 8; /*noframes*/
                }
              }
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('o') || lxr.adv_if('O')) {
    if (lxr.adv_if('l') || lxr.adv_if('L')) {
      div_len = 2; /*ol*/
    }
    else if (lxr.adv_if('p') || lxr.adv_if('P')) {
      if (lxr.adv_if('t') || lxr.adv_if('T')) {
        if (lxr.adv_if('g') || lxr.adv_if('G')) {
          if (lxr.adv_if('r') || lxr.adv_if('R')) {
            if (lxr.adv_if('o') || lxr.adv_if('O')) {
              if (lxr.adv_if('u') || lxr.adv_if('U')) {
                if (lxr.adv_if('p') || lxr.adv_if('P')) {
                  div_len = 8; /*optgroup*/
                }
              }
            }
          }
        }
        else if (lxr.adv_if('i') || lxr.adv_if('I')) {
          if (lxr.adv_if('o') || lxr.adv_if('O')) {
            if (lxr.adv_if('n') || lxr.adv_if('N')) {
              div_len = 6; /*option*/
            }
          }
        }
      }
    }
  }
  else if (lxr.adv_if('t') || lxr.adv_if('T')) {
    if (lxr.adv_if('a') || lxr.adv_if('A')) {
      if (lxr.adv_if('b') || lxr.adv_if('B')) {
        if (lxr.adv_if('l') || lxr.adv_if('L')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            div_len = 5; /*table*/
          }
        }
      }
    }
    else if (lxr.adv_if('b') || lxr.adv_if('B')) {
      if (lxr.adv_if('o') || lxr.adv_if('O')) {
        if (lxr.adv_if('d') || lxr.adv_if('D')) {
          if (lxr.adv_if('y') || lxr.adv_if('Y')) {
            div_len = 5; /*tbody*/
          }
        }
      }
    }
    else if (lxr.adv_if('d') || lxr.adv_if('D')) {
      div_len = 2; /*td*/
    }
    else if (lxr.adv_if('f') || lxr.adv_if('F')) {
      if (lxr.adv_if('o') || lxr.adv_if('O')) {
        if (lxr.adv_if('o') || lxr.adv_if('O')) {
          if (lxr.adv_if('t') || lxr.adv_if('T')) {
            div_len = 5; /*tfoot*/
          }
        }
      }
    }
    else if (lxr.adv_if('h') || lxr.adv_if('H')) {
      div_len = 2; /*th*/
      if (lxr.adv_if('e') || lxr.adv_if('E')) {
        if (lxr.adv_if('a') || lxr.adv_if('A')) {
          if (lxr.adv_if('d') || lxr.adv_if('D')) {
            div_len = 5; /*thead*/
          }
        }
      }
    }
    else if (lxr.adv_if('i') || lxr.adv_if('I')) {
      if (lxr.adv_if('t') || lxr.adv_if('T')) {
        if (lxr.adv_if('l') || lxr.adv_if('L')) {
          if (lxr.adv_if('e') || lxr.adv_if('E')) {
            div_len = 5; /*title*/
          }
        }
      }
    }
    else if (lxr.adv_if('r') || lxr.adv_if('R')) {
      div_len = 2; /*tr*/
      if (lxr.adv_if('a') || lxr.adv_if('A')) {
        if (lxr.adv_if('c') || lxr.adv_if('C')) {
          if (lxr.adv_if('k') || lxr.adv_if('K')) {
            div_len = 5; /*track*/
          }
        }
      }
    }
  }
  else if (lxr.adv_if('u') || lxr.adv_if('U')) {
    if (lxr.adv_if('l') || lxr.adv_if('L')) {
      div_len = 2; /*ul*/
    }
  }
}

}
