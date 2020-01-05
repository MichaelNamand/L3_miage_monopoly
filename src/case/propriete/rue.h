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
            int prixMaisonVente, int prixHotelVente, int prixMaisonAchat, int prixHotelAchat);
    int getNbMaisons() const;
    int getNbHotels() const;
    int getPrixMaisonVente() const;
    int getPrixMaisonAchat() const;
    int getPrixHotelVente() const;
    int getPrixHotelAchat() const;
    int getPrixVenteHotelsMaisons(int nbMaison, int nbHotels);
    int getPrixAchatHotelsMaisons(int nbMaison, int nbHotels);
    groupeCouleur &getGroupeCouleur();
    int getLoyer(joueur &j) const override;
    void action(joueur &j) override;
    string affichePropriete() const override;
private:
    groupeCouleur d_groupeCouleur;
    int d_prixMaisonVente;
    int d_prixMaisonAchat;
    int d_prixHotelVente;
    int d_prixHotelAchat;

};


#endif //L3_MIAGE_MONOPOLY_RUE_H
