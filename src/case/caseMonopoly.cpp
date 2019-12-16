//
//
//

#include "caseMonopoly.h"
#include <string>

using std::string;

caseMonopoly::caseMonopoly(const string& nom, const int type) : d_nom{nom}, d_type{type}
{}

caseMonopoly::~caseMonopoly() {}


string caseMonopoly::afficheCase() const {
    return d_nom;
}