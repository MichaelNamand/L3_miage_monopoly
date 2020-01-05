//
// Created by DELL on 22/12/2019.
//
#include "doctest.h"
#include "../fluxMonetaire.h"
#include "../../joueur/joueur.h"

TEST_CASE("Test sur l'action flux monétaire")
{
    {
        int argentOrigine = j.getArgent();
        c.action(j);
        int argentModifie = j.getArgent();
        fluxMonetaire c{"Taxe de luxe",DT_FLUX};
        ASSERT_EQ( argentOrigine-100 , argentModifie);
    }
    SUB_CASE("Taxe d'imposition")
    {
        int argentOrigine = j.getArgent();
        c.action(j);
        int argentModifie = j.getArgent();
        fluxMonetaire c{"Taxe impôt sur le revenu",DT_FLUX};
        ASSERT_EQ( argentOrigine-200 , argentModifie);
    }
}



