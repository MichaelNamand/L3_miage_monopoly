//
// Created by terminn on 1/5/20.
//

#include "../../case/propriete/propriete.h"

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

    SUB_CASE("Operations") {
        SUB_CASE("Operation negative") {
            int argentAvant = j.getArgent();
            j.operation(-50);
            REQUIRE_EQ(argentAvant-50,j.getArgent());
        }
        SUB_CASE("Operation positive") {
            int argentAvant = j.getArgent();
            j.operation(50);
            REQUIRE_EQ(argentAvant+50,j.getArgent());
        }
    }

    SUB_CASE("Ajouter une carte sortie de prison") {
        int nbCartesPrisonAvant = j.getCartesSortiePrison().size();
        j.ajouterCartePrison();
        REQUIRE_EQ(nbCartesPrisonAvant+1,j.getCartesSortiePrison().size());
    }

    SUB_CASE("Utiliser une carte sortie de prison") {
        int nbCartesPrisonAvant = j.getCartesSortiePrison().size();
        j.utiliserCartePrison();
        REQUIRE_EQ(nbCartesPrisonAvant,j.getCartesSortiePrison().size());
        j.ajouterCartePrison();
        REQUIRE_EQ(nbCartesPrisonAvant+1,j.getCartesSortiePrison().size());
        j.utiliserCartePrison();
        REQUIRE_EQ(nbCartesPrisonAvant,j.getCartesSortiePrison().size());
    }

    SUB_CASE("Proprietes") {
        rue r = new rue{"Boulevard de Belleville", DT_MARRON, 60, {2, 10, 30, 90, 160, 250}, 2, 50};
        SUB_CASE("Acheter une propriete") {
            int argentAvant = j.getArgent();
            int nbProprietesAvant = j.getProprietes(r.getType());
            j.acheterPropriete(r);
            REQUIRE_EQ(argentAvant,j.getArgent()+r.getPrix());
            REQUIRE_EQ(nbProprietesAvant+1,j.getProprietes(r.getType()));
        }
        SUB_CASE("Vendre une propriete") {
            joueur j2{"Acheteur"};
            int argentAvant = j.getArgent();
            int nbProprietesAvant = j.getProprietes(r.getType());
            int argentAcheteurAvant = j2.getArgent();
            int nbProprietesAcheteurAvant = j2.getProprietes(r.getType());
            j.acheterPropriete(r);
            j.vendrePropriete(j2,0,100);
            REQUIRE_EQ(argentAvant+100,j.getArgent());
            REQUIRE_EQ(nbProprietesAvant,j.getProprietes(r.getType())+1);
            REQUIRE_EQ(argentAcheteurAvant,j.getArgent()+100);
            REQUIRE_EQ(nbProprietesAcheteurAvant+1,j.getProprietes(r.getType()));
        }
        SUB_CASE("Hypothequer") {

        }
    }


}
