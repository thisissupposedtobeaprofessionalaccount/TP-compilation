#include "state3.h"
#include "../automate.h"
#include "../symbole.h"
#include <iostream>

bool State3::transition(Automate &automate, Symbole *s) {
  cout<<"State 3"<<endl;
  switch (*s) {
    {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
      Expr *s1 = (Expr *)automate.popSymbol();
      automate.reduction(1, new Expr(s1->getValeur()));
      return true;
    }
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}
