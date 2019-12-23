//
//
//

#include "plateau.h"
#include <cstdlib>

plateau::plateau() {

}

void plateau::sortirDePrison(joueur j) {
    j.mettreEnPrison(false);
    j.deplacerA(10, false); //se déplace sur la case visite de prison
}


vector<caseMonopoly> plateau::proprietesRestantes() const {
    vector<caseMonopoly> p;
    for(int i=0;i<d_cases.size();i++) {
        if(d_cases[i].getType() == DT_PROPRIETES) {
            if(d_cases[i].getJoueur() != nullptr) {
                p.push_back(d_cases[i]);
            }
        }
    }
    return p;
}

