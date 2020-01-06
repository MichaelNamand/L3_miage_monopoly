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
    cout<<"Vous tombez sur la case Aller en prison. " << j.getNom()<<" va en prison !" << endl;
    j.setEnPrison(true);
    j.setIndexCase(10);
}