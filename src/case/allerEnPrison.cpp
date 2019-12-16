//
//
//

#include "allerEnPrison.h"

#include <string>

using std::string;

allerEnPrison::allerEnPrison(const string& nom, int type): caseMonopoly{nom,type}
{}

allerEnPrison::~allerEnPrison() {}

void allerEnPrison::action(joueur joueur) {
    joueur.mettreEnPrison() = true;
    joueur.seDeplacer(-20);  //de la case AllezPrison à la case EnPrison/VisitePrison
                                     //nombre négatif pour ne pas gagner 200 euros de CaseDepart
}

