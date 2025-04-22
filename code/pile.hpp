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
        void Empiler(string val);
        string Depiler();
        bool Vide();
        string Evaluer(string *, int );
        void Transform(string *, int );
        ~Pile();
};

#endif