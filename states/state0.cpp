#include "state0.h"
#include "state1.h"
#include "state2.h"
#include "state3.h"
#include "../automate.h"
#include "../symbole.h"
#include <iostream>

bool State0::transition(Automate &automate, Symbole *s) {
  cout<<"State 0"<<endl;
  switch (*s) {
    case INT:
      automate.decalage(s, new State3);
      return true;
    case OPENPAR:
      automate.decalage(s, new State2);
      return true;
    case EXPR:
      automate.transitionSimple(s, new State1);
      return true;
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}
