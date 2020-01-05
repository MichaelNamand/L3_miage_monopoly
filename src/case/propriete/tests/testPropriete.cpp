//
// Created by DELL on 05/01/2020.
//

#include "../../../../includes/doctest.h"
#include "../propriete.h"
#include "../gare.h"
#include "../rue.h"
#include "../servicePublic.h"

TEST_CASE ("Test des methodes de propriete") {
    SUBCASE("Test de la valeur d'hypotheque") {
        gare g{"Test", 200, {1, 2, 3, 4}};
                REQUIRE_EQ(100, g.getValeurHypotheque());
    }
    SUBCASE("Test de la valeur d'hypotheque") {
        rue r{"Test",DT_BLEU, 100, {1, 2, 3, 4},2,100};
                REQUIRE_EQ(50, r.getValeurHypotheque());
    }
    SUBCASE("Test de la valeur d'hypotheque") {
        servicePublic s{"Test", 200};
                REQUIRE_EQ(100, s.getValeurHypotheque());
    }
}
