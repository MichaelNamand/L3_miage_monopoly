//
//
//

#ifndef L3_MIAGE_MONOPOLY_CARTE_H
#define L3_MIAGE_MONOPOLY_CARTE_H

#include <string>
#include "../joueur/joueur.h"

using std::string;
class carte {
public:
 carte( const string& texte);
 virtual void action(joueur joueur) = 0;

private:
    string d_texte;
};


#endif //L3_MIAGE_MONOPOLY_CARTE_H
