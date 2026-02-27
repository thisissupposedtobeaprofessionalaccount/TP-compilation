#include "automate.h"
class State4 : public State {
  public :
    State4();
    ~State4();
    bool transition (Automate & automate, Symbole * s);
};
