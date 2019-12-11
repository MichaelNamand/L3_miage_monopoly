//
//
//

#ifndef L3_MIAGE_MONOPOLY_PROPRIETE_H
#define L3_MIAGE_MONOPOLY_PROPRIETE_H

#include <vector>
#include "../../joueur/joueur.h"

class propriete {
private:
    int d_valeurHypotheque;
    int d_prix;
    joueur *d_joueur;
    std::vector<int> d_loyers;

public:
    propriete(int valeurHypotheque, int prix);

    virtual int getLoyer(int index) = 0;

    int getValeurHypotheque() const;
    int getPrix() const;
    joueur* getJoueur() const;
};


#endif //L3_MIAGE_MONOPOLY_PROPRIETE_H
