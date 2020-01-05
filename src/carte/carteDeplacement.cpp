//
//
//
#include <iostream>
#include "carteDeplacement.h"
#include "../joueur/joueur.h"


carteDeplacement::carteDeplacement(const string &texte, int cases, bool sensNormal) :
        carte{texte}, d_cases{cases}, d_sensNormal{sensNormal} {}

void carteDeplacement::action(joueur &j) {
    std::cout << afficheCarte() << std::endl;

    if(d_cases < j.getIndexCase()) {
        j.gagnerSalaire();
    }
    j.setIndexCase(d_cases);
}