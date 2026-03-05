#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR, EXPRBIN, EXPRPLUS, EXPRMULT };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR", "EXPRBIN", "EXPRPLUS", "EXPRMULT" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();
   protected:
      int ident;
};

class Expr : public Symbole {
   public:
      Expr(int v):Symbole(EXPR), valeur(v) {}
      ~Expr() {}
      int getValeur();
      void Affiche() override;
   protected:
      int valeur;
};

