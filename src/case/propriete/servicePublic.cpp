//
//
//

#include "servicePublic.h"

servicePublic::servicePublic(std::string nom, int valeurHypotheque, int prix, std::vector<int> loyers):
    propriete{nom, valeurHypotheque, prix, loyers, DT_SERVICE_PUBLIC}{

}

void servicePublic::action(joueur &j) {
    propriete::action(j);
}

int servicePublic::getLoyer(joueur &j) const {
    return d_loyers[0];
}
