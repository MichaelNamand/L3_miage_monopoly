//
//
//
#include <vector>
#include "propriete.h"

#ifndef L3_MIAGE_MONOPOLY_RUE_H
#define L3_MIAGE_MONOPOLY_RUE_H


class rue: public propriete {
private:
    int d_nbMaisons = 0;
    int d_nbHotels = 0;

public:
    rue(std::string &nom, std::string &couleur, int valeurHypotheque, int prix, std::vector<int> loyers, int nbMaxCouleur);
    int getNbMaisons() const;
    int getNbHotels() const;
    int getLoyer(joueur &j) const override;
    void action(joueur &j) override;

private:
    groupeCouleur d_groupeCouleur;

};


#endif //L3_MIAGE_MONOPOLY_RUE_H
