//
//
//

#ifndef L3_MIAGE_MONOPOLY_GARE_H
#define L3_MIAGE_MONOPOLY_GARE_H

#include <vector>
#include "propriete.h"

class gare: public propriete {

public:
    gare(std::vector<int> loyers);
    int getLoyer(int index) override;
};


#endif //L3_MIAGE_MONOPOLY_GARE_H
