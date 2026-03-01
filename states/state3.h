#pragma once
#include "state.h"

class Automate;

class State3 : public State {
  public :
    State3():State("State3"){}
    ~State3(){}
    bool transition (Automate & automate, Symbole * s);
};
