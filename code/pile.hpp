#ifndef PILE_HPP
#define PILE_HPP
#include "liste_chainee.h"    

class Pile {
    friend class Liste;
    friend class Maillon;
    friend string Transform(string expr[], int taille);
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
        string Evaluer(string expr[], int );
        
        //
        ~Pile();

};
        int Prioritee(string);
        string Transform(string expr[], int );

#endif