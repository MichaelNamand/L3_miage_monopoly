//
//
//

#ifndef L3_MIAGE_MONOPOLY_FLUXMONETAIRE_H
#define L3_MIAGE_MONOPOLY_FLUXMONETAIRE_H


#include "caseMonopoly.h"
#include "../joueur/joueur.h"

class fluxMonetaire : public caseMonopoly {
public:
    fluxMonetaire(const string& nom, int type);

    virtual ~fluxMonetaire();

    virtual void action(joueur& j) override;

};


#endif //L3_MIAGE_MONOPOLY_FLUXMONETAIRE_H
