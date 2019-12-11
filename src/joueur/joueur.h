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
    const string& getNom() const;
    int getArgent() const;
    int getIndexCase() const;
    const vector<carteSortiePrison> &getCartesSortiePrison() const;
    const vector<propriete> &getProprietes() const;
    const vector<propriete> &getRues() const;
    const vector<propriete> &getGares() const;
    const vector<propriete> &getServicePublic() const;
    void vendreMaison();
    void hypothequer();
    void seDeplacer(int nbCases);


private:
    string d_nom;
    int d_argent;
    bool d_enPrison;
    int d_indexCase;
    vector<carteSortiePrison> d_cartesSortiePrison;
    vector<propriete> d_proprietes;
};


#endif //L3_MIAGE_MONOPOLY_JOUEUR_H
