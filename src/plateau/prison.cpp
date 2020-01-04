//
// Created by terminn on 12/23/19.
//

#include "prison.h"

prison::prison() {

}



void prison::sortirDePrison(joueur& j) {
    j.mettreEnPrison(false);
    j.deplacerA(10, false); //se déplace sur la case visite de prison
}

void prison::allerEnPrison(joueur& j) {
    j.mettreEnPrison(true);
}

void prison::essayerDeSortir(joueur& j) {
    vector<int> des = j.lancerDes();
    if(des[0] == des[1]) {
        sortirDePrison(j);
    } else {
        unJourDePlus(j);
        if(j.getNbJoursPrison() == 3) {
            payerEnSortant(j);
        }
    }
}

void prison::unJourDePlus(joueur &j) {
    j.setNbJoursPrison(j.getNbJoursPrison()+1);
}

void prison::payerEnSortant(joueur &j) {
    j.operation(-50);
    sortirDePrison(j);
}

