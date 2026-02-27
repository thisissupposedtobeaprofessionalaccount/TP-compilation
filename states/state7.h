#pragma once
#include "../automate.h"
class State7 : public State {
  public :
    State7();
    ~State7();
    bool transition (Automate & automate, Symbole * s);
};
