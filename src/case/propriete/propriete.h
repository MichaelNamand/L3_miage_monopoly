//
//
//

#ifndef L3_MIAGE_MONOPOLY_PROPRIETE_H
#define L3_MIAGE_MONOPOLY_PROPRIETE_H

#include <vector>
#include "../caseMonopoly.h"
#include "groupeCouleur.h"
#include "../../joueur/joueur.h"
using namespace std;

class propriete : public caseMonopoly {
private:
    int d_prix;

protected:
    vector<int> d_loyers;
    joueur *d_proprietaire;
public:
    propriete(const string &nom, int prix, const vector<int> &loyers, int type);
    ~propriete();
    virtual int getLoyer(joueur &j) const = 0;

    void action(joueur &j) override;
    void setProprietaire(joueur *j);
    joueur *getProprietaire() const;
    void afficherResultatPaiement(bool succes, joueur &j);
    void choixActions(int montantPaiement, joueur &j);
    int getValeurHypotheque() const;
    int getPrix() const;
    int getType() const;
    bool estHypothequee() const;
    void setHypotheque(bool estHypothequee);
    virtual string affichePropriete() const;

private:
    int d_type;
    bool d_estHypothequee = false;
};


#endif //L3_MIAGE_MONOPOLY_PROPRIETE_H
