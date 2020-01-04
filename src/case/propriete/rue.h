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
    rue(const string &nom, const string &couleur, int valeurHypotheque, int prix, const std::vector<int> &loyers, int nbMaxCouleur,
            int prixMaison, int prixHotel);
    int getNbMaisons() const;
    int getNbHotels() const;
    int getPrixMaison() const;
    int getPrixHotel() const;
    int getPrixVenteHotelsMaisons(int nbMaison, int nbHotels);
    int getLoyer(joueur &j) const override;
    void action(joueur &j) override;
    string affichePropriete() const override;
private:
    groupeCouleur d_groupeCouleur;
    int d_prixMaison;
    int d_prixHotel;

};


#endif //L3_MIAGE_MONOPOLY_RUE_H
