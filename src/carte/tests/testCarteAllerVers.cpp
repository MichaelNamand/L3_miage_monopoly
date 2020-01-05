//
// Created by Administrator on 05.01.2020.
//

#include "../../../includes/doctest.h"
#include "../carteAllerVers.h"

TEST_CASE ("tester methode lie a la classe CarteAllerVers") {
    int numeroCase = 10;
    carteAllerVers carte{"Direction Vers la case 10", numeroCase};
    joueur j{"Testeur"};

    carte.action(j);
    REQUIRE_EQ(j.getIndexCase(), numeroCase-1);

}