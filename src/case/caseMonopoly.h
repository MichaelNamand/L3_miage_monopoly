//
//
//

#ifndef L3_MIAGE_MONOPOLY_CASEMONOPOLY_H
#define L3_MIAGE_MONOPOLY_CASEMONOPOLY_H

#define DT_PIOCHE 1
#define DT_PROPRIETE 2
#define DT_FLUX 3
#define DT_ALLERPRISON 4
#define DT_ATTENTE 5

class caseMonopoly {
public :
    virtual ~caseMonopoly();

    virtual void action() const = 0;

private :
    string d_nom;
    int d_type;
};


#endif //L3_MIAGE_MONOPOLY_CASEMONOPOLY_H
