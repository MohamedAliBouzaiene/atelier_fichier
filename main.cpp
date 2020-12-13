#include <iostream>
#include "fichier.h"

using namespace std;

int main()
{
    fichier F;
    string var;
    int choix;

    do{
        cout << "choisir une fonction: " << endl << endl;
        cout << "1- Chercher une adresse mail" << endl;
        cout << "2- Chercher une chaine de caracteres" << endl;
        cout << "0- Quitter" << endl << endl;
        cin >> choix;

        switch(choix){
            case 1:
                cout << "ecrire votre adresse mail" << endl;
                cin >> var;
                F.chercherAdresse(var);
                break;

            case 2:
                cout << "ecrire quelque chose a chercher" << endl;
                cin >> var;
                F.chercherString(var);
                break;
            case 0:
                return 0;
                break;
        }
    }
    while(choix!=0);
    return 0;
}
