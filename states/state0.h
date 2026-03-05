#include "../automate.h"
#include "state.h"
class State0 : public State {
  public :
    State0() : State("State0"){};
    virtual ~State0(){};
    bool transition (Automate & automate, Symbole * s);
};
