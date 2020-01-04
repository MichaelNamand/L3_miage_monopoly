//
//
//

#include "carteSortiePrison.h"
#include "../joueur/joueur.h"

carteSortiePrison::carteSortiePrison(const string &texte) :
        carte{texte} {}

void carteSortiePrison::action(joueur &j) {

    j.ajouterCartePrison();
}