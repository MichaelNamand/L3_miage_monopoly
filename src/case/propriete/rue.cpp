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
        int prixMaison, int prixHotel, int prixMaisonAchat, int prixHotelAchat):
        propriete{nom, valeurHypotheque, prix, loyers, DT_RUE}, d_groupeCouleur{couleur, nbMaxCouleur}, d_prixMaisonVente{prixMaison},
        d_prixHotelVente{prixHotel}, d_prixMaisonAchat{prixMaisonAchat}, d_prixHotelAchat{prixHotelAchat} {}

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

int rue::getPrixMaisonVente() const {
    return d_prixMaisonVente;
}

int rue::getPrixHotelVente() const {
    return d_prixHotelVente;
}

int rue::getPrixVenteHotelsMaisons(int nbMaison, int nbHotels) {
    return nbMaison * getPrixMaisonVente() + nbHotels * getPrixHotelVente();
}

groupeCouleur &rue::getGroupeCouleur() {
    return d_groupeCouleur;
}

int rue::getPrixAchatHotelsMaisons(int nbMaison, int nbHotels) {
    return nbMaison * getPrixMaisonVente() + nbHotels * getPrixHotelVente();
}

int rue::getPrixMaisonAchat() const {
    return d_prixMaisonAchat;
}

int rue::getPrixHotelAchat() const {
    return d_prixHotelAchat;
}
