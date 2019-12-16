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
        if (tmp < casePrison) {
            j.seDeplacer(casePrison - tmp);
        } else {

            j.seDeplacer(tmp - casePrison);
        }
        // j.setEnPrison(true);

    }

}