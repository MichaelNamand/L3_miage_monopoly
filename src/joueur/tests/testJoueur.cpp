//
// Created by terminn on 1/5/20.
//

#include "../../case/propriete/propriete.h"
#include "../../../includes/doctest.h"
#include "../../case/propriete/rue.h"

TEST_CASE ("Tests sur les méthodes liees au joueur") {
    joueur j{"Testeur"};
    SUBCASE("Le résultat des des doivent etre entre 1 et 6 chacun")
    {
        vector<int> des = j.lancerDes();
                REQUIRE_LE(1, des[0]);
                REQUIRE_GE(6, des[0]);
                REQUIRE_LE(1, des[1]);
                REQUIRE_GE(6, des[1]);
    }
    SUBCASE("Si le joueur gagne un salaire son argent augmente de 200")
    {
        int argentAvant = j.getArgent();
        j.gagnerSalaire();
                REQUIRE_EQ(argentAvant + 200, j.getArgent());
    }
    SUBCASE("Deplacer vers une case et verifier si le salaire est donne")
    {
        int argentAvant = j.getArgent();
        j.deplacerDe(20);
                REQUIRE_EQ(argentAvant, j.getArgent());
                REQUIRE_EQ(20, j.getIndexCase());

        j.deplacerDe(30);
                REQUIRE_EQ(argentAvant + 200, j.getArgent());
                REQUIRE_EQ(10, j.getIndexCase());
    }

    SUBCASE("Operations")
    {
        SUBCASE("Operation negative")
        {
            int argentAvant = j.getArgent();
            j.operation(-50);
                    REQUIRE_EQ(argentAvant - 50, j.getArgent());
        }
        SUBCASE("Operation positive")
        {
            int argentAvant = j.getArgent();
            j.operation(50);
                    REQUIRE_EQ(argentAvant + 50, j.getArgent());
        }
    }

    SUBCASE("Ajouter une carte sortie de prison")
    {
        int nbCartesPrisonAvant = j.getCartesSortiePrison().size();
        j.ajouterCartePrison();
                REQUIRE_EQ(nbCartesPrisonAvant + 1, j.getCartesSortiePrison().size());
    }

    SUBCASE("Utiliser une carte sortie de prison")
    {
        int nbCartesPrisonAvant = j.getCartesSortiePrison().size();
        j.utiliserCartePrison();
                REQUIRE_EQ(nbCartesPrisonAvant, j.getCartesSortiePrison().size());
        j.ajouterCartePrison();
                REQUIRE_EQ(nbCartesPrisonAvant + 1, j.getCartesSortiePrison().size());
        j.utiliserCartePrison();
                REQUIRE_EQ(nbCartesPrisonAvant, j.getCartesSortiePrison().size());
    }

    SUBCASE("Proprietes")
    {
        rue *r = new rue{"Boulevard de Belleville", DT_MARRON, 60, {2, 10, 30, 90, 160, 250}, 2, 50};
        SUBCASE("Acheter une propriete")
        {
            int argentAvant = j.getArgent();
            int nbProprietesAvant = j.getProprietes(r->getType()).size();
            j.acheterPropriete(r);
                    REQUIRE_EQ(argentAvant, j.getArgent() + r->getPrix());
                    REQUIRE_EQ(nbProprietesAvant + 1, j.getProprietes(r->getType()).size());
        }
        SUBCASE("Vendre une propriete")
        {
            joueur j2{"Acheteur"};

            j.acheterPropriete(r);
            int nbProprietesAvant = j.getProprietes(r->getType()).size();
            int argentAcheteurAvant = j2.getArgent();
            int nbProprietesAcheteurAvant = j2.getProprietes(r->getType()).size();
            int argentAvant = j.getArgent();
            j.vendrePropriete(j2, 0, 100);
                    REQUIRE_EQ(argentAvant + 100, j.getArgent());
                    REQUIRE_EQ(nbProprietesAvant, j.getProprietes(r->getType()).size() + 1);
                    REQUIRE_EQ(argentAcheteurAvant, j2.getArgent() + 100);
                    REQUIRE_EQ(nbProprietesAcheteurAvant + 1, j2.getProprietes(r->getType()).size());
        }
        SUBCASE("Hypothequer")
        {
            j.acheterPropriete(r);
            int argentAvant = j.getArgent();
            int nbProprietesAvant = j.getProprietes(r->getType()).size();
            int nbProprietesHypothequeeAvant = j.getProprietesHypothequees(r->getType()).size();
            j.hypothequerPropriete(0);
            REQUIRE_EQ(argentAvant+r->getValeurHypotheque(),j.getArgent());
            REQUIRE_EQ(nbProprietesAvant - 1, j.getProprietes(r->getType()).size());
            REQUIRE_EQ(nbProprietesHypothequeeAvant+1 , j.getProprietesHypothequees(r->getType()).size());
        }
    }

    SUBCASE("achat Maison Hotel")
    {

        //j.achatMaisonsHotels(1, 0,);

    }

    SUBCASE("Verifie et ajoute les tour en prison, il reste en prison")
    {

        REQUIRE_UNARY_FALSE(j.ajouterEtVerifierTourEnPrison());

    }

    SUBCASE("Verifie et ajoute les tour en prison, il reste en prison")
    {
//pour simuler que le jouer etait pendant 2 tour en prison
        j.ajouterEtVerifierTourEnPrison();
        j.ajouterEtVerifierTourEnPrison();

        REQUIRE_UNARY(j.ajouterEtVerifierTourEnPrison());
    }

    SUBCASE(" affecte un nombre de double et Reinitialise le nombre de double")
    {
        int valeurExpecte = 0;
        REQUIRE_UNARY_FALSE(j.faitUnDoubleEtVaEnPrison());
        j.reinitDoubles();
                REQUIRE_EQ(j.getNbDoubles(), valeurExpecte);
    }

    SUBCASE(" le joueur a fait trop de double et va en prison")
    {

        j.faitUnDoubleEtVaEnPrison();
        j.faitUnDoubleEtVaEnPrison();
        j.faitUnDoubleEtVaEnPrison();
                REQUIRE_UNARY(j.estEnPrison());
    }

    SUBCASE("Payer une redevance à un joueur") {
        joueur *j2 = new joueur{"receveur"};
        int argentReceveurAvant = j2->getArgent();
        int argentAvant = j.getArgent();
        j.payerRedevanceJoueur(j2,50);
        REQUIRE_EQ(argentReceveurAvant+50,j2->getArgent());
        REQUIRE_EQ(argentAvant-50,j.getArgent());
    }


}
