#pragma once
#include "state.h"

class Automate;

class State1 : public State {
  public :
    State1():State("State1"){}
    ~State1(){}
    bool transition (Automate & automate, Symbole * s);
};
