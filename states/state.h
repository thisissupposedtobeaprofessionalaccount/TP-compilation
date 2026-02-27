#pragma once
#include "../automate.h"
#include <string>

class Automate;

class State {
public:
  State(std::string name);
  virtual ~State();
  void print() const;
  virtual bool transition(Automate &automate, Symbole *s) = 0;

protected:
  string name;
};
