//
//
//

#ifndef L3_MIAGE_MONOPOLY_CARTEDEPLACEMENT_H
#define L3_MIAGE_MONOPOLY_CARTEDEPLACEMENT_H


#include "carte.h"

class carteDeplacement : public carte {
public:
    carteDeplacement(const string &texte, int cases, bool d_sensNormal);

    void action(joueur &j) override;

private:
    int d_cases;
    bool d_sensNormal;
};


#endif //L3_MIAGE_MONOPOLY_CARTEDEPLACEMENT_H
