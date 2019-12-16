//
//
//

#include "gare.h"

void gare::action() {
    propriete::action();
}

gare::gare(std::string &nom, int valeurHypotheque, int prix, std::vector<int>loyers):
    propriete{nom, valeurHypotheque, prix, loyers} {
}
