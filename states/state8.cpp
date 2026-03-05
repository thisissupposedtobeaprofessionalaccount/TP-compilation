#include "state8.h"
#include "../automate.h"
#include "../symbole.h"
#include <iostream>

bool State8::transition(Automate &automate, Symbole *s) {
  cout<<"State 8"<<endl;
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
      return true;
    }
  default:
    std::cout << "Erreur de syntaxe" << endl;
    break;
  }
  return false;
}
