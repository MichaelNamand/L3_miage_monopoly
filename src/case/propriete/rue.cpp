//
//
//

#include "rue.h"
using namespace std;

int rue::getNbMaisons() const {
    return d_nbMaisons;
}

int rue::getNbHotels() const {
    return d_nbHotels;
}

rue::rue(const string &nom, const string &couleur, int prix,const std::vector<int> &loyers, int nbMaxCouleur,
        int prixMaisonHotel):
        propriete{nom, prix, loyers, DT_RUE}, d_groupeCouleur{couleur, nbMaxCouleur},
        d_prixMaisonHotel{prixMaisonHotel} {}

int rue::getLoyer(joueur &j) const {
    int multiplicateur = 1;
    if (d_groupeCouleur.sontToutesPossedeesParJoueur(j) && getNbHotels() == 0 && getNbMaisons() == 0) {
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

int rue::getPrixMaisonHotelVente() const {
    return d_prixMaisonHotel / 2;
}

int rue::getPrixMaisonHotelAchat() const {
    return d_prixMaisonHotel;
}

int rue::getPrixVenteHotelsMaisons(int nbMaison, int nbHotels) {
    return nbMaison * getPrixMaisonHotelVente() * (nbMaison + nbHotels);
}

groupeCouleur &rue::getGroupeCouleur() {
    return d_groupeCouleur;
}

int rue::getPrixAchatHotelsMaisons(int nbMaison, int nbHotels) {
    return getPrixMaisonHotelAchat() * (nbMaison + nbHotels);
}
