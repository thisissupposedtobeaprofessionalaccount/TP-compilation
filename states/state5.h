#pragma once
#include "../automate.h"
class State5 : public State {
  public :
    State5();
    ~State5();
    bool transition (Automate & automate, Symbole * s);
};
