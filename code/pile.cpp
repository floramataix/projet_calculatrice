#include <iostream> 
#include "pile.hpp"
#include "liste_chainee.h"
using namespace std;

Pile::Pile(){
    L= new Liste();
}

Pile::Pile(Liste *list){
    L = list;
}


Pile::Pile(string T[], int taille){
    L = new Liste(T,taille);
}

void Pile::Afficher_pile(){
    L->Afficher();
}


string Pile::Empiler(string val) {
    if (L == nullptr) {
        L = new Liste();
    }
    L->InsererEnTete(val);
    return L->tete->info;
}

bool Pile::Vide() {
    if (L == nullptr || L->tete == nullptr ) {
        return true;
    }
    else {
        return false;
    }
}

string Pile::Depiler() {
    if (Vide()) {
        cout << "Attention : la pile est vide " << endl;
        return 0;
    }
    string val = L->tete->info;
    Maillon* tmp = L->tete;
    L->tete = L->tete->suiv;
    return val;
}

string Pile::Evaluer(string expr[], int taille) {
    
    for (int i = 0; i < taille; i++ ){
         
        if (expr[i] == "+"){
            double a = stod(Depiler());
            double b = stod(Depiler());
            Empiler(to_string(a+b));
            
        }
        else if (expr[i] == "-"){
            double a = stod(Depiler());
            double b = stod(Depiler());
            Empiler(to_string(a - b));
        }
        else if (expr[i] == "*"){
            double a = stod(Depiler());
            double b = stod(Depiler());
            Empiler(to_string(a * b));
        }
        else if (expr[i] == "/"){
            double a = stod(Depiler());
            double b = stod(Depiler());
            Empiler(to_string(a / b));
        }
        else {
            Empiler(expr[i]);
        }
    }
    return Depiler();
} 

int Pile::Prioritee(string expr) {
    //prioritée de l'operateur :
    int priorite = 0;
    if (expr == "+" || expr == "-" ){
        priorite = 1;
    }
    if (expr == "*" || expr == "/"){
        priorite = 2;
    }
    return priorite;
}



string Pile::Transform(string expr[], int taille) {
    Pile * operateurs = new Pile();
    string sortie ;

    for (int i = 0; i < taille; i++ ){
        //algorithme de shunting yard 
        
        string a = Depiler();
        
        if ( Prioritee(expr[i]) == 1 && !Vide()) {
            while (a != "(" && !Vide() ){
                sortie = sortie + Depiler();
                a = Depiler();
            }
        }

        else if (Prioritee(expr[i]) == 2){
            if (a != "(" && !Vide() ){
                if (Prioritee(a) == 2) {
                    while (Prioritee(a) != 1 && a != "(") {
                        sortie = sortie + a;
                        a = Depiler();
                    }
                }
                operateurs->Empiler(expr[i]);
            }
        }

        else if (expr[i] == "(" ){
            operateurs->Empiler(expr[i]);
        }

        else if (expr[i] == ")"){

            while (!operateurs->Vide() && operateurs->L->tete->info != "(") {
                sortie = sortie + Empiler(operateurs->Depiler());
            }
            if (!operateurs->Vide() && operateurs->L->tete->info == "(") {
                operateurs->Depiler(); // Retirer la parenthèse gauche
            }
        }
        else {  //si c'est un operande
            sortie = sortie + Empiler(expr[i]);
        }
    }
    while (!operateurs->Vide()) {
        sortie = sortie + Depiler();
    }
    return sortie;
}

Pile::~Pile() {
    delete L;
}
