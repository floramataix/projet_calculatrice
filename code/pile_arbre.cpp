#include <iostream> 
#include <string>
#include "pile_arbre.hpp"
#include "pile_str.hpp"
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


void ListeNoeud::Afficher_listenoeud()
{
    MaillonNoeud * tmp;
    tmp = tete;
    
    while (tmp != nullptr)
    {
        cout << tmp -> info->val << " ";
        tmp = tmp -> suiv;
    }
    cout << endl;
}

MaillonNoeud::~MaillonNoeud(){
  if (info)
    delete info;
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
    delete tmp; // Libère la mémoire
    if (tete != nullptr) {
        cout << "Nouvelle tête : " << tete->info << endl;
    } 
    else {
        cout << "La liste est maintenant vide." << endl;
    }
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
    if (L == nullptr || L->tete == nullptr) {
        return nullptr; }
    return L->tete->info;
}

bool PileNoeud::VideArbre() {
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

void PileNoeud::Afficher_noeud(){
    if (!VideArbre()) {
        L->Afficher_listenoeud();
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
    if (VideArbre()) {
        cout << "Attention : la pile est vide " << endl;
        return nullptr; // Retourne nullptr au lieu de "none"
    }
    else {
        Noeud * val = L->tete->info;
        MaillonNoeud* tmp = L->tete;
        L->tete = L->tete->suiv;
        //delete tmp; // Libère uniquement le maillon
        return val;
    }
}

Noeud::Noeud(char type,double v){
    type = type; //‘f’ pour valeur.
    ope = 0;
    val = v;    // valeur si type == "f"
    fg = nullptr;
    fd = nullptr;
}

Noeud::Noeud(char type,char op, Noeud *g, Noeud *d){
    type = type;
    ope = op;
    val = 0.0;
    fg = g;
    fd = d;
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

Arbre::Arbre(string expr[], int taille){    ///constructeur d'arbre.
    PileNoeud P;
    for (int i = 0; i < taille; i++ ){
        cout << i << endl;
        cout << expr[i] <<endl;
        if (expr[i] == "+" || expr[i] == "-" || expr[i] == "*" || expr[i] == "/" ) {
            if (!P.VideArbre()) {
                Noeud* droite = P.DePilerNoeud();
                if (!P.VideArbre()) {
                    Noeud* gauche = P.DePilerNoeud();
                    Noeud* operateur = new Noeud('o',expr[i][0], gauche, droite);
                P.EmPilerNoeud(operateur);
                }
            }
        }
        else { 
            Noeud* n = new Noeud('f',stod(expr[i]));
            P.EmPilerNoeud(n);
        }
    }
    if (!P.VideArbre()) {
        racine = P.DePilerNoeud();} 
}

double Noeud::evaluer_noeud() {     //Transforme une expression infixée en une expression suffixée

    if (type == 'f') { //c'est une operande seule
        return val;
    }

    else if (type == 'o') {  // opérateur 
        double gauche = fg->evaluer_noeud();
        double droite = fd->evaluer_noeud();

    // On applique l'opération selon le type d'opérateur
        if (ope == '+') {
            return gauche + droite;}
        else if (ope == '-') {
            return gauche - droite;}
        else if (ope == '*') {
            return gauche * droite;}
        else if (ope == '/') {
            if (droite != 0) {
                return gauche / droite;}
            else {
                cout<<"pas possible de diviser par 0"<<endl;
                return 0;
            }
        }
        else {
            return 0;   // si le type est 'o' mais operatuer diff de +-*/
        }
    }
    else {
        return 0;   // si le type est different de 'f' ou 'o' 
    }
}

Arbre::~Arbre() {
    if (this->racine != NULL) {
        racine->~Noeud();
        delete this-> racine;
    }
    
}

string Noeud::Transformer(string expr){
    if(fg){
        if(fg->type == 'f'){
            expr += to_string(fg->val);
        }
        else if(fg->type == 'v'){
            expr += fg->val;
        }
        else{
            expr += "(";
            expr = fg->Transformer(expr);
            expr += ")";
        }
    }
    expr += ope;
    if(fd){
        if(fd->type == 'f'){
            expr += to_string(fd->val);
        }
        else if(fd->type == 'v'){
            expr += fd->val;
        }
        else{
            expr += "(";
            expr = fd->Transformer(expr);
            expr += ")";
        }
    }
    return expr;
}