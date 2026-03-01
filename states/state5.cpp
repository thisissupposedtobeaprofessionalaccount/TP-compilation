#include "state2.h"
#include "state3.h"
#include "state5.h"
#include "state8.h"
#include <iostream>
#include "../automate.h"
#include "../symbole.h"

bool State5::transition(Automate &automate, Symbole *s) {
  switch (*s) {
    case INT:
      automate.decalage(s, new State3);
      break;
    case OPENPAR:
      automate.decalage(s, new State2);
      break;
    case EXPR:
      automate.transitionSimple(s, new State8);
      break;
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}


