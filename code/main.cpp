#include <iostream> 
#include "pile_int.hpp"
#include "pile_str.hpp"
#include "pile_arbre.hpp"
using namespace std;

int main() {

  cout << "--------------------------\n";
    Pile * pile1 = new Pile();
    string Tab[5] = {"1","2","3","4","5"};
    Pile * pile2 = new Pile(Tab,5); 
  cout << "Exercice 1 : " << endl;
  cout << "--------------------------\n";
  cout << "Exercice 2 : " << endl;
  cout << "--------------------------\n";
  cout << "Exercice 3 : " << endl;
  cout << "--------------------------\n";
  cout << "Exercice 4 : " << endl;
  cout << "--------------------------\n";
  

    /*
    Pile * pile1 = new Pile();
    string Tab[5] = {"1","2","3","4","5"};
    Pile * pile2 = new Pile(Tab,5); 
    
    cout<< "La pile1 est elle vide ?  " << pile1->Vide()<< endl;
    cout<< "La pile2 est elle vide ?  " << pile2->Vide()<< endl;

    cout << "Pile avant empiler :"<< endl;
    pile2->Afficher_pile();
    pile2->Empiler("15");
    cout << "Pile apres empiler :"<< endl;
    pile2->Afficher_pile();
    cout << "Valeur qui est dépilé: :"<< endl;
    cout << pile2->Depiler() <<endl;
    cout << "Pile apres depiler :"<< endl;
    pile2->Afficher_pile();

    Pile *resultat = new Pile();
    string expr[5] = {"1","3","+"};
    cout << resultat->Evaluer(expr, 3) << endl;
    string expression2[12] = {"3", "+", "4", "*", "(", "2", "-", "1", "*", "6", "+", "8" };
    cout << Transform(expression2,12) <<endl;
    cout << "Le resultat est sensé etre : 3421-*6*+8" <<endl;
  
    
  string expression3[15] = {"3", "+", "5", "*", "(", "2", "-", "3", "+", "2", "*", "4", ")", "-", "9" };
  cout << Transform(expression3,15) <<endl;
  cout << "Le resultat est sensé etre : 523-24*+*+9-" <<endl;
  
  
  string expression[10] = {"(", "5", "*", "4", "+", "3", "*", ")", "-", "1" };
  cout << Transform(expression,10) <<endl;
  cout << "Le resultat est sensé etre : 54*3*+1- " <<endl;
 

 string expression[11] = {"a", "+", "(", "(", "b", "*", "4", ")", "/", "3", ")"};
 cout << Transform(expression, 11) << endl;


string expression[11] = {"a", "+", "(", "(", "b", "*", "4", ")", "/", "3", ")"};
cout << Transform(expression, 11) << endl;
Arbre(Transform(expression, 11), 11);

  Noeud* n1 = new Noeud(3.0); // Valeur 3
  Noeud* n2 = new Noeud(4.0); // Valeur 4
  Noeud* n3 = new Noeud('+', n1, n2); // n1 + n2

  Noeud* n4 = new Noeud(2.0); // Valeur 2
  Noeud* n5 = new Noeud('*', n3, n4); // (n1 + n2) * n4
  
  // Evaluation de l'expression (n1 + n2) * n4

  double resultat1 = n1->evaluer_noeud();
  cout << "Le résultat de l'expression est: " << resultat1 << endl;

  double resultat3 = n3->evaluer_noeud();
  cout << "Le résultat de l'expression est: " << resultat3 << endl;

  double resultat5 = n5->evaluer_noeud();
  cout << "Le résultat de l'expression est: " << resultat5 << endl;
 

   // Arbre A2(new Noeud('f',1.2));
  // cout << "le type est : " << endl;
  // cout << A2.getRacine()->getType() << endl;
  // Arbre A3(new Noeud('v','X'));
  // cout << "le type est : " << endl;
  // cout << A3.getRacine()->getType() << endl;


  

  // X + 3
  Arbre A1(new Noeud('o', '+', new Noeud('v', 'X'), new Noeud('f', 3.0)));

  Noeud * derivee_A1 = A1.getRacine()->Derivee('X'); //on calcule la derivee.

  string s1 = " ";
  cout << "affiche derivee : " <<endl;
  cout << derivee_A1->Transformer(s1) <<endl;  //on affiche.



  

  string s1 = " ";
  cout << "affiche avant la deriv : " <<endl;
  cout << A2.getRacine()->Transformer(s1) <<endl;  //on affiche avant deriv.



//2 * Y
Arbre A1(new Noeud('o', '*', new Noeud('f', 2.0), new Noeud('v', 'Y')));

string ss1 = " ";
cout << "avant deriv A1 : " <<endl;
cout << A1.getRacine()->Transformer(ss1) <<endl;  //on affiche.
Noeud *derivee_A1 = A1.getRacine()->Derivee('Y');
string s1 = " ";
cout << "derivee de A1 en fonction de Y : " << derivee_A1->Transformer(s1) << endl;


//4 * X^2

Arbre A2(new Noeud('o', '*', new Noeud('f', 4.0), new Noeud('o', '^', new Noeud('v', 'X'), new Noeud('f', 2.0))));

string ss2 = " ";
cout << "avant deriv A2 : " <<endl;
cout << A2.getRacine()->Transformer(ss2) <<endl;  //on affiche.

Noeud *derivee_A2 = A2.getRacine()->Derivee('X');

string s2 = " ";
cout << "derivee de A2 en fonction de X: " << derivee_A2->Transformer(s2) << endl;


// 4 * X ^2 - 2 * Y + (-Z)
Arbre A3(new Noeud('o','-', new Noeud('o','*', new Noeud('f', 4.0), new Noeud('o','^', new Noeud('v', 'X'),new Noeud('f', 2.0))),
  new Noeud('o','+',new Noeud('o','*',new Noeud('f', 2.0),new Noeud('v', 'Y')),new Noeud('o','-',new Noeud('f',0.0),new Noeud('v', 'Z')))));

string s = " ";
cout << "avant deriv A3 : " <<endl;
cout << A3.getRacine()->Transformer(s) <<endl;  //on affiche.

Noeud * derivee_A3 = A3.getRacine()->Derivee('X'); //on calcule la derivee.

string s3 = " ";
cout << "derivee A3 en fonction de X : " <<endl;
cout << derivee_A3->Transformer(s2) <<endl;  //on affiche deriv.

*/

}

