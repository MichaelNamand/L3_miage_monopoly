//
//
//

#ifndef L3_MIAGE_MONOPOLY_CARTE_H
#define L3_MIAGE_MONOPOLY_CARTE_H

#include <string>

class joueur;

using std::string;

class carte {
public:
    carte(const string &texte);

    virtual void action(joueur &j) = 0;

    string afficheCarte() const;

private:
    string d_texte;
};


#endif //L3_MIAGE_MONOPOLY_CARTE_H
