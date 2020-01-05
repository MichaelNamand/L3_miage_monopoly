//
//
//
#include <vector>
#include "propriete.h"

#ifndef L3_MIAGE_MONOPOLY_RUE_H
#define L3_MIAGE_MONOPOLY_RUE_H


class rue: public propriete {

public:
    rue(const string &nom, const string &couleur, int prix, const std::vector<int> &loyers, int nbMaxCouleur,
        int prixMaisonHotel);
    int getNbMaisons() const;
    int getNbHotels() const;
    int getPrixMaisonHotelVente() const;
    int getPrixMaisonHotelAchat() const;
    int getPrixVenteHotelsMaisons(int nbMaison, int nbHotels);
    int getPrixAchatHotelsMaisons(int nbMaison, int nbHotels);
    groupeCouleur &getGroupeCouleur();
    int getLoyer(joueur &j) const override;
    void action(joueur &j) override;
    string affichePropriete() const override;

private:
    int d_nbMaisons = 0;
    int d_nbHotels = 0;
    groupeCouleur d_groupeCouleur;
    int d_prixMaisonHotel;

};


#endif //L3_MIAGE_MONOPOLY_RUE_H
