//
//
//

#ifndef L3_MIAGE_MONOPOLY_PIOCHE_H
#define L3_MIAGE_MONOPOLY_PIOCHE_H


#include "caseMonopoly.h"
#include "../carte/carte.h"
#include <vector>

class pioche : public caseMonopoly{
public:
    pioche(const string& nom, int type);

    virtual ~pioche();

    virtual void action() override;   //pioche et affiche la carte

private :
    vector <vector<carte*>> d_cartesPlateau;
    unsigned d_indexPioche[2];
};


#endif //L3_MIAG{}E_MONOPOLY_PIOCHE_H
