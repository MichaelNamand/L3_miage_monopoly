//
// Created by Administrator on 05.01.2020.
//

#include "doctest.h"

TEST_CASE("tester methode lie a la classe CarteSortiePrison"){

carteSortiePrison carte{"Vous avez gagner une carte Prison, faites en bonne ussage"};
joueur j{"Testeur"};

//nombre carte en prison avant l'action
int nbCartePrison = j.getCartesSortiePrison().size();

carte.action(j);
REQUIERE_EQ(j.getCartesSortiePrison().size(), nbCartePrison+1);

}