//
//
//

#include <iostream>
#include "carteAllerEnPrison.h"
#include "../joueur/joueur.h"
#include "../jeu.h"

using namespace std;

carteAllerEnPrison::carteAllerEnPrison(const string &texte) :
        carte{texte} {}

void carteAllerEnPrison::action(joueur &j) {
    std::cout << afficheCarte() << std::endl;
    j.setEnPrison(true);
    jeu::continuerJoueur();
}