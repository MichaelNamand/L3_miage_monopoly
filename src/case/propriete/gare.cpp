//
//
//

#include "gare.h"

gare::gare(const std::string &nom, int valeurHypotheque, int prix,const std::vector<int>&loyers):
    propriete{nom, valeurHypotheque, prix, loyers, DT_GARE} {
}

void gare::action(joueur &j) {
    propriete::choixActions(getLoyer(j), j);
}

int gare::getLoyer(joueur &j) const {
    return d_loyers[j.getProprietes(DT_GARE).size() - 1];
}

