//
//
//

#include "carteDeplacement.h"


carteDeplacement::carteDeplacement(const string &texte, int cases):
        carte{texte}, d_cases{cases} {}

void carteDeplacement::action(joueur j) {
    int tmp=j.getIndexCase();
    if(tmp<d_cases) {
        j.seDeplacer(d_cases - tmp);
    }
    else{
        int case_inter;
        j.seDeplacer(40-tmp+(d_cases+1));
    }

}