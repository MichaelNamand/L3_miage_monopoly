//
//
//

#ifndef L3_MIAGE_MONOPOLY_PLATEAU_H
#define L3_MIAGE_MONOPOLY_PLATEAU_H

#include <vector>
#include "../carte/carte.h"
#include "../case/caseMonopoly.h"
#include "../joueur/joueur.h"
#include "../case/propriete/propriete.h"


using std::vector;

class plateau {
public:
    plateau();
    void sortirDePrison(joueur j);
    vector<caseMonopoly> proprietesRestantes() const;
    const vector<carte>& getPiocheChance() const;
    const vector<carte>& getPiocheCaisseCommunaute() const;
    void piocherCarteChance(joueur& j);
    void piocherCarteCaisseCommunaute(joueur& j);
    
private:
    vector<carte> d_piocheCaisseCommunaute;
    vector<carte> d_piocheChance;
    vector<caseMonopoly> d_cases;
};


#endif //L3_MIAGE_MONOPOLY_PLATEAU_H
