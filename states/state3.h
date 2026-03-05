#include "../automate.h"
#include "state.h"
class State3 : public State {
  public :
    State3() : State("State3"){};
   ~State3(){};
    bool transition (Automate & automate, Symbole * s);
};
