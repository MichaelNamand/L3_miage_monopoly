//
//
//

#include "carteSortiePrison.h"

carteSortiePrison::carteSortiePrison(const string &texte) :
        carte{texte} {}

void carteSortiePrison::action(joueur j) {

    j.ajouterCartePrison();
}