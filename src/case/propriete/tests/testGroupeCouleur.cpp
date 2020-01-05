//
// Created by DELL on 05/01/2020.
//

#include "../../../../includes/doctest.h"
#include "../../../joueur/joueur.h"
#include "../../../plateau/plateau.h"
#include "../rue.h"

TEST_CASE("Test sur la possession de toutes les propriétées")
{
    joueur j{"testeur"};
    groupeCouleur gc{DT_BLEU_CIEL, 3};
    rue r1{"Rue de Courcelles", DT_BLEU_CIEL, 100, {6, 30, 90, 270, 400, 550}, 3, 50};
    rue r2{"Avenue de la République", DT_BLEU_CIEL, 120, {8, 40, 100, 300, 450, 600}, 3, 50};
    rue r3{"Rue de Vaugirard", DT_BLEU_CIEL, 100, {6, 30, 90, 270, 400, 550}, 3, 50};

    SUBCASE("Possession de toutes les propriétées même couleur")
    {
        j.acheterPropriete(&r1);
        j.acheterPropriete(&r2);
        j.acheterPropriete(&r3);

        REQUIRE_UNARY(gc.sontToutesPossedeesParJoueur(j));
    }
    SUBCASE("Aucune possession de toutes les propriétées même couleur")
    {
        REQUIRE_UNARY_FALSE(gc.sontToutesPossedeesParJoueur(j));
    }
    SUBCASE("Possesion manquante de toutes les propriétées même couleur")
    {
        j.acheterPropriete(&r1);
        j.acheterPropriete(&r2);

        REQUIRE_UNARY_FALSE(gc.sontToutesPossedeesParJoueur(j));
    }
}