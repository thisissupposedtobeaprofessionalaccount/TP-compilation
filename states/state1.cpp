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
      return true;
    case MULT:
      automate.decalage(s, new State5);
      return true;
    case FIN:
      return automate.accepter(s);
      return true;
    default:
      std::cout << "Erreur de syntaxe" << endl;
      break;
  }
  return false;
}
