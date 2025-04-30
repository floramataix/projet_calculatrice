#include <iostream> 
#include "pile.hpp"
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
  */

    string expression[10] = {"(", "5", "*", "4", "+", "3", "*", ")", "-", "1" };

    
    cout << Transform(expression,10) <<endl;

 
}
