//
// Created by Administrator on 05.01.2020.
//

#include "../../../includes/doctest.h"
#include "../../joueur/joueur.h"
#include "../carteDeplacement.h"



TEST_CASE ("tester methode lie a la classe CarteDeplacement") {
    int avanceDe = 5;


    joueur j{"Testeur"};
    int placementAvantMouvement = j.getIndexCase();

            SUBCASE("Deplacement sens normal") {
        carteDeplacement carte{"Deplacement", avanceDe, true};
        carte.action(j);
                REQUIRE_EQ(j.getIndexCase(), placementAvantMouvement + avanceDe);
    }

            SUBCASE("Deplacement sens inverse") {
        carteDeplacement carte{"Deplacement", avanceDe, false};
        carte.action(j);
                REQUIRE_EQ(j.getIndexCase(), placementAvantMouvement + avanceDe);
    }

}