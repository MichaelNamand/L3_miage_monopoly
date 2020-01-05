//
// Created by Administrator on 05.01.2020.
//

#include "../../../includes/doctest.h"
#include "../../joueur/joueur.h"
#include "../carteFlux.h"
#include "../carteAllerVers.h"

TEST_CASE ("tester methode lie a la classe CarteFlux") {
    int fluxArgent;

    joueur j{"Testeur"};



            SUBCASE("Flux positiv") {
        fluxArgent = 200;
        carteFlux carte{"Deplacement", fluxArgent};
        int argentAvantFlux = j.getArgent();
        carte.action(j);
                REQUIRE_EQ(j.getArgent(), argentAvantFlux + fluxArgent);
    }

            SUBCASE("Flux negativ") {
        fluxArgent = -300;
        carteAllerVers carte{"Deplacement", fluxArgent};
        int argentAvantFlux = j.getArgent();
        carte.action(j);
                REQUIRE_EQ(j.getArgent(), argentAvantFlux + fluxArgent);
    }

}