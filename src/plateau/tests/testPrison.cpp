//
// Created by terminn on 1/5/20.
//

#include "doctest.h"
#include "../prison.h"
#include "../../joueur/joueur.h"

TEST_CASE("Tests sur les méthodes liees à la prison") {
    joueur j{"Testeur"};
    prison p{};
    SUB_CASE("Si le joueur sort de prison, il sera sur la 10eme case") {
        p.sortirDePrison(j);
        REQUIRE_EQ(10,j.getIndexCase());
    }
    SUB_CASE("Le nombre de jours en prison du joueur doit incrémenter") {
        int nbJoursAvant = j.getTourEnPrison();
        p.unJourDePlus(j);
        REQUIRE_EQ(nbJoursAvant+1,j.getTourEnPrison());
    }
    SUB_CASE("Si le joueur sort de prison en payant, son argent total est reduit de 50 et il sera sur la 10eme case") {
        int argentAvant = j.getArgent();
        p.payerEnSortant(j);
        REQUIRE_EQ(argentAvant-50,j.getArgent());
        REQUIRE_EQ(10,j.getIndexCase());
    }
}

