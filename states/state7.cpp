#pragma once
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
      break;
    case PLUS:
    case CLOSEPAR:
    case FIN:
      Entier *s1 = (Entier *)automate.popSymbol();
      automate.popAndDestroySymbol();
      Entier *s2 = (Entier *)automate.popSymbol();
      automate.reduction(3, new Expr(s2->getValeur() + s1->getValeur()));
      break;
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}
