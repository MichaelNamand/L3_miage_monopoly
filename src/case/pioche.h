//
//
//

#ifndef L3_MIAGE_MONOPOLY_PIOCHE_H
#define L3_MIAGE_MONOPOLY_PIOCHE_H

#define DT_COMMUNAUTE 1
#define DT_CHANCE 2

#include "caseMonopoly.h"
#include "../plateau/plateau.h"
#include "../joueur/joueur.h"

class pioche : public caseMonopoly{
public:
    pioche(const string& nom, int type, plateau *plateau);

    virtual ~pioche();

    virtual void action(joueur& j) override;   //pioche et affiche la carte
private:
    plateau *d_plateau;
};


#endif //L3_MIAG{}E_MONOPOLY_PIOCHE_H
