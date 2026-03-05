#include "../automate.h"
#include "state.h"
class State6 : public State {
  public :
    State6() : State("State6"){};
    ~State6(){};
    bool transition (Automate & automate, Symbole * s);
};
