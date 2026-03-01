#include "automate.h"
#include "./states/state0.h"
#include <iostream>

Automate::Automate(Lexer * l): lexer(l), symbolstack(), statestack() {
    statestack.push_back(new State0());
}

void Automate::run() {
    bool finish = false;
    while (!finish) {
        Symbole * s = lexer->Consulter();
        finish = statestack.back()->transition(*this, s);
    }
}

void Automate::decalage(Symbole * s, State * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
    lexer->Avancer();
}

void Automate::transitionSimple(Symbole * s, State * e) {
    symbolstack.push_back(s);
    statestack.push_back(e);
}

void Automate::reduction(int n, Symbole * s) {
    for (int i=0;i<n;i++)
    {
        delete(statestack.back());
        statestack.pop_back();
    }
    statestack.back()->transition(*this,s);
}

void Automate::popAndDestroySymbol(){
    Symbole* temp = symbolstack.back();
    symbolstack.pop_back();
    delete temp;
}

Symbole* Automate::popSymbol(){
    Symbole * result = symbolstack.back();
    symbolstack.pop_back();
    return result;
}

bool Automate::accepter(Symbole * s){
    s->Affiche();
    std::cout<<"\t";
    Expr * result = static_cast<Expr*>(symbolstack.back());
    result->Affiche();
    std::cout<<endl;
    return true;
}

Automate::~Automate() {
    while (!statestack.empty()) {
        delete statestack.back();
        statestack.pop_back();
    }

    while (!symbolstack.empty()) {
        delete symbolstack.back();
        symbolstack.pop_back();
    }
}
