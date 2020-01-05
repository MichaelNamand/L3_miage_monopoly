#include <iostream>
#include <limits>
#include "src/joueur/joueur.h"
#include "src/plateau/plateau.h"
#include "src/jeu.h"

using namespace std;
vector<joueur> jeu::d_joueurs;

void afficherListeJoueurs(vector<joueur> &joueurs) {
    cout << "Liste des joueurs inscrits : " << endl;
    for (int i = 0; i < joueurs.size(); i++) {
        cout << i + 1 << ". " << joueurs[i].getNom() << endl;
    }
}
//#ifdef USING_TEST_MAIN
int main() {
    plateau plateauMonopoly{};
    jeu j{plateauMonopoly};
    j.lancerJeu();
    return 0;
}
//#endif


