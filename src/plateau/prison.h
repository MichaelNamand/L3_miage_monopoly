//
// Created by terminn on 12/23/19.
//

#ifndef L3_MIAGE_MONOPOLY_PRISON_H
#define L3_MIAGE_MONOPOLY_PRISON_H


#include "../joueur/joueur.h"

class prison {
public:
    prison();

    void sortirDePrison(joueur& j);
    void payerEnSortant(joueur& j);


private:
    void unJourDePlus(joueur& j);
};


#endif //L3_MIAGE_MONOPOLY_PRISON_H
