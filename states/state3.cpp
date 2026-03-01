#include "state3.h"
#include "../automate.h"
#include "../symbole.h"
#include <iostream>

bool State3::transition(Automate &automate, Symbole *s) {
  switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
      Entier *s1 = (Entier *)automate.popSymbol();
      automate.reduction(1, new Expr(s1->getValeur()));
      break;
    }
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}
