//
//
//

#ifndef L3_MIAGE_MONOPOLY_PROPRIETE_H
#define L3_MIAGE_MONOPOLY_PROPRIETE_H


#include "../../joueur/joueur.h"

class propriete {
private:
    int loyer;
    int valeurHypotheque;
    int prix;
    joueur *j;

public:
    virtual int getLoyer() const = 0; // méthode abstraite
    int getValeurHypotheque() const;
    int getPrix() const;
    joueur* getJoueur() const;
};


#endif //L3_MIAGE_MONOPOLY_PROPRIETE_H
