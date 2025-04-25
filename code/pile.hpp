#ifndef PILE_HPP
#define PILE_HPP
#include "liste_chainee.h"    

class Pile {
    private :
        Liste* L ;
    public :
        Pile();
        Pile(Liste *);
        Pile(string T[], int taille);
        void Afficher_pile();
        string Empiler(string val);
        string Depiler();
        bool Vide();
        string Evaluer(string *, int );
        int Prioritee(string);
        string Transform(string *, int );
        ~Pile();
};

#endif