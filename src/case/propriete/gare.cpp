//
//
//

#include "gare.h"

gare::gare(std::string &nom, int valeurHypotheque, int prix, std::vector<int>loyers):
    propriete{nom, valeurHypotheque, prix, loyers, DT_GARE} {
}

void gare::action(joueur &j) {
    propriete::choixActions(getLoyer(j));
}

int gare::getLoyer(joueur &j) const {
    return 0;
}

