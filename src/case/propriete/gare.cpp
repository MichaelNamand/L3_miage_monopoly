//
//
//

#include "gare.h"

gare::gare(std::string &nom, int valeurHypotheque, int prix, std::vector<int>loyers):
    propriete{nom, valeurHypotheque, prix, loyers} {
}

void gare::action(joueur *j) {
    propriete::choixActions();
}

