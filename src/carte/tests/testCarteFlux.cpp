//
// Created by Administrator on 05.01.2020.
//

#include "doctest.h"

TEST_CASE("tester methode lie a la classe CarteFlux"){
int fluxArgent;
int argentAvantFlux = j.getArgent;

joueur j{"Testeur"};

    SUB_CASE("Flux positiv"){
        fluxArgent = 200;
        carteFlux carte{"Deplacement", fluxArgent};
        carte.action(j);
        REQUIERE_EQ(j.getArgent(), argentAvantFlux+fluxArgent);
    }

    SUB_CASE("Flux negativ"){
        fluxArgent = -300;
        carteAllerVers carte{"Deplacement", fluxArgent};
        carte.action(j);
        REQUIERE_EQ(j.getArgent(), argentAvantFlux+fluxArgent);
    }

}