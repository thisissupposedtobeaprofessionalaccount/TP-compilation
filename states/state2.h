#include "../automate.h"
#include "state.h"
class State2 : public State {
public:
  State2() : State("State2") {};
    ~State2(){};
  bool transition(Automate &automate, Symbole *s);
};
