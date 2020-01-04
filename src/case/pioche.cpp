//
//
//

#include "pioche.h"
#include <iostream>
#include "../plateau/plateau.h"
using namespace std;

pioche::pioche(const string& nom, int type, plateau *plateau) : caseMonopoly{nom, type}, d_plateau{plateau}
{}

pioche::~pioche() {}

void pioche::action(joueur& j) {
    string typePioche;
    if (getType() == DT_COMMUNAUTE) {
        typePioche = "Chance";
    } else {
        typePioche = "Caisse de communaute";
    }
    cout << "Vous venez de piocher une carte " << typePioche << " contenant l'information suivante :" << endl;
   d_plateau->piocherCarte(j, getType() );
}