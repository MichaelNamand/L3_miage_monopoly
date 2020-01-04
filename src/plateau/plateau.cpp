//
//
//

#include "plateau.h"
#include <fstream>
#include <iostream>

using namespace std;

#include "../joueur/joueur.h"
#include "../case/propriete/rue.h"
#include "../case/pioche.h"
#include "../carte/carteAllerEnPrison.h"
#include "../case/propriete/servicePublic.h"
#include "../case/propriete/gare.h"
#include "../case/attente.h"

plateau::plateau() {
    d_cases.push_back(new rue{"Boulevard de Belleville", DT_MARRON, 30, 60, {1, 2, 4, 8}, 2, 100, 200});
    d_cases.push_back(new pioche{"Caisse de communaute", DT_COMMUNAUTE, this});
    d_cases.push_back(new rue{"Rue Lecourbe", DT_MARRON, 40, 70, {2, 3, 5, 9}, 2, 100, 200});
    d_cases.push_back(new servicePublic{"Compagnie de distribution d'electricite", 75, 140});
    d_cases.push_back(new gare{"Gare de Lyon", 75, 140, {25, 50, 100, 200}});
    d_cases.push_back(new pioche{"Chance", DT_CHANCE, this});
    d_cases.push_back(new attente{"Depart", DT_ATTENTE});

    d_piocheChance.push(new carteAllerEnPrison{"Interpol vous a attrape. Allez en prison et ne passez pas par la case Depart"});
    d_piocheCaisseCommunaute.push(new carteAllerEnPrison{"Interpol vous a attrape. Allez en prison et ne passez pas par la case Depart"});
}

void plateau::sortirDePrison(joueur &j) {
    // j.mettreEnPrison(false);
    j.deplacerA(10, false); //se déplace sur la case visite de prison
}

vector<caseMonopoly> plateau::proprietesRestantes() const {
    vector<caseMonopoly> p;
    for (int i = 0; i < d_cases.size(); i++) {
        /*if(d_cases[i].getType() == DT_PROPRIETES) {
            if(d_cases[i].getJoueur() != nullptr) {
                p.push_back(d_cases[i]);
            }
        }*/
    }
    return p;
}

const queue<carte *> &plateau::getPiocheChance() const {
    return d_piocheChance;
}

const queue<carte *> &plateau::getPiocheCaisseCommunaute() const {
    return d_piocheCaisseCommunaute;
}

void plateau::piocherCarte(joueur &j, int type) {
    carte *c;
    if (type == DT_COMMUNAUTE){
        c = d_piocheChance.front();
    }
    else {
        c = d_piocheCaisseCommunaute.front();
    }
    c->action(j);
    if (type == DT_COMMUNAUTE){
        d_piocheCaisseCommunaute.pop();
        d_piocheCaisseCommunaute.push(c);
    } else {
        d_piocheChance.pop();
        d_piocheChance.push(c);
    }
}

caseMonopoly &plateau::getCase(int index) const {
    return *d_cases[index];
}

vector<caseMonopoly *> plateau::getCases() const {
    return d_cases;
}

