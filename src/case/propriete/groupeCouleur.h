//
//
//

#ifndef L3_MIAGE_MONOPOLY_GROUPECOULEUR_H
#define L3_MIAGE_MONOPOLY_GROUPECOULEUR_H

#include <string>

class groupeCouleur {
private:
    std::string d_couleur;
    int d_nbMaxCouleurs;

public:
    groupeCouleur(std::string &couleur, int nbMaxCouleurs);
    bool sontToutesPossedeesParJoueur() const;
};


#endif //L3_MIAGE_MONOPOLY_GROUPECOULEUR_H
