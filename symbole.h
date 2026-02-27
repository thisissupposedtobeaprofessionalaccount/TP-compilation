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

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      operator int() const { return valeur; }
      virtual void Affiche();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr():Symbole(EXPR) {}
      virtual ~Expr() {}
      virtual double eval(const map<string, double> & valeurs) = 0;
      virtual void Affiche();
   protected:
};

class ExprBin : public Expr {
   public: 
      ExprBin(Symbole s1, Symbole s2): Symbole(EXPRBIN) {}
      virtual ~ExprBin() {}
      virtual void Affiche();
   protected:
}

class ExprMult : public ExprBin {
   public:
      ExprMult(Symbole s1, Symbole s2) : Symbole(EXPRMULT) {}
      virtual ~ExprMult() {}
      virtual void Affiche();
   protected:
}

class ExprPlus : public ExprBin {
   public:
      ExprPlus(Symbole s1, Symbole s2) : Symbole(EXPRPLUS) {}
      virtual ~ExprPlus() {}
      virtual void Affiche();
   protected:
};

