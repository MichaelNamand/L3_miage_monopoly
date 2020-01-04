//
//
//

#include <time.h>
#include "joueur.h"
#include "../case/propriete/propriete.h"

int joueur::getArgent() const {
    return d_argent;
}

int joueur::getIndexCase() const {
    return d_indexCase;
}


vector<carteSortiePrison> joueur::getCartesSortiePrison() const {
    return d_cartesSortiePrison;
}

int joueur::getTourEnPrison() const {
    return d_nbTourPrison;
}

void joueur::setEnPrison(int tour) {
    int d_nbTourPrison = tour;
}

vector<int> joueur::lancerDes() const {
    srand (time(NULL));
    vector<int> des;
    des.push_back(rand() % 6 + 1);
    des.push_back(rand() % 6 + 1);
    return des;
}

void joueur::gagnerSalaire() {
    d_argent += 200;
}

void joueur::deplacerA(int indexCase, bool enAvancant) {
    if(enAvancant && indexCase < d_indexCase)
        gagnerSalaire();
    d_indexCase = indexCase;
}

void joueur::operation(int argent) {
    d_argent += argent;
}

void joueur::ajouterCartePrison() {
    carteSortiePrison carte = carteSortiePrison{"Tu as gagner une carte prison"};

    d_cartesSortiePrison.pop_back();
}

void joueur::utiliserCartePrison() {
    if (d_cartesSortiePrison.size() > 0) {
        d_cartesSortiePrison.erase(d_cartesSortiePrison.begin());
    }

}

void joueur::vendrePropriete(joueur &j, int numeroPropriete, int prixDeVente) {
    d_proprietes.erase(d_proprietes.begin() + numeroPropriete);
    j.operation(-prixDeVente);
    operation(prixDeVente);

}

void joueur::hypothequerProptieter(int numeroPropirete) {
    operation(d_proprietes[numeroPropirete]->getValeurHypotheque());
    d_proprietesHypothequees.push_back(d_proprietes[numeroPropirete]);
    d_proprietes.erase(d_proprietes.begin() + numeroPropirete);
}

string joueur::getNom() const {
    return d_nom;
}

vector<propriete*> joueur::getProprietes(string &typeNom) const {
    vector<propriete*> tableauTemporaire;
    for (int i = 0; i < d_proprietes.size(); ++i) {
        if (typeNom == d_proprietes[i]->getType()) {
            tableauTemporaire.push_back(d_proprietes[i]);
        }
    }
    return tableauTemporaire;
}

bool joueur::estEnPrison() const {
    return d_estEnPrison;
}
