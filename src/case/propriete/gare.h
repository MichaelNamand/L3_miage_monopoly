//
//
//

#ifndef L3_MIAGE_MONOPOLY_GARE_H
#define L3_MIAGE_MONOPOLY_GARE_H

#include <vector>
#include "propriete.h"

class gare: public propriete {

public:
    gare(const std::string &nom, int prix,const std::vector<int> &loyers);
    void action(joueur &j) override;
    int getLoyer(joueur &j) const override;
};


#endif //L3_MIAGE_MONOPOLY_GARE_H
