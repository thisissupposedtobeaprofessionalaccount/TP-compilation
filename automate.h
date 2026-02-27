#include "symbole.h"
#include "states/state.h"

class Automate {
    public:
        Automate();
        void decalage(Symbole * s, Etat * e);
        void transitionsimple(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        void popAndDestroySymbol();
        Symbole* popSymbol();
    protected:
        vector<Symbole> symbolstack;
        vector<State> statestack;
};