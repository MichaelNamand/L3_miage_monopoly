//
// Created by Administrator on 05.01.2020.
//

#include "doctest.h"

TEST_CASE("tester methode lie a la classe CarteDeplacement"){
int avanceDe = 5;
int placementAvantMouvement = j.getIndexCase();

joueur j{"Testeur"};

    SUB_CASE("Deplacement sens normal"){
        carteDeplacement carte{"Deplacement", avanceDe, true};
        carte.action(j);
        REQUIERE_EQ(j.getIndexCase(), placementAvantMouvement+avanceDe);
        }

    SUB_CASE("Deplacement sens inverse"){
        carteAllerVers carte{"Deplacement", avanceDe, false};
        carte.action(j);
        REQUIERE_EQ(j.getIndexCase(), placementAvantMouvement+avanceDe);
    }

}