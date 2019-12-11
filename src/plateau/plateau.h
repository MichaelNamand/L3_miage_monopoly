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
    vector<case> casesDisponibles() const;
    bool estCaseDisponible() const;
    void carteChance(joueur j);
    void carteCommunaute(joueur j);
    void sortirDePrison(joueur j);
    int* lancerDes(joueur j) const;
    void mettreAuxEncheres();
    vector<propriete> proprietesRestantes() const;
    void lancerEchange();

private:
    vector<vector<carte>> d_pioches;
    vector<case> d_cases;
};


#endif //L3_MIAGE_MONOPOLY_PLATEAU_H
