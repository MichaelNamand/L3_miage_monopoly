//
//
//

#include "servicePublic.h"

servicePublic::servicePublic(const std::string &nom, int valeurHypotheque, int prix):
    propriete{nom, valeurHypotheque, prix, {}, DT_SERVICE_PUBLIC}{

}

void servicePublic::action(joueur &j) {
    propriete::action(j);
    propriete::choixActions(getLoyer(j), j);
}

int servicePublic::getLoyer(joueur &j) const {
    if (j.getProprietes(DT_SERVICE_PUBLIC).size() == 2) {
        return j.getDernierLanceDes() * 10;
    } else {
        return j.getDernierLanceDes() * 4;
    }
}
