#include "state4.h"
#include "state5.h"
#include "state6.h"
#include "state9.h"
#include <iostream>
#include "../automate.h"
#include "../symbole.h"

bool State6::transition(Automate &automate, Symbole *s) {
  switch (*s) {
    case PLUS:
      automate.decalage(s, new State4);
      break;
    case MULT:
      automate.decalage(s, new State5);
      break;
    case CLOSEPAR:
      automate.decalage(s, new State9);
      break;
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}

