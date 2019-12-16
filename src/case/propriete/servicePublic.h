//
//
//

#ifndef L3_MIAGE_MONOPOLY_SERVICEPUBLIC_H
#define L3_MIAGE_MONOPOLY_SERVICEPUBLIC_H

#include <string>
#include <vector>
#include "propriete.h"

class servicePublic: public propriete {
public:
    servicePublic(std::string nom, int valeurHypotheque, int prix, std::vector<int> loyers);
    int getLoyer() const override;
    void action(joueur *j) override;
};


#endif //L3_MIAGE_MONOPOLY_SERVICEPUBLIC_H
