#pragma once
#include "state0.h"
#include "state1.h"
#include "state2.h"
#include "state3.h"
#include "state4.h"
#include "state5.h"
#include "state6.h"
#include "state7.h"
#include "state8.h"
#include "state9.h"
#include <iostream>
#include "../automate.h"
#include "../symbole.h"

bool State7::transition(Automate &automate, Symbole *s) {
  switch (*s) {
    case PLUS:
    automate.reduction(s, new State2);
    break;
    case MULT:
    automate.decalage(s, new State5);
    break;
    case CLOSEPAR:
    automate.reduction(s, new State2);
    break;
    case FIN:
    automate.reduction(s, new State2);
    break;
   default:
    std::cout << "Erreur de syntaxe" << endl;
    break;
  }
  return false;
}

