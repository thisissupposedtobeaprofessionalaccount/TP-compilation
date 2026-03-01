#pragma once
#include "state.h"

class Automate;

class State6 : public State {
  public :
    State6():State("State6"){}
    ~State6(){}
    bool transition (Automate & automate, Symbole * s);
};
