#include "../automate.h"
#include "../symbole.h"
#include "state5.h"
#include "state7.h"
#include <iostream>

bool State7::transition(Automate &automate, Symbole *s) {
  cout<<"State 7"<<endl;
  switch (*s) {
  case MULT:
    automate.decalage(s, new State5);
    return true;
    {
  case PLUS:
  case CLOSEPAR:
  case FIN:
    Expr *s1 = (Expr *)automate.popSymbol();
    automate.popAndDestroySymbol();
    Expr *s2 = (Expr *)automate.popSymbol();
    automate.reduction(3, new Expr(s2->getValeur() + s1->getValeur()));
    return true;
    }
  default:
    std::cout << "Erreur de syntaxe" << endl;
    break;
  }
  return false;
}
