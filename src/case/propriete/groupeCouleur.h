//
//
//

#ifndef L3_MIAGE_MONOPOLY_GROUPECOULEUR_H
#define L3_MIAGE_MONOPOLY_GROUPECOULEUR_H

#include <string>
#include "../../joueur/joueur.h"

#define DT_BLEU "Bleu"
#define DT_BLEU_CIEL "Bleu ciel"
#define DT_ROUGE "Rouge"
#define DT_VERT "Vert"
#define DT_JAUNE "Jaune"
#define DT_ORANGE "Orange"
#define DT_ROSE "Rose"
#define DT_MARRON "Marron"
using namespace std;
class groupeCouleur {
private:
    std::string d_couleur;
    int d_nbMaxCouleurs;

public:
    groupeCouleur(const std::string &couleur, int nbMaxCouleurs);
    bool sontToutesPossedeesParJoueur(joueur &j) const;
    string getCouleur() const;
};


#endif //L3_MIAGE_MONOPOLY_GROUPECOULEUR_H
