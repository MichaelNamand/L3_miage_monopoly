//
// Created by terminn on 12/23/19.
//

#include "prison.h"

prison::prison() {

}



void prison::sortirDePrison(joueur j) {
    j.mettreEnPrison(false);
    j.deplacerA(10, false); //se déplace sur la case visite de prison
}

void prison::allerEnPrison(joueur j) {
    j.mettreEnPrison(true);
}

void prison::essayerDeSortir(joueur j) {

}
