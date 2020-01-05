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

const int NB_CASES_PLATEAU = 40;

class plateau {
public:
    plateau();
    vector<caseMonopoly> proprietesRestantes() const;
    void piocherCarte(joueur& j, int type);
    caseMonopoly &getCase(int index) const;

private:
    queue<carte*> d_piocheCaisseCommunaute;
    queue<carte*> d_piocheChance;
    vector<caseMonopoly*> d_cases;
};


#endif //L3_MIAGE_MONOPOLY_PLATEAU_H
