//
//
//

#ifndef L3_MIAGE_MONOPOLY_PLATEAU_H
#define L3_MIAGE_MONOPOLY_PLATEAU_H

#include <queue>
#include <vector>
#include "../carte/carte.h"
#include "../case/caseMonopoly.h"
#include "../joueur/joueur.h"
#include "../case/propriete/propriete.h"


using std::queue;
using std::vector;

class plateau {
public:
    plateau();
    void sortirDePrison(joueur j);
    vector<caseMonopoly> proprietesRestantes() const;
    const queue<carte>& getPiocheChance() const;
    const queue<carte>& getPiocheCaisseCommunaute() const;
    void piocherCarteChance(joueur& j);
    void piocherCarteCaisseCommunaute(joueur& j);
    
private:
    queue<carte> d_piocheCaisseCommunaute;
    queue<carte> d_piocheChance;
    vector<caseMonopoly> d_cases;
};


#endif //L3_MIAGE_MONOPOLY_PLATEAU_H
