#include <iostream>
using namespace std;
#include "liste_chainee.h"


Liste::Liste()
{
	tete = nullptr;
}


Maillon::Maillon()
{
	suiv = nullptr;
}

Maillon::Maillon(string val)
{
	info = val;
	suiv = nullptr;
}

Maillon::Maillon(string val, Maillon * suivant)
{
  info = val;
  suiv = suivant;
}

Liste::Liste(string T[], int taille)
{
  int i;
  Maillon * tmp;
  
  if (taille == 0)
  {   
    tete = nullptr;
    return;
  }
  tete = new Maillon(T[0]);
  tmp = tete;
  for (i = 1;i < taille; i++)
  {
    tmp -> suiv = new Maillon(T[i]);
    tmp = tmp -> suiv;
  }
}

Liste::Liste(int taille, string T[])
{
  int i;
  tete = nullptr;
  for (i = taille - 1;i >= 0; i--)
    tete = new Maillon(T[i], tete);
}

void Liste::Afficher()
{
	Maillon * tmp;
	tmp = tete;
	
	while (tmp != nullptr)
	{
		cout << tmp -> info << " ";
		tmp = tmp -> suiv;
	}
	cout << endl;
}

Maillon::~Maillon(){
  if (suiv != nullptr)
    delete suiv;
}

void Liste::InsererEnTete(string val) {
  if (tete == nullptr) {
    tete = new Maillon(val);
  } 
  else {

    Maillon* nouveau = new Maillon(val, tete);
    tete = nouveau;
  }
}

void Liste::SupprimerEnTete() {
  if (tete == nullptr) {
      return;
  }
  Maillon* tmp = tete;
  tete = tete->suiv;
  cout << "etat de la tête après supprimer en tete" << tete->info << endl;
  cout << "etat de la tête après supprimer en tete" << tete->info << endl;
}

Liste::~Liste()
{
  Maillon * tmp;
  
  while (tete != nullptr)
  {
    tmp = tete;
    tete = tete -> suiv;
    delete tmp;
  }
}
