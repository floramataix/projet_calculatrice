#ifndef ARBRE_HPP
#define ARBRE_HPP
#include <iostream>
using namespace std;

// Je ne savais pas si c'etais autoriser d'utiliser template pour adapter ma classe PileNoeud a n'importe quel type.
// J'ai donc creer une nouvelle PileNoeud qui cette fois ci ne prend pas des Noeud * mais des pointeurs vers des noeuds.

class MaillonNoeud {
    friend class ListeNoeud;
    friend class PileNoeud;
    
    Noeud * info;
    MaillonNoeud * suiv;
    
    public:
        MaillonNoeud();
        MaillonNoeud(Noeud *);
        MaillonNoeud(Noeud *, MaillonNoeud *);   
        ~MaillonNoeud();
};

class ListeNoeud {
    private :
        friend class PileNoeud;
        MaillonNoeud *tete;

    public :
        ListeNoeud();
        ListeNoeud(Noeud * T[], int );
        MaillonNoeud * NouveauMaillon(Noeud * , MaillonNoeud * );
        void Afficher();
        void InsererEnTete(Noeud * );
        void SupprimerEnTete();
        ~ListeNoeud();
};


class PileNoeud {
    private :
        friend class ListeNoeud;
        friend class MaillonNeud;
        ListeNoeud* L ;
    public :
        PileNoeud();
        PileNoeud(ListeNoeud *);
        PileNoeud(Noeud * T[], int taille);
        Noeud * getInfo(); 
        void Afficher_pile();
        Noeud * EmPilerNoeud(Noeud * val);
        Noeud * DePilerNoeud(); 
        bool Vide();
        Noeud * Evaluer(Noeud * expr[], int );
        ~PileNoeud();
};

//L'arbre en lui meme

class Noeud {
    private :
        char type ; //‘o’ pour opérateur et ‘f’ pour valeur.
        char ope ;// opérateur (+, -, *, /) si type == 'o'
        double val;    // valeur si type == 'f'
        Noeud * fg, * fd ;
    public : 
        Noeud(double v);
        Noeud(char op, Noeud* g, Noeud* d);
        ~Noeud();
        friend class Arbre; 

} ;

class Arbre {
    private : 
        Noeud *racine;
    public :
        Arbre();
        Arbre(const Noeud *& expr_suffixee);
        
        ~Arbre();
};

#endif;