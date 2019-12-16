//
//
//

#ifndef L3_MIAGE_MONOPOLY_PIOCHE_H
#define L3_MIAGE_MONOPOLY_PIOCHE_H


#include "caseMonopoly.h"
#include "../carte/carte.h"

class pioche : public caseMonopoly{
public:
    pioche();

    virtual ~pioche();

    virtual void action() override;   //pioche une carte et affiche le contenu

private :
    vector <vector<carte*>> d_pioches;
};


#endif //L3_MIAGE_MONOPOLY_PIOCHE_H
