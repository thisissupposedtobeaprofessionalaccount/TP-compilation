#include "state2.h"
#include "state3.h"
#include "state6.h"
#include <iostream>
#include "../automate.h"
#include "../symbole.h"

bool State2::transition(Automate &automate, Symbole *s) {
  switch (*s) {
    case INT:
      automate.decalage(s, new State3);
      break;
    case OPENPAR:
      automate.decalage(s, new State2);
      break;
    case EXPR:
      automate.transitionSimple(s, new State6);
      break;
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}

