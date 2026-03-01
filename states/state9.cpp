#include "state9.h"
#include "../automate.h"
#include "../symbole.h"
#include <iostream>

bool State9::transition(Automate &automate, Symbole *s) {
  switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
      automate.popAndDestroySymbol();
      Expr *s1 = (Expr *)automate.popSymbol();
      automate.popAndDestroySymbol();
      automate.reduction(3, s1);
      break;
    }
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}
