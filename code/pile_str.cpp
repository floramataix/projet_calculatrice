#include <iostream> 
#include "pile_str.hpp"
using namespace std;


ListeStr::ListeStr()
{
    tete = nullptr;
}


MaillonStr::MaillonStr()
{
    suiv = nullptr;
}

MaillonStr::MaillonStr(string val)
{
    info = val;
    suiv = nullptr;
}

MaillonStr::MaillonStr(string val, MaillonStr * suivant)
{
  info = val;
  suiv = suivant;
}

ListeStr::ListeStr(string T[], int taille)
{
  int i;
  MaillonStr * tmp;
  
  if (taille == 0)
  {
    tete = nullptr;
    return;
  }
  tete = new MaillonStr(T[0]);
  tmp = tete;
  for (i = 1;i < taille; i++)
  {
    tmp -> suiv = new MaillonStr(T[i]);
    tmp = tmp -> suiv;
  }
}

ListeStr::ListeStr(int taille, string T[])
{
  int i;
  tete = nullptr;
  for (i = taille - 1;i >= 0; i--)
    tete = new MaillonStr(T[i], tete);
}

void ListeStr::Afficher()
{
    MaillonStr * tmp;
    tmp = tete;
    
    while (tmp != nullptr)
    {
        cout << tmp -> info << " ";
        tmp = tmp -> suiv;
    }
    cout << endl;
}

MaillonStr::~MaillonStr(){
  if (suiv != nullptr)
    delete suiv;
}

void ListeStr::InsererEnTete(string val) {
  if (tete == nullptr) {
    tete = new MaillonStr(val);
  }
  else {

    MaillonStr* nouveau = new MaillonStr(val, tete);
    tete = nouveau;
  }
}

void ListeStr::SupprimerEnTete() {
  if (tete == nullptr) {
      return;
  }
  MaillonStr* tmp = tete;
  tete = tete->suiv;
  cout << "etat de la tête après supprimer en tete" << tete->info << endl;
  cout << "etat de la tête après supprimer en tete" << tete->info << endl;
}

ListeStr::~ListeStr()
{
  MaillonStr * tmp;
  
  while (tete != nullptr)
  {
    tmp = tete;
    tete = tete -> suiv;
    delete tmp;
  }
}


PileStr::PileStr(){
    L= new ListeStr();
}

PileStr::PileStr(ListeStr *list){
    L = list;
}


PileStr::PileStr(string T[], int taille){
    L = new ListeStr(T,taille);
}

string PileStr::getInfo() {
    return L->tete->info;
}

bool PileStr::Vide() {
    if (L == nullptr || L->tete == nullptr ) {
        return true;
    }
    else {
        return false;
    }
}

void PileStr::Afficher_pile(){
    if (!Vide()) {
        L->Afficher();
    }
    else {
        cout << "La pileStr est vide "<<endl;
    }
}

string PileStr::EmPilerStr(string val) {
    if (L == nullptr) {
        L = new ListeStr();
    }
    L->InsererEnTete(val);
    return L->tete->info;
}

string PileStr::DePilerStr() {
    if (Vide()) {
        cout << "Attention : la pileStr est vide " << endl;
        return "none";
    }
    else {
        string val = L->tete->info;
        MaillonStr* tmp = L->tete;
        L->tete = L->tete->suiv;
        return val;

    }
}

string PileStr::Evaluer(string expr[], int taille) {
    for (int i = 0; i < taille; i++ ){
         
        if (expr[i] == "+"){
            double a = stod(DePilerStr());
            double b = stod(DePilerStr());
            EmPilerStr(to_string(a+b));
        }
        else if (expr[i] == "-"){
            double a = stod(DePilerStr());
            double b = stod(DePilerStr());
            EmPilerStr(to_string(a - b));
        }
        else if (expr[i] == "*"){
            double a = stod(DePilerStr());
            double b = stod(DePilerStr());
            EmPilerStr(to_string(a * b));
        }
        else if (expr[i] == "/"){
            double a = stod(DePilerStr());
            double b = stod(DePilerStr());
            EmPilerStr(to_string(a / b));
        }
        else {
            EmPilerStr(expr[i]);
        }
    }
    return DePilerStr();
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

string* Transform(string expr[], int taille) {
    PileStr * operateurs = new PileStr();
    string* sortie = new string[taille];    //la taille ne sera pas la meme mais ca nous derange pas car elle sera plus petite que l'autre.
    int j = 0;

    for (int i = 0; i < taille; i++ ){
        //algorithme de shunting yard.

        if (Prioritee(expr[i]) == 1 || Prioritee(expr[i]) == 2) {
            while (!operateurs->Vide() && Prioritee(expr[i]) <= Prioritee(operateurs->getInfo())) {
                sortie[j++] = operateurs->DePilerStr();// j+++ pour se deplacer dans
            }
            operateurs->EmPilerStr(expr[i]);
        }
    

        else if (expr[i] == "(" ){  //si c'est une parenthese ouvrante.
            operateurs->EmPilerStr(expr[i]);
        }

        else if (expr[i] == ")"){ //si c'est une parenthese fermante.
            while (!operateurs->Vide() && operateurs->getInfo() != "(") {
                sortie[j++] = operateurs->DePilerStr();
            }
            if (!operateurs->Vide() && operateurs->getInfo() == "(") {
                operateurs->DePilerStr(); 
            }
        }

        else {  //si c'est un operande
            sortie[j++] = expr[i];
        }

        /* //debug
        cout << "i qui est étudier actuellement : " << expr[i] << endl;
        cout << "La sortie actuellement : " << sortie <<endl;
        cout <<"La pileStr operateur actuellement : ";
        operateurs->Afficher_pile();
        cout << "-------------------" <<endl; */
    }

    while (!operateurs->Vide()) {    
        sortie[j++] = operateurs->DePilerStr();
    }
    
    return sortie;
}

PileStr::~PileStr() {
    delete L;
}
