//
//
//

#include "gare.h"
#include <iostream>

gare::gare(const std::string &nom, int prix,const std::vector<int>&loyers):
    propriete{nom, prix, loyers, DT_GARE} {
}

void gare::action(joueur &j) {
    propriete::action(j);
    propriete::choixActions(getLoyer(j), j);
}

int gare::getLoyer(joueur &j) const {
    if (getProprietaire())
        return d_loyers[getProprietaire()->getProprietes(DT_GARE).size() - 1];
    else
        return getPrix();
}

