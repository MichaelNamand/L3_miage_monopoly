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

protected:
    std::vector<int> d_loyers;
    joueur *d_proprietaire;
public:
    propriete(std::string &nom, int valeurHypotheque, int prix, std::vector<int> &loyers, int type);
    ~propriete();
    virtual int getLoyer(joueur &j) const = 0;

    void action(joueur &j) override;
    void setProprietaire(joueur &j);
    void choixActions(int montantPaiement);
    bool getConfirmationJoueur();
    int getValeurHypotheque() const;
    int getPrix() const;
    string getType() const;

private:
    string d_type;
};


#endif //L3_MIAGE_MONOPOLY_PROPRIETE_H
