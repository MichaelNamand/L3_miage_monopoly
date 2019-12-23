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

vector<int> joueur::lancerDes() const {
    srand (time(NULL));
    vector<int> des;
    des.push_back(rand() % 6 + 1);
    des.push_back(rand() % 6 + 1);
    return des;
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

void joueur::gagnerSalaire() {
    d_argent += 200;
}

void joueur::deplacerA(int indexCase, bool enAvancant) {
    if(enAvancant && indexCase < d_indexCase)
        gagnerSalaire();
    d_indexCase = indexCase;
}

void joueur::mettreEnPrison(bool prison) {
    d_enPrison = prison;
}