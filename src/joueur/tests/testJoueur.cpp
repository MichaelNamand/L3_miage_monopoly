//
// Created by terminn on 1/5/20.
//

TEST_CASE("Tests sur les méthodes liees au joueur") {
    joueur j{"Testeur"};
    SUB_CASE("Le résultat des des doivent etre entre 1 et 6 chacun") {
        vector<int> des = j.lancerDes();
        REQUIRE_GE(1,des[0]);
        REQUIRE_GE(1,des[1]);
        REQUIRE_LE(6,des[0]);
        REQUIRE_LE(6,des[1]);
    }
    SUB_CASE("Si le joueur gagne un salaire son argent augmente de 200") {
        int argentAvant = j.getArgent();
        j.gagnerSalaire();
        REQUIRE_EQ(argentAvant+200,j.getArgent());
    }
    SUB_CASE("Deplacer vers une case") {
        int argentAvant = j.getArgent();
        j.deplacerA(20,true);
        REQUIRE_EQ(argentAvant,j.getArgent());
        REQUIRE_EQ(20,j.getIndexCase());

        j.deplacerA(10,true);
        REQUIRE_EQ(argentAvant+200,j.getArgent());
        REQUIRE_EQ(10,j.getIndexCase());
    }
}
