//
//
//
#include <vector>
#include "propriete.h"

#ifndef L3_MIAGE_MONOPOLY_RUE_H
#define L3_MIAGE_MONOPOLY_RUE_H


class rue: public propriete {
private:
    int d_nbMaisons = 0;
    int d_nbHotels = 0;

public:
    int getNbMaisons() const;
    int getNbHotels() const;
    int getLoyer(int index) override;
};


#endif //L3_MIAGE_MONOPOLY_RUE_H
