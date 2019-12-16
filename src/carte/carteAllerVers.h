//
// Created by Administrator on 16.12.2019.
//

#ifndef L3_MIAGE_MONOPOLY_CARTEALLERVERS_H
#define L3_MIAGE_MONOPOLY_CARTEALLERVERS_H


#include "carte.h"

class carteAllerVers : public carte {
public:
    carteAllerVers(const string &texte, int cases);

    void action(joueur j) override;

private:
    int d_cases;

};


#endif //L3_MIAGE_MONOPOLY_CARTEALLERVERS_H
