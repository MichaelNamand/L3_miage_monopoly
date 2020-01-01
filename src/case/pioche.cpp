//
//
//

#include "pioche.h"
#include "../plateau/plateau.h"

pioche::pioche(const string& nom, int type) : caseMonopoly{nom,type}
{}

pioche::~pioche() {}

void pioche::action(joueur& j) {

   if(afficheCase() == "Carte chance")
   {
        // p.piocherCarteChance(j);
   }
   else
   {
       // p.piocherCarteCommunaute(j);
   }
}