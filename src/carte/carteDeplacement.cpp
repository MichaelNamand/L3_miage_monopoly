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

    j.deplacerA(d_cases, d_sensNormal);
}