//
//
//

#ifndef L3_MIAGE_MONOPOLY_FLUXMONETAIRE_H
#define L3_MIAGE_MONOPOLY_FLUXMONETAIRE_H


#include "caseMonopoly.h"

class fluxMonetaire : public caseMonopoly {
public:
    fluxMonetaire();

    virtual ~fluxMonetaire();

    virtual void action() override;

};


#endif //L3_MIAGE_MONOPOLY_FLUXMONETAIRE_H
