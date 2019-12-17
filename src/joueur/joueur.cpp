//
//
//

#include "joueur.h"

bool joueur::estEnPrison() const {
    return d_enPrison;
}

const string &joueur::getNom() const {
    return d_nom;
}

int joueur::getArgent() const {
    return d_argent;
}

int joueur::getIndexCase() const {
    return d_indexCase;
}

const vector<carteSortiePrison> &joueur::getCartesSortiePrison() const {
    return d_cartesSortiePrison;
}

const vector<propriete> &joueur::getProprietes() const {
    return d_proprietes;
}

const vector<propriete> &joueur::getRues() const {
    vector<propriete()> p;
    for(int i=0;i<d_proprietes.size();i++) {
        if(d_proprietes[i].getType() == DT_RUES) {
            if(d_proprietes[i].getJoueur() != nullptr) {
                p.push_back(d_proprietes[i]);
            }
        }
    }
    return p;
}

const vector<propriete> &joueur::getGares() const {
    return <#initializer#>;
}

const vector<propriete> &joueur::getServicePublic() const {
    return <#initializer#>;
}

void joueur::vendreMaison() {

}

void joueur::hypothequer() {

}

void joueur::seDeplacer(int nbCases) {

}
