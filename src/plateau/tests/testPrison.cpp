//
// Created by terminn on 1/5/20.
//

#include "doctest.h"
#include "../prison.h"
#include "../../joueur/joueur.h"

TEST_CASE("Tests sur les méthodes liées à la prison") {
    joueur j{"Testeur"};
    prison p{};
    SUB_CASE("Si le joueur sort de prison, il sera sur la 10ème case") {
        p.sortirDePrison(j);
        ASSERT_EQ(10,j.getIndexCase());
    }
    SUB_CASE("Le nombre de jours en prison du joueur doit incrémenter") {
        int nbJoursAvant = j.getTourEnPrison();
        p.unJourDePlus(j);
        ASSERT_EQ(nbJoursAvant+1,j.getTourEnPrison());
    }
    SUB_CASE("Si le joueur sort de prison en payant, son argent total est réduit de 50 et il sera sur la 10ème case") {
        int argentAvant = j.getArgent();
        p.payerEnSortant(j);
        ASSERT_EQ(argentAvant-50,j.getArgent());
        ASSERT_EQ(10,j.getIndexCase());
    }
}

