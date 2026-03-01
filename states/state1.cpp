#pragma once
#include "state1.h"
#include "state4.h"
#include "state5.h"
#include <iostream>
#include "../automate.h"
#include "../symbole.h"

bool State1::transition(Automate &automate, Symbole *s) {
  cout<<"State 1"<<endl;
  switch (*s) {
    case PLUS:
      automate.decalage(s, new State4);
      break;
    case MULT:
      automate.decalage(s, new State5);
      break;
    case FIN:
      return automate.accepter(s);
      break;
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}
