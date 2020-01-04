//
//
//

#ifndef L3_MIAGE_MONOPOLY_PIOCHE_H
#define L3_MIAGE_MONOPOLY_PIOCHE_H


#include "caseMonopoly.h"
#include "../plateau/plateau.h"
#include "../joueur/joueur.h"

class pioche : public caseMonopoly{
public:
    pioche(const string& nom, int type);

    virtual ~pioche();

    virtual void action(joueur& j) override;   //pioche et affiche la carte

};


#endif //L3_MIAG{}E_MONOPOLY_PIOCHE_H
