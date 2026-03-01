#pragma once
#include "state2.h"
#include "state3.h"
#include "state4.h"
#include "state7.h"
#include <iostream>
#include "../automate.h"
#include "../symbole.h"

bool State4::transition(Automate &automate, Symbole *s) {
  cout<<"State 4"<<endl;
  switch (*s) {
    case INT:
      automate.decalage(s, new State3);
      break;
    case OPENPAR:
      automate.decalage(s, new State2);
      break;
    case EXPR:
      automate.transitionSimple(s, new State7);
      break;
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}

