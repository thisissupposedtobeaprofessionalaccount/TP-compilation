#include "../automate.h"
#include "state.h"
class State4 : public State {
  public :
    State4() : State("State4"){};
   ~State4(){};
    bool transition (Automate & automate, Symbole * s);
};
