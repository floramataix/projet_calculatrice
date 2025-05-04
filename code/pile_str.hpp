#ifndef PILE_STR_HPP
#define PILE_STR_HPP

#include <iostream>
using namespace std;

class MaillonStr {
    friend class ListeStr;
    friend class PileStr;
    
    string info;
    MaillonStr * suiv;
    
    public:
        MaillonStr();
        MaillonStr(string);
        MaillonStr(string, MaillonStr *);
        ~MaillonStr();
};

class ListeStr {
    private :
        friend class PileStr;
        MaillonStr *tete;

    public :
        ListeStr();
        ListeStr(string T[], int );
        ListeStr(int , string T[]);
        MaillonStr * NouveauMaillon(string , MaillonStr * );
        void Afficher();
        void InsererEnTete(string );
        void SupprimerEnTete();
        ~ListeStr();
};

class PileStr {
    friend class ListeStr;
    friend class MaillonStr;
    private :
        
        ListeStr* L ;
    public :
        PileStr();
        PileStr(ListeStr *);
        PileStr(string T[], int taille);
        string getInfo(); 
        void Afficher_pile();
        string EmPilerStr(string val);
        string DePilerStr();
        string Evaluer(string expr[], int );
        bool Vide();
        
        ~PileStr();

};

    int Prioritee(string);
    string Transform(string expr[], int );

#endif
