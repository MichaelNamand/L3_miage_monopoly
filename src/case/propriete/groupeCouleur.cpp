//
//
//

#include "groupeCouleur.h"

groupeCouleur::groupeCouleur(const std::string &couleur, int nbMaxCouleurs): d_couleur{couleur}, d_nbMaxCouleurs{nbMaxCouleurs}{

}

bool groupeCouleur::sontToutesPossedeesParJoueur() const {

}

string groupeCouleur::getCouleur() const {
    return d_couleur;
}
