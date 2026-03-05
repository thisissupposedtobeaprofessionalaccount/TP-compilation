#include "../automate.h"
#include "state.h"
class State9 : public State {
  public :
    State9() : State("State9"){};
    ~State9(){};
    bool transition (Automate & automate, Symbole * s);
};
