#include "automate.h"
class State6 : public State {
  public :
    State6();
    ~State6();
    bool transition (Automate & automate, Symbole * s);
};
