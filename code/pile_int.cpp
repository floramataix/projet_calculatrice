#include <iostream>
using namespace std;
#include "pile_int.hpp"


ListeInt::ListeInt()
{
	tete = nullptr;
}


MaillonInt::MaillonInt()
{
	suiv = nullptr;
}

MaillonInt::MaillonInt(int val)
{
	info = val;
	suiv = nullptr;
}

MaillonInt::MaillonInt(int val, MaillonInt * suivant)
{
  info = val;
  suiv = suivant;
}

ListeInt::ListeInt(int T[], int taille)
{
  int i;
  MaillonInt * tmp;
  
  if (taille == 0)
  {   
    tete = nullptr;
    return;
  }
  tete = new MaillonInt(T[0]);
  tmp = tete;
  for (i = 1;i < taille; i++)
  {
    tmp -> suiv = new MaillonInt(T[i]);
    tmp = tmp -> suiv;
  }
}

ListeInt::ListeInt(int taille, int T[])
{
  int i;
  tete = nullptr;
  for (i = taille - 1;i >= 0; i--)
    tete = new MaillonInt(T[i], tete);
}

void ListeInt::Afficher()
{
	MaillonInt * tmp;
	tmp = tete;
	
	while (tmp != nullptr)
	{
		cout << tmp -> info << " ";
		tmp = tmp -> suiv;
	}
	cout << endl;
}

MaillonInt::~MaillonInt(){
  if (suiv != nullptr)
    delete suiv;
}

void ListeInt::InsererEnTete(int val) {
  if (tete == nullptr) {
    tete = new MaillonInt(val);
  } 
  else {

    MaillonInt* nouveau = new MaillonInt(val, tete);
    tete = nouveau;
  }
}

void ListeInt::SupprimerEnTete() {
  if (tete == nullptr) {
      return;
  }
  MaillonInt* tmp = tete;
  tete = tete->suiv;
  cout << "etat de la tête après supprimer en tete" << tete->info << endl;
  cout << "etat de la tête après supprimer en tete" << tete->info << endl;
}

ListeInt::~ListeInt()
{
  MaillonInt * tmp;
  
  while (tete != nullptr)
  {
    tmp = tete;
    tete = tete -> suiv;
    delete tmp;
  }
}

PileInt::PileInt(){
  L= new ListeInt();
}

PileInt::PileInt(ListeInt *list){
  L = list;
}


PileInt::PileInt(int T[], int taille){
  L = new ListeInt(T,taille);
}

int PileInt::getInfo() {
  return L->tete->info;
}

bool PileInt::Vide() {
  if (L == nullptr || L->tete == nullptr ) {
      return true;
  }
  else {
      return false;
  }
}

void PileInt::Afficher_PileInt(){ 
  if (!Vide()) {
      L->Afficher();
  }
  else {
      cout << "La pile est vide "<<endl;
  }
}

int PileInt::EmPileInt(int val) { 
  if (L == nullptr) {
      L = new ListeInt();
  }
  L->InsererEnTete(val);
  return L->tete->info;
}

int PileInt::DePileInt() {
  if (Vide()) {
      cout << "Attention : la pile est vide " << endl;
      return ;
  }
  else {
      int val = L->tete->info;
      MaillonInt* tmp = L->tete;
      L->tete = L->tete->suiv;
      return val;

  }
}

