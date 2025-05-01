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

string Pile::getInfo() {
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

void Pile::Afficher_pile(){
    if (!Vide()) {
        L->Afficher();
    }
    else {
        cout << "La pile est vide "<<endl;
    }
}

string Pile::Empiler(string val) {
    if (L == nullptr) {
        L = new Liste();
    }
    L->InsererEnTete(val);
    return L->tete->info;
}

string Pile::Depiler() {
    if (Vide()) {
        cout << "Attention : la pile est vide " << endl;
        return "none";
    }
    else {
        string val = L->tete->info;
        Maillon* tmp = L->tete;
        L->tete = L->tete->suiv;
        return val;

    }
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

int Prioritee(string expr) {
    //prioritée de l'operateur :
    if (expr == "+" || expr == "-") {
        return 1;
    }
    else if (expr == "*" || expr == "/") {
        return 2;
    }
    else if (expr == "(" || expr == ")") {
        return 0;
    }
    return 0;
}

string Transform(string expr[], int taille) {
    Pile * operateurs = new Pile();
    string sortie ;

    for (int i = 0; i < taille; i++ ){
        //algorithme de shunting yard.

        if (Prioritee(expr[i]) == 1 || Prioritee(expr[i]) == 2) {
            while (!operateurs->Vide() && Prioritee(expr[i]) <= Prioritee(operateurs->getInfo())) {
                sortie += operateurs->Depiler();
            }
            operateurs->Empiler(expr[i]);
        }
    

        else if (expr[i] == "(" ){  //si c'est une parenthese ouvrante.
            operateurs->Empiler(expr[i]);
        }

        else if (expr[i] == ")"){ //si c'est une parenthese fermante.
            while (!operateurs->Vide() && operateurs->getInfo() != "(") {
                sortie += operateurs->Depiler();
            }
            if (!operateurs->Vide() && operateurs->getInfo() == "(") {
                operateurs->Depiler(); 
            }
        }

        else {  //si c'est un operande
            sortie += expr[i];
        }

        /* //debug
        cout << "i qui est étudier actuellement : " << expr[i] << endl;
        cout << "La sortie actuellement : " << sortie <<endl;
        cout <<"La pile operateur actuellement : ";
        operateurs->Afficher_pile();
        cout << "-------------------" <<endl; */
    }

    while (!operateurs->Vide()) {    
        sortie += operateurs->Depiler();
    }
    
    return sortie;
}

Pile::~Pile() {
    delete L;
}
