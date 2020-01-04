//
//
//

#ifndef L3_MIAGE_MONOPOLY_CASEMONOPOLY_H
#define L3_MIAGE_MONOPOLY_CASEMONOPOLY_H

#include <string>
class joueur;

#define DT_PIOCHE 1
#define DT_RUE 2
#define DT_GARE 3
#define DT_SERVICE_PUBLIC 4
#define DT_FLUX 5
#define DT_ALLERPRISON 6
#define DT_ATTENTE 7

using std::string;

class caseMonopoly {
public :
    caseMonopoly(const string& nom, int type);

    virtual ~caseMonopoly();

    virtual void action(joueur &j) = 0;
    string afficheCase() const;
    int getType() const;

private :
    const string d_nom;
    const int d_type;
};


#endif //L3_MIAGE_MONOPOLY_CASEMONOPOLY_H
