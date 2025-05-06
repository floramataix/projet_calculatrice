#include <iostream> 
#include "pile_int.hpp"
#include "pile_str.hpp"
#include "pile_arbre.hpp"
using namespace std;

int main() {

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
Arbre(Transform(expression, 11), 11);*/

  Noeud* n1 = new Noeud(3.0); // Valeur 3
  Noeud* n2 = new Noeud(4.0); // Valeur 4
  Noeud* n3 = new Noeud('+', n1, n2); // n1 + n2

  Noeud* n4 = new Noeud(2.0); // Valeur 2
  Noeud* n5 = new Noeud('*', n3, n4); // (n1 + n2) * n4

  // Evaluation de l'expression (n1 + n2) * n4

  double resultat1 = n1->evaluer_noeud();
  std::cout << "Le résultat de l'expression est: " << resultat1 << std::endl;

  double resultat3 = n3->evaluer_noeud();
  std::cout << "Le résultat de l'expression est: " << resultat3 << std::endl;

  double resultat5 = n5->evaluer_noeud();
  std::cout << "Le résultat de l'expression est: " << resultat5 << std::endl;

}




