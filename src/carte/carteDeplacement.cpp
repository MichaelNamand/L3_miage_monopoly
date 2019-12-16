//
//
//

#include "carteDeplacement.h"


carteDeplacement::carteDeplacement(const string &texte, int cases) :
        carte{texte}, d_cases{cases} {}

void carteDeplacement::action(joueur j) {

    j.seDeplacer(d_cases);

}