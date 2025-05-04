#ifndef PILE_INT_HPP
#define PILE_INT_HPP

#include <iostream> 
using namespace std;

class MaillonInt { 
    friend class ListeInt;
    friend class PileInt;
    
	int info;
	MaillonInt * suiv;  
	
	public:
	    MaillonInt();
	    MaillonInt(int);
	    MaillonInt(int, MaillonInt *);
	    ~MaillonInt();
};


class ListeInt {
	private : 
        friend class PileInt;
		MaillonInt *tete;

	public :
	    ListeInt();
        ListeInt(int T[], int ); 
        ListeInt(int , int T[]);
        MaillonInt * NouveauMaillonInt(int , MaillonInt * );
        void Afficher();
        void InsererEnTete(int );
        void SupprimerEnTete();
        ~ListeInt();
};


class PileInt {
    friend class ListeInt;
    friend class MaillonInt;
    private :
        
        ListeInt* L ;
    public :
        PileInt();
        PileInt(ListeInt *);
        PileInt(int T[], int taille);
        int getInfo(); 
        void Afficher_PileInt();
        int EmPileInt(int val);
        int DePileInt();
        bool Vide();
        
        
        //
        ~PileInt();

};


#endif 