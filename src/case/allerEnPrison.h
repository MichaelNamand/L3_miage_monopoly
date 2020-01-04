//
//
//

#ifndef L3_MIAGE_MONOPOLY_ALLERENPRISON_H
#define L3_MIAGE_MONOPOLY_ALLERENPRISON_H


#include "caseMonopoly.h"
#include "../joueur/joueur.h"

class allerEnPrison : public caseMonopoly {

public :
    allerEnPrison(const string& nom, int type);

    virtual ~allerEnPrison();

    void action(joueur& j) override; //emmenerEnPrison


};


#endif //L3_MIAGE_MONOPOLY_ALLERENPRISON_H
