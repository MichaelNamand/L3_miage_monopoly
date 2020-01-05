//
// Created by Administrator on 05.01.2020.
//

#include "../../../includes/doctest.h"

TEST_CASE("tester methode lie a la classe CarteAllerVers"){
int numeroCase = 10;
carteAllerVers carte{"Direction Vers", numeroCase};
joueur j{"Testeur"};

carte.action(j);
REQUIERE_EQ(j.getIndexCase(), numeroCase);

}