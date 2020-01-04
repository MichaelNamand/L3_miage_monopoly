//
//
//

#include "rue.h"
#include <iostream>
using namespace std;

int rue::getNbMaisons() const {
    return d_nbMaisons;
}

int rue::getNbHotels() const {
    return d_nbHotels;
}

rue::rue(const string &nom, const string &couleur, int valeurHypotheque, int prix,const std::vector<int> &loyers, int nbMaxCouleur,
        int prixMaison, int prixHotel):
    propriete{nom, valeurHypotheque, prix, loyers, DT_RUE}, d_groupeCouleur{couleur, nbMaxCouleur}, d_prixMaison{prixMaison},
        d_prixHotel{prixHotel} {}

int rue::getLoyer(joueur &j) const {
    int multiplicateur = 1;
    if (d_groupeCouleur.sontToutesPossedeesParJoueur() && getNbHotels() == 0 && getNbMaisons() == 0) {
        multiplicateur = 2;
    }
    return d_loyers[d_nbMaisons + d_nbHotels] * multiplicateur;
}

void rue::action(joueur &j) {
    propriete::action(j);
    propriete::choixActions(getLoyer(j), j);
}

string rue::affichePropriete() const {
    return propriete::affichePropriete() + "Maison(s) : " + to_string(getNbMaisons()) + ". Hotel(s) : " + to_string(getNbHotels())
    + "\nCouleur : " + d_groupeCouleur.getCouleur() + "\n";
}

int rue::getPrixMaison() const {
    return d_prixMaison;
}

int rue::getPrixHotel() const {
    return d_prixHotel;
}

int rue::getPrixVenteHotelsMaisons(int nbMaison, int nbHotels) {
    return nbMaison * getPrixMaison() + nbHotels * getPrixHotel();
}
