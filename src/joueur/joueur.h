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

    void vendrePropriete(joueur j);

    void hypothequer();

    void seDeplacer(int nbCases);

    void ajouterCartePrison(carteSortiePrison &carte);

    void utiliserCartePrison();

    void operation(int argent);

    void mettreEnPrison(bool prison);


private:
    string d_nom;
    int d_argent;
    bool d_enPrison;
    int d_indexCase;
    vector<carteSortiePrison> d_cartesSortiePrison;
    vector<propriete> d_proprietes;
    vector<carteSortiePrison> d_carteSortiePrison;
};


#endif //L3_MIAGE_MONOPOLY_JOUEUR_H
