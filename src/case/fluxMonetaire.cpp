//
//
//

#include "fluxMonetaire.h"

fluxMonetaire::fluxMonetaire(const string &nom, int type) {}

fluxMonetaire::~fluxMonetaire() {}

void fluxMonetaire::action(joueur &j) {
    if(afficheCase() == "Taxe de luxe")
    {
        cout<<j.getNom()<<" est redevable d'un taxe de luxe de 100€ !";
        j.operation(-100);
    }
    else
    {
        cout<<j.getNom()<<" est redevable d'un impôt sur le revenu de 200€ !";
        j.operation(-200);
    }
}