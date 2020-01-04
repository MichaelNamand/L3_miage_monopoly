//
//
//

#include "servicePublic.h"

servicePublic::servicePublic(std::string nom, int valeurHypotheque, int prix, std::vector<int> loyers):
    propriete{nom, valeurHypotheque, prix, loyers}{

}

int servicePublic::getLoyer() const {
    return 0; // TODO
}

int servicePublic::getLoyer(int index) {
    return d_loyers[index];
}
