//
//
//

#include <iostream>
#include "carteAllerEnPrison.h"
#include "../joueur/joueur.h"

carteAllerEnPrison::carteAllerEnPrison(const string &texte) :
        carte{texte} {}

void carteAllerEnPrison::action(joueur j) {
    int tmp = j.getIndexCase();
    int casePrison = 10;
    if (j.estEnPrison()) {
        std::cout << "Deja en prison";

    } else {
        j.seDeplacer(casePrison - tmp);

        j.mettreEnPrison(true);

    }

}