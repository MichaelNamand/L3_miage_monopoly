//
//
//
#include <iostream>
#include "carteFlux.h"
#include "../joueur/joueur.h"

carteFlux::carteFlux(const string &texte, int flux) :
        carte{texte},
        d_flux{flux} {}

void carteFlux::action(joueur &j) {
    std::cout << afficheCarte();
    j.operation(d_flux);
    std::cout << " Votre nouveau solde est de " << j.getArgent() << " euros." << std::endl;
}