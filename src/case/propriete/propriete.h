//
//
//

#ifndef L3_MIAGE_MONOPOLY_PROPRIETE_H
#define L3_MIAGE_MONOPOLY_PROPRIETE_H

#include <vector>
#include "../caseMonopoly.h"
#include "groupeCouleur.h"
#include "../../joueur/joueur.h"

class propriete : public caseMonopoly {
private:
    int d_valeurHypotheque;
    int d_prix;
    joueur *d_joueur;

protected:
    std::vector<int> d_loyers;

public:
    propriete(std::string &nom, int valeurHypotheque, int prix, std::vector<int> &loyers);
    ~propriete();
    virtual int getLoyer() const = 0;

    void action(joueur *j) override;

    int getChoixJoueur() const;
    int getValeurHypotheque() const;
    int getPrix() const;
    joueur *getJoueur() const;
};


#endif //L3_MIAGE_MONOPOLY_PROPRIETE_H
