//
//
//

#include <time.h>
#include "joueur.h"
#include <iostream>
#include "../case/propriete/propriete.h"
#include "../case/propriete/rue.h"
#include "../plateau/plateau.h"
#include "../jeu.h"

using namespace std;

joueur::joueur(const string &nom): d_nom{nom} {
    d_argent = 1500;
    d_indexCase = 0;
    d_nbTourPrison = 0;
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

int joueur::getTourEnPrison() const {
    return d_nbTourPrison;
}

void joueur::setEnPrison(bool estEnPrison) {
    d_estEnPrison = estEnPrison;
    if (estEnPrison) {
        int tmp = getIndexCase();
        int casePrison = 10;
        deplacerA(casePrison - tmp, false);
    }
}

vector<int> joueur::lancerDes() {
    srand (time(NULL));
    vector<int> des;
    des.push_back(rand() % 6 + 1);
    des.push_back(rand() % 6 + 1);
    setDernierLanceDes(des[0] + des[1]);
    return des;
}

void joueur::gagnerSalaire() {
    d_argent += 200;
    cout << "Vous venez de passer par la case Depart ! Recevez 200 euros. Votre nouveau solde est de " << getArgent() << "euros" << endl;
    jeu::continuerJoueur();
}

void joueur::deplacerA(int indexCase, bool enAvancant) {
    int max = DT_NB_CASES_PLATEAU;
    if(enAvancant && indexCase >= max){
        gagnerSalaire();
        d_indexCase = indexCase - max;
    } else {
        d_indexCase = indexCase;
    }
}

void joueur::operation(int argent) {
    d_argent += argent;
}

void joueur::ajouterCartePrison() {
    carteSortiePrison carte = carteSortiePrison{"Tu as gagner une carte prison"};

    d_cartesSortiePrison.push_back(carte);
}

void joueur::utiliserCartePrison() {
    if (d_cartesSortiePrison.size() > 0) {
        d_cartesSortiePrison.pop_back();
    }

}

void joueur::vendrePropriete(joueur &j, int numeroPropriete, int prixDeVente) {
    j.ajouterPropriete(d_proprietes[numeroPropriete]);
    d_proprietes.erase(d_proprietes.begin() + numeroPropriete);
    j.operation(-prixDeVente);
    operation(prixDeVente);
}

void joueur::hypothequerPropriete(int index) {
    operation(d_proprietes[index]->getValeurHypotheque());
    d_proprietesHypothequees.push_back(d_proprietes[index]);
    d_proprietes.erase(d_proprietes.begin() + index);
}

string joueur::getNom() const {
    return d_nom;
}

vector<propriete*> joueur::getProprietes(int type) const {
    vector<propriete*> tableauTemporaire;
    for (int i = 0; i < d_proprietes.size(); ++i) {
        if (type == d_proprietes[i]->getType() || type == DT_ALL) {
            tableauTemporaire.push_back(d_proprietes[i]);
        }
    }
    return tableauTemporaire;
}

bool joueur::estEnPrison() const {
    return d_estEnPrison;
}

bool joueur::acheterPropriete(propriete *p) {
    if (d_argent >= p->getPrix()) {
        operation(-p->getPrix());
        ajouterPropriete(p);
        return true;
    } else {
        return false;
    }
}

bool joueur::payerRedevanceJoueur(joueur *j, int montantRedevance) {
    if (getArgent() < montantRedevance) {
        return false;
    } else {
        j->operation(montantRedevance);
        operation(-montantRedevance);
        return true;
    }
}

int joueur::getNbDoubles() const {
    return d_nbDoubles;
}

bool joueur::faitUnDoubleEtVaEnPrison() {
    d_nbDoubles++;
    if (d_nbDoubles == 3) {
        d_nbDoubles = 0;
        d_estEnPrison = true;
        return true;
    }
    return false;
}

void joueur::reinitDoubles() {
    d_nbDoubles = 0;
}

bool joueur::ajouterEtVerifierTourEnPrison() {
    d_nbTourPrison++;
    if (d_nbTourPrison == 3) {
        d_nbTourPrison = 0;
        return true;
    }
    return false;
}

int joueur::getDernierLanceDes() const {
    return d_dernier_lance_des;
}

void joueur::setDernierLanceDes(int valeur) {
    d_dernier_lance_des = valeur;
}

joueur::~joueur() {

}

bool joueur::vendreMaisonsHotels(int nbMaison, int nbHotels, rue *r) {
    if (nbMaison > 0 && nbHotels > 0 && nbHotels <= r->getNbHotels() && nbMaison <= r->getNbMaisons()) {
        operation(r->getPrixVenteHotelsMaisons(nbMaison, nbHotels));
        return true;
    } else {
        cout << "Les valeurs saisies n'ont pas permis d'effectuer la vente..." << endl;
        return false;
    }
}

bool joueur::achatMaisonsHotels(int nbMaison, int nbHotels, rue *r) {
    if (r->getPrixVenteHotelsMaisons(nbMaison, nbHotels) <= getArgent()) {
        operation(-r->getPrixVenteHotelsMaisons(nbMaison, nbHotels));
        return true;
    } else {
        cout << "Les valeurs saisies n'ont pas permis d'effectuer la vente..." << endl;
        return false;
    }
}

void joueur::ajouterPropriete(propriete *p) {
    d_proprietes.push_back(p);
    p->setProprietaire(this);
}
