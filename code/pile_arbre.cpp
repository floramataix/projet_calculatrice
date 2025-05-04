#include <iostream> 
#include "pile_arbre.hpp"
using namespace std;

ListeNoeud::ListeNoeud()
{
    tete = nullptr;
}


MaillonNoeud::MaillonNoeud()
{
    suiv = nullptr;
}

MaillonNoeud::MaillonNoeud(Noeud * val)
{
    info = val;
    suiv = nullptr;
}

MaillonNoeud::MaillonNoeud(Noeud * val, MaillonNoeud * suivant)
{
  info = val;
  suiv = suivant;
}

ListeNoeud::ListeNoeud(Noeud * T[], int taille)
{
  int i;
  MaillonNoeud * tmp;
  
  if (taille == 0)
  {
    tete = nullptr;
    return;
  }
  tete = new MaillonNoeud(T[0]);
  tmp = tete;
  for (i = 1;i < taille; i++)
  {
    tmp -> suiv = new MaillonNoeud(T[i]);
    tmp = tmp -> suiv;
  }
}


void ListeNoeud::Afficher()
{
    MaillonNoeud * tmp;
    tmp = tete;
    
    while (tmp != nullptr)
    {
        cout << tmp -> info << " ";
        tmp = tmp -> suiv;
    }
    cout << endl;
}

MaillonNoeud::~MaillonNoeud(){
  if (suiv != nullptr)
    delete suiv;
}

void ListeNoeud::InsererEnTete(Noeud * val) {
  if (tete == nullptr) {
    tete = new MaillonNoeud(val);
  }
  else {

    MaillonNoeud* nouveau = new MaillonNoeud(val, tete);
    tete = nouveau;
  }
}

void ListeNoeud::SupprimerEnTete() {
  if (tete == nullptr) {
      return;
  }
  MaillonNoeud* tmp = tete;
  tete = tete->suiv;
  cout << "etat de la tête après supprimer en tete" << tete->info << endl;
  cout << "etat de la tête après supprimer en tete" << tete->info << endl;
}

ListeNoeud::~ListeNoeud()
{
  MaillonNoeud * tmp;
  
  while (tete != nullptr)
  {
    tmp = tete;
    tete = tete -> suiv;
    delete tmp;
  }
}


PileNoeud::PileNoeud(){
    L= new ListeNoeud();
}

PileNoeud::PileNoeud(ListeNoeud *list){
    L = list;
}


PileNoeud::PileNoeud(Noeud * T[], int taille){
    L = new ListeNoeud(T,taille);
}

Noeud * PileNoeud::getInfo() {
    return L->tete->info;
}

bool PileNoeud::Vide() {
    if (L == nullptr || L->tete == nullptr ) {
        return true;
    }
    else {
        return false;
    }
}

PileNoeud::~PileNoeud()
{
}

void PileNoeud::Afficher_pile(){
    if (!Vide()) {
        L->Afficher();
    }
    else {
        cout << "La pile est vide "<<endl;
    }
}

Noeud * PileNoeud::EmPilerNoeud(Noeud * val) {
    if (L == nullptr) {
        L = new ListeNoeud();
    }
    L->InsererEnTete(val);
    return L->tete->info; // Retourne un Noeud*
}

Noeud * PileNoeud::DePilerNoeud() {
    if (Vide()) {
        cout << "Attention : la pile est vide " << endl;
        return nullptr; // Retourne nullptr au lieu de "none"
    }
    else {
        Noeud * val = L->tete->info;
        Noeud* tmp = L->tete->info;
        L->tete = L->tete->suiv;
        delete tmp; // Libère la mémoire
        return val;
    }
}

Noeud::Noeud(double v){
    char type = 'f'; //‘f’ pour valeur.
    char ope = 0;
    double val = v;    // valeur si type == 'f'
    Noeud * fg = nullptr;
    Noeud * fd = nullptr;

}

Noeud::Noeud(char op, Noeud *g, Noeud *d){
    char type = 'o';
    char ope = op;
    double val = 0.0;
    Noeud * fg = g;
    Noeud * fd = d;
}

Noeud::~Noeud() {
    if (fg != nullptr) {
        delete fg;
    }
    if (fd != nullptr) {
        delete fd;
    }
}

Arbre::Arbre() {
    racine = nullptr;
}

Arbre::~Arbre() {
    if (this->racine != NULL) {
        delete this->racine;
    }
}
