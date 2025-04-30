#ifndef __LISTE_H__
#define __LISTE_H__

#include <iostream> 
using namespace std;

class Maillon { 
    friend class Liste;
    friend class Pile;
	friend string Transform(string expr[], int taille);
    
	string info;
	Maillon * suiv;  
	
	public:
	    Maillon();
	    Maillon(string);
	    Maillon(string, Maillon *);
	    ~Maillon();
};



class Liste {
	private : 
        friend class Pile;
		friend string Transform(string expr[], int taille);
		Maillon *tete;

	public :
	    Liste();
        Liste(string T[], int ); 
        Liste(int , string T[]);
        Maillon * NouveauMaillon(string , Maillon * );
        void Afficher();
        void InsererEnTete(string );
        void SupprimerEnTete();
        ~Liste();
};

#endif
