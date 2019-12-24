//
//
//

#ifndef L3_MIAGE_MONOPOLY_ATTENTE_H
#define L3_MIAGE_MONOPOLY_ATTENTE_H


#include "caseMonopoly.h"

class attente : public caseMonopoly{
public:
    attente(const string& nom, int type);

    ~attente();

    virtual void action() override;
};


#endif //L3_MIAGE_MONOPOLY_ATTENTE_H
