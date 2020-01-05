//
// Created by Michael on 04/01/2020.
//

#ifndef L3_MIAGE_MONOPOLY_JEU_H
#define L3_MIAGE_MONOPOLY_JEU_H


#include "plateau/plateau.h"

class jeu {
private:
    plateau d_plateau;
public:
    static vector<joueur> d_joueurs;
    jeu(plateau &plateau);
    void lancerJeu();
    void gererPropriete(joueur &j);
    void gererTourJoueur(joueur &j);
    static bool getConfirmationJoueur();
    static void continuerJoueur();
    static int afficherEtRecupererChoix(const string &question, const vector<string> &choix);
};


#endif //L3_MIAGE_MONOPOLY_JEU_H
