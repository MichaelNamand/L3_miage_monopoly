//
// Created by DELL on 22/12/2019.
//
#include "../../../includes/doctest.h"
#include "../allerEnPrison.h"
#include "../../joueur/joueur.h"

TEST_CASE("Test sur l'action aller en prison")
{
    joueur j{"testeur"};
    allerEnPrison c{"Aller en prison",DT_ALLERPRISON};
    c.action(j);
    REQUIRE_EQ(10,j.getIndexCase());
}

