//
//
//

#include "allerEnPrison.h"
#include "../plateau/plateau.h"

#include <string>
#include <iostream>

using std::string;
using std::cout;

allerEnPrison::allerEnPrison(const string& nom, int type): caseMonopoly{nom,type}
{}

allerEnPrison::~allerEnPrison() {}

void allerEnPrison::action(joueur& j) {
    cout<<j.getNom()<<" va en prison !";
    j.setEnPrison(true);
    j.setIndexCase(10);
}