#pragma once
#include "state.h"

class Automate;

class State9 : public State {
  public :
    State9():State("State9"){}
    ~State9(){}
    bool transition (Automate & automate, Symbole * s);
};
