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
    servicePublic(const std::string &nom, int prix);
    int getLoyer(joueur &j) const override;
    void action(joueur &j) override;
};


#endif //L3_MIAGE_MONOPOLY_SERVICEPUBLIC_H
