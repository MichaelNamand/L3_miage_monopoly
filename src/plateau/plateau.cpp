//
//
//

#include "plateau.h"

plateau::plateau() {

}

void plateau::carteChance(joueur j) {

}

void plateau::carteCommunaute(joueur j) {

}

void plateau::sortirDePrison(joueur j) {

}

int *plateau::lancerDes(joueur j) const {
    return nullptr;
}

void plateau::mettreAuxEncheres() {

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

void plateau::lancerEchange() {

}

