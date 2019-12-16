//
//
//

#include "rue.h"

int rue::getNbMaisons() const {
    return d_nbMaisons;
}

int rue::getNbHotels() const {
    return d_nbHotels;
}

rue::rue(std::string &nom, std::string &couleur, int valeurHypotheque, int prix, std::vector<int> loyers, int nbMaxCouleur):
    propriete{nom, valeurHypotheque, prix, loyers}, d_groupeCouleur{couleur, nbMaxCouleur} {}

int rue::getLoyer() const {
    int multiplicateur = 1;
    if (d_groupeCouleur.sontToutesPossedeesParJoueur() && getNbHotels() == 0 && getNbMaisons() == 0) {
        multiplicateur = 2;
    }
    return d_loyers[d_nbMaisons + d_nbHotels] * multiplicateur;
}
