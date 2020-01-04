//
//
//

#include <iostream>
#include "attente.h"

using std::cout;

attente::attente(const string& nom, int type) : caseMonopoly{nom,type}
{}

attente::~attente() {}

void attente::action(joueur &j) {
    cout<<afficheCase();
    cout<<"Detendez-vous rien ne se passe" << std::endl;
}