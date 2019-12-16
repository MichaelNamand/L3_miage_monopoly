//
//
//

#include "joueur.h"

bool joueur::estEnPrison() const {
    return d_enPrison;
}

string joueur::getNom() const {
    return d_nom;
}

int joueur::getArgent() const {
    return d_argent;
}

int joueur::getIndexCase() const {
    return d_indexCase;
}

vector<carteSortiePrison> joueur::getCartesSortiePrison() const {
    return d_cartesSortiePrison;
}

void joueur::ajouterPropriete(propriete &propriete) {
    d_proprietes.push_back(propriete);
}


vector<propriete> joueur::getPropriete(string typeNom) const {
    vector<propriete> tableauTemporaire;
    int i=0;
    for(int i=0; i < d_proprietes.size(); ++i){
        if(typeNom == d_proprietes.getType()){
            tableauTemporaire.push_back(d_proprietes[i]);
        }

    }

}

void joueur::setEnPrison(bool prison) {
    d_enPrison = prison;
}

void joueur::operation(int argent) {
    d_argent = d_argent + argent;
}

void joueur::ajouterCartePrison(carteSortiePrison &carte) {
    d_cartesSortiePrison.push_back(carte);
}

