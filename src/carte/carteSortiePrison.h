//
//
//

#ifndef L3_MIAGE_MONOPOLY_CARTESORTIEPRISON_H
#define L3_MIAGE_MONOPOLY_CARTESORTIEPRISON_H


#include "carte.h"

class carteSortiePrison : public carte {
public:
    carteSortiePrison(const string &texte);

    void action(joueur &j) override;

};


#endif //L3_MIAGE_MONOPOLY_CARTESORTIEPRISON_H
