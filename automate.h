#pragma once
#include "symbole.h"
#include "./states/state.h"
#include <stack>
#include <vector>
#include "lexer.h"

class State;

class Automate {
    public:
        Automate(Lexer * l);
        ~Automate();
        void decalage(Symbole * s, State * e);
        void transitionSimple(Symbole * s, State * e);
        void reduction(int n, Symbole * s);
        void popAndDestroySymbol();
        Symbole* popSymbol();
        void run();

        bool accepter( Symbole * s);
    protected:
        Lexer * lexer;
        vector<Symbole*> symbolstack;
        vector<State*> statestack;
};
