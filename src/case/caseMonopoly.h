//
//
//

#ifndef L3_MIAGE_MONOPOLY_CASEMONOPOLY_H
#define L3_MIAGE_MONOPOLY_CASEMONOPOLY_H

#include <string>
#include "../joueur/joueur.h"

const int DT_PIOCHE = 1;
const int DT_PROPRIETE = 2;
const int DT_FLUX = 3;
const int DT_ALLERPRISON = 4;
const int DT_ATTENTE = 5;

using std::string;

class caseMonopoly {
public :
    caseMonopoly(const string& nom, int type);

    virtual ~caseMonopoly();

    virtual void action(joueur &j) = 0;
    string afficheCase() const;

private :
    const string d_nom;
    const int d_type;
};


#endif //L3_MIAGE_MONOPOLY_CASEMONOPOLY_H
