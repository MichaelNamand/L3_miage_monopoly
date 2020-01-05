//
// Created by DELL on 22/12/2019.
//
#include "../../../includes/doctest.h"
#include "../fluxMonetaire.h"
#include "../../joueur/joueur.h"

TEST_CASE("Test sur l'action flux monétaire")
{
    joueur j{"testeur"};
    {
        fluxMonetaire c{"Taxe de luxe",DT_FLUX};
        int argentOrigine = j.getArgent();
        c.action(j);
        int argentModifie = j.getArgent();
        REQUIRE_EQ( argentOrigine-100 , argentModifie);
    }
    SUBCASE("Taxe d'imposition")
    {
        fluxMonetaire c{"Taxe impôt sur le revenu",DT_FLUX};
        int argentOrigine = j.getArgent();
        c.action(j);
        int argentModifie = j.getArgent();
        REQUIRE_EQ( argentOrigine-200 , argentModifie);
    }
}



