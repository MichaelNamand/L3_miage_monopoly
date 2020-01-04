//
// Created by Administrator on 16.12.2019.
//

#include "carteAllerVers.h"
carteAllerVers::carteAllerVers(const string &texte, int cases) :
        carte{texte}, d_cases{cases} {}

void carteAllerVers::action(joueur &j) {
    int tmp = j.getIndexCase();
    if (tmp < d_cases) {
        j.deplacerA(d_cases - tmp, true);
    } else {

        j.deplacerA(40 - tmp + (d_cases + 1), true);
    }

}