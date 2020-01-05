//
//
//

#ifndef L3_MIAGE_MONOPOLY_JOUEUR_H
#define L3_MIAGE_MONOPOLY_JOUEUR_H

#include <string>
#include <vector>
#include <bits/unique_ptr.h>
#include "../carte/carteSortiePrison.h"

class propriete;
class rue;

using std::string;
using std::vector;

class joueur {
public:
    joueur(const string &nom);

    ~joueur();

    bool estEnPrison() const;

    string getNom() const;

    int getArgent() const;

    int getIndexCase() const;

    vector<carteSortiePrison> getCartesSortiePrison() const;

    vector<propriete*> getProprietes(int type) const;

    // void ajouterPropriete(propriete propriete);

    bool acheterPropriete(propriete *p);

    bool payerRedevanceJoueur(joueur *j, int montantRedevance);

    void vendrePropriete(joueur &j, int numeroPropriete, int prixDeVente);

    void hypothequerPropriete(propriete *popriete, int index);

    bool vendreMaisonsHotels(int nbMaison, int nbHotels, rue *r);

    bool achatMaisonsHotels(int nbMaison, int nbHotels, rue *r);

    void deplacerA(int indexCase, bool enAvancant);

    void ajouterCartePrison();

    void utiliserCartePrison();

    void operation(int argent);

    void setEnPrison(bool estEnprison);

    int getTourEnPrison() const;

    bool ajouterEtVerifierTourEnPrison();

    int getNbDoubles() const;

    bool faitUnDoubleEtVaEnPrison();

    void reinitDoubles();

    void gagnerSalaire();

    int getDernierLanceDes() const;

    void setDernierLanceDes(int valeur);

    vector<int> lancerDes();


private:
    string d_nom;
    int d_argent;
    int d_indexCase;
    int d_dernier_lance_des;
    int d_nbTourPrison;
    int d_nbDoubles = 0;
    bool d_estEnPrison = false;
    vector<carteSortiePrison> d_cartesSortiePrison;
    vector<propriete*> d_proprietes;
    vector<propriete*> d_proprietesHypothequees;

};


#endif //L3_MIAGE_MONOPOLY_JOUEUR_H
