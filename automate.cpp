#include "automate.h"
#include <iostream>
#include "states/state0.h"
#include "states/state.h"

void Automate::start() {
    done = false;
    ok = false;
    
    statestack.push_back(new State0()); 

    while (!done) {
        Symbole *s = lexer->Consulter();

        if (!this->statestack.back()->transition(*this, s)) {
            std::cout << "Erreur de syntaxe :(" << std::endl;
            done = true;
            ok = false;
        }
    }

    if (ok) {
        // 2. Le résultat final est le dernier symbole EXPR sur la pile
        Expr *res = (Expr *)symbolstack.back(); 
        std::cout << "Analyse réussie ! :3" << std::endl;
        std::cout << "Resultat : " << res->getValeur() << std::endl;
    }
}
void Automate::decalage(Symbole *s, State *e) {
  symbolstack.push_back(s);
  statestack.push_back(e);
  lexer->Avancer();
}

void Automate::transitionSimple(Symbole *s, State *e) {
  symbolstack.push_back(s);
  statestack.push_back(e);
}

void Automate::reduction(int n, Symbole *s) {
  for (int i = 0; i < n; i++) {
    delete (statestack.back());
    statestack.pop_back();
  }
  statestack.back()->transition(*this, s);
}

void Automate::popAndDestroySymbol() {
  Symbole *temp = symbolstack.back();
  symbolstack.pop_back();
  delete temp;
}

Symbole *Automate::popSymbol() {
  Symbole *result = symbolstack.back();
  symbolstack.pop_back();
  return result;
}

bool Automate::accepter(Symbole *s) {
  this->done = true;
  this->ok = true;

  return true;
}
