//
//
//

#ifndef L3_MIAGE_MONOPOLY_CARTEALLERENPRISON_H
#define L3_MIAGE_MONOPOLY_CARTEALLERENPRISON_H


#include "carte.h"

class carteAllerEnPrison : public carte {
public:
    carteAllerEnPrison(const string &texte);

    void action(joueur &j) override;
};


#endif //L3_MIAGE_MONOPOLY_CARTEALLERENPRISON_H
