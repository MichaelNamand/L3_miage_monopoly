//
// Created by Administrator on 05.01.2020.
//

#include "doctest.h"

TEST_CASE("tester methode lie a la classe CarteFlux"){
int fluxArgent;
int argentAvantFlux = j.getArgent;

joueur j{"Testeur"};

    SUB_CASE("Deplacement sens normal"){
        fluxArgent = 200;
        carteFlux carte{"Deplacement", fluxArgent};
        carte.action(j);
        REQUIERE_EQ(j.getIndexCase(), argentAvantFlux+fluxArgent);
    }

    SUB_CASE("Deplacement sens inverse"){
        fluxArgent = -300;
        carteAllerVers carte{"Deplacement", fluxArgent};
        carte.action(j);
        REQUIERE_EQ(j.getIndexCase(), argentAvantFlux+fluxArgent);
    }

}