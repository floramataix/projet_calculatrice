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
        cout << "La pile est vidEEE "<<endl;
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
    int priorite = 0;
    if (expr == "+" || expr == "-" ){
        priorite = 1;
    }
    else if (expr == "*" || expr == "/"){
        priorite = 2;
    }
    else {
        priorite = 0;
    } 
    return priorite;
}



string Transform(string expr[], int taille) {
    Pile * operateurs = new Pile();
    string sortie ;


    for (int i = 0; i < taille; i++ ){
        //algorithme de shunting yard 
                
        if ( Prioritee(expr[i]) == 1 && !operateurs->Vide()) {
            string a = operateurs->Depiler();
            while (a != "(" && !operateurs->Vide() ){
                sortie = sortie + operateurs->Depiler();
                a = operateurs->Depiler(); 
            }
        }

        else if (Prioritee(expr[i]) == 2){
            string a = operateurs->Depiler();
            if (a != "(" &&  a != ")" && !operateurs ->Vide() ){
                if (Prioritee(a) == 2) {
                    while (Prioritee(a) != 1 && a != "(" && a != ")") {
                        sortie = sortie + a;
                        a = operateurs->Depiler();}
                }
                operateurs->Empiler(expr[i]);
            }
        }

        else if (expr[i] == "(" ){
            operateurs->Empiler(expr[i]);
        }

        else if (expr[i] == ")"){

            while (!operateurs->Vide() && operateurs->L->tete->info != "(") {
                sortie = sortie + operateurs->Depiler();
            }
            if (!operateurs->Vide() && (operateurs->L->tete->info == "(" || operateurs->L->tete->info == ")")) {
                operateurs->Depiler(); // Retirer les parenthèses
            }
        }
        else {  //si c'est un operande
            sortie = sortie + expr[i];
        }
        
        //debug
        cout << "i qui est étudier actuellement" << expr[i] << endl;
        cout << "La sortie actuellement" << sortie <<endl;
        cout <<"La pile operateur actuellement";
        operateurs->Afficher_pile();
        cout << "-------------------" <<endl;
    }
    while (!operateurs->Vide()) {
        sortie = sortie + operateurs->Depiler();
    }
    
    return sortie;
}

Pile::~Pile() {
    delete L;
}
