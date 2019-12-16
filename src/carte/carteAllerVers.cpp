//
// Created by Administrator on 16.12.2019.
//

#include "carteAllerVers.h"
carteAllerVers::carteAllerVers(const string &texte, int cases) :
        carte{texte}, d_cases{cases} {}

void carteAllerVers::action(joueur j) {
    int tmp = j.getIndexCase();
    if (tmp < d_cases) {
        j.seDeplacer(d_cases - tmp);
    } else {

        j.seDeplacer(40 - tmp + (d_cases + 1));
    }

}