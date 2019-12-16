//
//
//

#ifndef L3_MIAGE_MONOPOLY_CASEMONOPOLY_H
#define L3_MIAGE_MONOPOLY_CASEMONOPOLY_H

#include <string>

#define DT_PIOCHE 1
#define DT_PROPRIETE 2
#define DT_FLUX 3
#define DT_ALLERPRISON 4
#define DT_ATTENTE 5

using std::string;

class caseMonopoly {
public :
    caseMonopoly(const string& nom, const int type);

    virtual ~caseMonopoly();

    virtual void action() = 0;
    string afficheCase() const;

private :
    const string d_nom;
    const int d_type;
};


#endif //L3_MIAGE_MONOPOLY_CASEMONOPOLY_H
