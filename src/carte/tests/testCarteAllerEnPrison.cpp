//
// Created by Administrator on 05.01.2020.
//
#define USING_TEST_MAIN

#ifdef USING_TEST_MAIN
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#endif
#include "../../../includes/doctest.h"
#include "../carteAllerEnPrison.h"
#include "../../joueur/joueur.h"


TEST_CASE ("tester methode lie a la classe CarteAllerEnPrison") {
    carteAllerEnPrison carte{"Direction Prison"};
    joueur j{"Testeur"};

    carte.action(j);
            REQUIRE_UNARY(j.estEnPrison());


}