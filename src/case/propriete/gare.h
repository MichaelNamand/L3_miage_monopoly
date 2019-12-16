//
//
//

#ifndef L3_MIAGE_MONOPOLY_GARE_H
#define L3_MIAGE_MONOPOLY_GARE_H

#include <vector>
#include "propriete.h"

class gare: public propriete {

public:
    gare(std::string &nom, int valeurHypotheque, int prix, std::vector<int> loyers);
    void action(joueur *j) override;
};


#endif //L3_MIAGE_MONOPOLY_GARE_H
