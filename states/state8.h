#include "../automate.h"
#include "state.h"
class State8 : public State {
public:
  State8() : State("State8") {};
  ~State8() {};
  bool transition(Automate &automate, Symbole *s);
};
