//
// Created by Administrator on 05.01.2020.
//

#include "doctest.h"
#include "../carteAllerEnPrison.h"


TEST_CASE("tester methode lie a la classe CarteAllerEnPrison"){
    carteAllerEnPrison carte{"Direction Prison"};
    joueur j{"Testeur"};

    carte.action(j);
    REQUIERE_EQ(j.estEnPrison(),true);


}