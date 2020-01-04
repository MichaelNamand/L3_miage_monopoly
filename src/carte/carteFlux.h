//
//
//

#ifndef L3_MIAGE_MONOPOLY_CARTEFLUX_H
#define L3_MIAGE_MONOPOLY_CARTEFLUX_H

#include "carte.h"

class carteFlux : public carte {
public:
    carteFlux(const string &texte, int flux);

    void action(joueur &j) override;

private:
    int d_flux;

};


#endif //L3_MIAGE_MONOPOLY_CARTEFLUX_H
