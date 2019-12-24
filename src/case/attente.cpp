//
//
//

#include "attente.h"

attente::attente(const string& nom, int type) : caseMonopoly{nom,type}
{}

attente::~attente() {}

void attente::action() {
    if(afficheCase() == "Parc gratuit")
    {
        cout<<"Vous faites une balade au parc !"
    }
    else
    {
        cout<<"Relax, vous êtes à la case départ !"
    }
}