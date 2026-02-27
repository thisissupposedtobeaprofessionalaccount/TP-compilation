#include "automate.h"

class State {
public:
  State(string name);
  virtual ~State();
  void print() const;
  virtual bool transition(Automate &automate, Symbole *s) = 0;

protected:
  string name;
};
