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

PileNoeud::~PileNoeud(){

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

Noeud::Noeud(){
    this->type = ' '; // rien car vide .
    this->ope = ' ';
    this->val = 0.0;    
    this->var = ' ';
    this->fg = nullptr;
    this->fd = nullptr;
}

Noeud::Noeud(char type,double val){
    this->type = type; //‘f’ pour valeur.
    this->ope = ' ';
    this->val = val;    // valeur si type == "f"
    this->var = ' ';
    this->fg = nullptr;
    this->fd = nullptr;
}

Noeud::Noeud(char type,char var){
    this->type = type; //‘v’ pour valeur.
    this->ope = ' ';
    this->val = 0.0;    
    this->var = var;    // valeur si type == "v"
    this->fg = nullptr;
    this->fd = nullptr;
}

Noeud::Noeud(char type,char op, Noeud *g, Noeud *d){
    this->type = type;  //‘o’ pour valeur.
    this->ope = op;     // operateur si type == "o"
    this->val = 0.0;
    this->var = ' ';
    this->fg = g;
    this->fd = d;
}

char Noeud::getType(){   
    if (this->type == ' ') {
        cout << "ici ca va pas " <<endl;}
    return this->type;
}

Noeud *Noeud::getFg() {
    if (fg == nullptr) {
        cout << "Erreur : pas de fils gauche." << endl;
    } else {
        cout << "Fils gauche trouvé, type : " << fg->getType() << endl;
    }
    return this->fg;
}

Noeud *Noeud::getFd(){
    if (fd == nullptr) {
        cout << "Erreur : pas de fils droit." << endl;
    } else {
        cout << "Fils droit trouvé, type : " << fd->getType() << endl;
    }
    return this->fd;
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

Arbre::Arbre(Noeud * n){
    racine = n;
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

Noeud *Arbre::getRacine(){
    if (racine == nullptr) {
        cout << " erreur il n'y a pas de racine." <<endl;
    }
    return this->racine;
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
        return 0;   // si le type est different de 'f' ou 'o' ou 'v'
    }
}

Arbre::~Arbre() {
    if (this->racine != NULL) {
        delete this-> racine;
    }
}

string Noeud::Transformer(string expr){
    if(this->fg){
        if(this->fg->type == 'f'){
            expr += to_string(fg->val);
        }
        else if(this->fg->type == 'v'){
            expr += fg->var;
        }
        else{
            expr += "(";
            expr = this->fg->Transformer(expr);
            expr += ")";
        }
    }
    expr += ope;
    if(fd){
        if(fd->type == 'f'){
            expr += to_string(fd->val);
        }
        else if(fd->type == 'v'){
            expr += fd->var;
        }
        else{
            expr += "(";
            expr = fd->Transformer(expr);
            expr += ")";
        }
    }
    return expr;
}

Noeud * Noeud::copie() {
    Noeud * copie_gauche = nullptr;
    Noeud * copie_droite = nullptr;
    if (fg != nullptr) {
        copie_gauche = fg->copie();
    }
    if (fd != nullptr) {
        copie_droite = fd->copie();
    }
    if (this->type == 'f') {
        return new Noeud(type, val);
    }
    if (this->type == 'o') {
        return new Noeud(type, ope, copie_gauche, copie_droite);
    }
    if (this->type == 'v') {
        return new Noeud(type, var);
    }
    else {
        cout<< "Un probleme ici (copie)" <<endl;
        return new Noeud('f',0.0) ;
    }
    
}

Noeud* Noeud::Derivee(char variable){

    if (this->type == 'f') {
        return new Noeud('f',0.0);
    }

    else if (this->type == 'v') {
        if (this->var == variable){
            return new Noeud('f', 1.0);
        } else {
            return new Noeud('f', 0.0);  // variable différente, dérivée = 0
        }
    }    

    else if (this->type == 'o'){
        if (ope == '+'){
            
            Noeud * a = fg->Derivee(variable);
            Noeud * b = fd->Derivee(variable);
            return new Noeud ('o','+', a, b);
        }
        else if (ope == '-'){
            
            Noeud * a = fg->Derivee(variable);
            Noeud * b = fd->Derivee(variable);
            return new Noeud ('o','-', a, b);
        }
        else if (ope == '*'){    //u*v = u'v+uv'
            
            Noeud * u = fg->copie();
            Noeud * v = fd->copie();
            Noeud * uprime = fg->Derivee(variable);
            Noeud * vprime = fd->Derivee(variable);

            Noeud * gauche = new Noeud('o','*',uprime,v);
            Noeud * droit = new Noeud('o','*',u,vprime);
            return new Noeud('o','+',gauche,droit);
        }
        else if (ope == '/'){    //u*v = (u'v-uv')/v2
            
            Noeud * u = fg->Derivee(variable);
            Noeud * v = fd->Derivee(variable);
            Noeud * uprime = fg->copie();
            Noeud * vprime = fd->copie();

                Noeud * fois1 = new Noeud ('o', '*', uprime, v);
                Noeud * fois2 = new Noeud ('o', '*', u, vprime);
            Noeud * moins = new Noeud ('o','-',fois1,fois2);
            Noeud * expo = new Noeud ('o', '^', v, new Noeud ('f', 2.0));
            return new Noeud('o', '/', moins, expo);
        }
        else if (ope == '^'){    //(u^n)’= n*u’*u^(n-1)
            
            Noeud * uprime = this -> fg -> Derivee(variable);
            Noeud * u = this -> fg -> copie();
            Noeud * n = this -> fd -> copie();
            Noeud *nmoinsun = new Noeud('f', n->val - 1); // Crée une nouvelle copie avec n - 1
            return new Noeud('o', '*', new Noeud('o', '*', n, uprime), new Noeud('o', '^', u, nmoinsun));
            return new Noeud('o', '*', new Noeud('o', '*', uprime, n), new Noeud('o', '^', u, nmoinsun));
        }

        else {
            return new Noeud('f',0.0);
        }
    }
    else {
        cout<< "Un probleme est survenu" <<endl;
        return new Noeud('f',0.0) ;
    } 
}

