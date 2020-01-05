//
//
//

#include "carteFlux.h"
#include "../joueur/joueur.h"

carteFlux::carteFlux(const string &texte, int flux) :
        carte{texte},
        d_flux{flux} {}

void carteFlux::action(joueur &j) {
    j.operation(j.getArgent() + d_flux);
}