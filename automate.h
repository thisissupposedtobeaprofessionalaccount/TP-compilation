class Automate {
    public:
        Automate();
        decalage(Symbole * s, Etat * e);
        transitionsimple(Symbole * s, Etat * e);
        reduction(int n, Symbole * s);
        popAndDestroySymbol();
        popSymbol();
    protected:

};