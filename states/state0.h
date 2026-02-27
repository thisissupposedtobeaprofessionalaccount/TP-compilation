#include "../automate.h"
class State0 : public State {
  public :
    State0();
    ~State0();
    bool transition (Automate & automate, Symbole * s);
};
