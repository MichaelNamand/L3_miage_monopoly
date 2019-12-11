//
//
//

#ifndef L3_MIAGE_MONOPOLY_CARTEDEPLACEMENT_H
#define L3_MIAGE_MONOPOLY_CARTEDEPLACEMENT_H


#include "carte.h"

class carteDeplacement : public carte {
public:
    carteDeplacement(const string &texte, int cases);

    void action(joueur joueur) override;


private:
    string d_texte;
    int d_cases;


};


#endif //L3_MIAGE_MONOPOLY_CARTEDEPLACEMENT_H
