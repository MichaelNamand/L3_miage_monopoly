//
//
//

#include "groupeCouleur.h"
#include "../caseMonopoly.h"
#include "rue.h"

groupeCouleur::groupeCouleur(const std::string &couleur, int nbMaxCouleurs): d_couleur{couleur}, d_nbMaxCouleurs{nbMaxCouleurs}{

}

bool groupeCouleur::sontToutesPossedeesParJoueur(joueur &j) const {
    int compteur = 0;
    for (auto &prop : j.getProprietes(DT_RUE)) {
        if (rue *r = dynamic_cast<rue *>(prop)) {
            if (r->getGroupeCouleur().getCouleur() == getCouleur()) {
                compteur++;
            }
        }
    }
    return compteur == d_nbMaxCouleurs;
}

string groupeCouleur::getCouleur() const {
    return d_couleur;
}
