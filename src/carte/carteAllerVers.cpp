//
// Created by Administrator on 16.12.2019.
//

#include "carteAllerVers.h"
#include <iostream>

carteAllerVers::carteAllerVers(const string &texte, int cases) :
        carte{texte}, d_cases{cases} {}

void carteAllerVers::action(joueur &j) {
    std::cout << afficheCarte() << std::endl;
    j.deplacerDe(d_cases);
}