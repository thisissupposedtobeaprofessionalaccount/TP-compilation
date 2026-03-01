#pragma once
#include "state.h"

class Automate;

class State5 : public State {
  public :
    State5():State("State5"){}
    ~State5(){}
    bool transition (Automate & automate, Symbole * s);
};
