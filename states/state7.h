#pragma once
#include "state.h"

class Automate;

class State7 : public State {
  public :
    State7():State("State7"){}
    ~State7(){}
    bool transition (Automate & automate, Symbole * s);
};
