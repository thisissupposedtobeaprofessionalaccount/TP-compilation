#include "state8.h"
#include "../automate.h"
#include "../symbole.h"
#include "state0.h"
#include "state1.h"
#include "state2.h"
#include "state3.h"
#include "state4.h"
#include "state5.h"
#include "state6.h"
#include "state7.h"
#include "state9.h"
#include <iostream>

bool State8::transition(Automate &automate, Symbole *s) {
  switch (*s) {
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
      Expr *s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      Expr *s2 = (Expr *)automate.popSymbol();
      automate.reduction(3, new Expr(s2->getValeur() * s1->getValeur()));
      break;
    }
  default:
    std::cout << "Erreur de syntaxe" << endl;
    break;
  }
  return false;
}
