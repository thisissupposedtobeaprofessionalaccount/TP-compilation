#pragma once
#include "lexer.h"
#include "symbole.h"
#include <stack>
#include <vector>

class State;
class Automate {
public:
  Automate(Lexer *lexer) : lexer(lexer), done(false), ok(true) {};
  void start();
  void decalage(Symbole *s, State *e);
  void transitionSimple(Symbole *s, State *e);
  void reduction(int n, Symbole *s);
  void popAndDestroySymbol();
  Symbole *popSymbol();

  bool accepter(Symbole *s);

protected:
  Lexer *lexer;
  vector<Symbole *> symbolstack;
  vector<State *> statestack;
  bool done;
  bool ok;
};
