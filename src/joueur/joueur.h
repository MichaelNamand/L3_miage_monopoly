//
//
//

#ifndef L3_MIAGE_MONOPOLY_JOUEUR_H
#define L3_MIAGE_MONOPOLY_JOUEUR_H

#include <string>
#include <vector>
#include "../carte/carteSortiePrison.h"
#include "../case/propriete/propriete.h"

using std::string;
using std::vector;

class joueur {
public:
    bool estEnPrison() const;

    string getNom() const;

    int getArgent() const;

    int getIndexCase() const;

    vector<carteSortiePrison> getCartesSortiePrison() const;

    vector<propriete> getPropriete(string typeNom) const;

    void ajouterPropriete(propriete &propriete);

    void vendrePropriete(joueur j, int numeroPropriete, int prixDeVente);

    void hypothequerProptieter(int numeroPropriete);

    void deplacerA(int indexCase, bool enAvancant);

    void ajouterCartePrison();

    void utiliserCartePrison();

    void operation(int argent);


    void setEnPrison(int tour);

    int getTourEnPrison() const;

    void gagnerSalaire();

    vector<int> lancerDes() const;


private:
    string d_nom;
    int d_argent;
    int d_indexCase;
    int d_nbTourPrison;
    vector<carteSortiePrison> d_cartesSortiePrison;
    vector<propriete> d_proprietes;
    vector<propriete> d_proprietesHypothequer

};


#endif //L3_MIAGE_MONOPOLY_JOUEUR_H
