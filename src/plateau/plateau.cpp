//
//
//

#include "plateau.h"
#include <cstdlib>

plateau::plateau() {

}

void plateau::sortirDePrison(joueur &j) {
    // j.mettreEnPrison(false);
    j.deplacerA(10, false); //se déplace sur la case visite de prison
}

vector<caseMonopoly> plateau::proprietesRestantes() const {
    vector<caseMonopoly> p;
    for(int i=0;i<d_cases.size();i++) {
        /*if(d_cases[i].getType() == DT_PROPRIETES) {
            if(d_cases[i].getJoueur() != nullptr) {
                p.push_back(d_cases[i]);
            }
        }*/
    }
    return p;
}

const queue<carte*> &plateau::getPiocheChance() const {
    return d_piocheChance;
}

const queue<carte*> &plateau::getPiocheCaisseCommunaute() const {
    return d_piocheCaisseCommunaute;
}

void plateau::piocherCarteChance(joueur &j) {
    carte *c = d_piocheChance.front();
    c->action(j);
    d_piocheChance.pop();
    d_piocheChance.push(c);
}

void plateau::piocherCarteCaisseCommunaute(joueur &j) {
    carte *cartePiochee = d_piocheCaisseCommunaute.front();
    d_piocheCaisseCommunaute.pop();
    cartePiochee->action(j);
    d_piocheCaisseCommunaute.push(cartePiochee);
}

