//
//
//

#include "plateau.h"
#include <iostream>

using namespace std;

#include "../case/propriete/rue.h"
#include "../case/pioche.h"
#include "../carte/carteAllerEnPrison.h"
#include "../case/propriete/servicePublic.h"
#include "../case/propriete/gare.h"
#include "../case/attente.h"
#include "../case/allerEnPrison.h"
#include "../carte/carteFlux.h"
#include "../carte/carteDeplacement.h"
#include "../carte/carteAllerVers.h"

plateau::plateau() {
    vector<int> loyerGare = {25, 50, 100, 200};

    /**
     * CASES DU PLATEAU
     */
    d_cases.push_back(new attente{"Depart", DT_ATTENTE});
    d_cases.push_back(new rue{"Boulevard de Belleville", DT_MARRON, 60, {2, 10, 30, 90, 160, 250}, 2, 50});
    d_cases.push_back(new pioche{"Caisse de communaute", DT_COMMUNAUTE, this});
    d_cases.push_back(new rue{"Rue Lecourbe", DT_MARRON, 60, {4, 20, 60, 180, 320, 450}, 2, 50});
    d_cases.push_back(new gare{"Gare Montparnasse", 200, loyerGare});
    d_cases.push_back(new rue{"Rue de Vaugirard", DT_BLEU_CIEL, 100, {6, 30, 90, 270, 400, 550}, 3, 50});
    d_cases.push_back(new pioche{"Chance", DT_CHANCE, this});
    d_cases.push_back(new rue{"Rue de Courcelles", DT_BLEU_CIEL, 100, {6, 30, 90, 270, 400, 550}, 3, 50});
    d_cases.push_back(new rue{"Avenue de la République", DT_BLEU_CIEL, 120, {8, 40, 100, 300, 450, 600}, 3, 50});

    d_cases.push_back(new rue{"Boulevard de la Villette", DT_ROSE, 140, {10, 50, 150, 450, 625, 750}, 3, 100});
    d_cases.push_back(new servicePublic{"Compagnie de distribution d'electricite", 140});
    d_cases.push_back(new rue{"Avenue de Neuilly", DT_ROSE, 140, {10, 50, 150, 450, 625, 750}, 3, 100});
    d_cases.push_back(new rue{"Rue de Paradis", DT_ROSE, 160, {12, 60, 180, 500, 700, 900}, 3, 100});
    d_cases.push_back(new gare{"Gare de Lyon", 200, loyerGare});
    d_cases.push_back(new rue{"Avenue Mozart", DT_ORANGE, 180, {14, 70, 200, 550, 750, 950}, 3, 100});
    d_cases.push_back(new pioche{"Caisse de communaute", DT_COMMUNAUTE, this});
    d_cases.push_back(new rue{"Boulevard Saint-Michel", DT_ORANGE, 180, {14, 70, 200, 550, 750, 950}, 3, 100});
    d_cases.push_back(new rue{"Place Pigalle", DT_ORANGE, 200, {16, 80, 220, 600, 800, 1000}, 3, 100});
    d_cases.push_back(new attente{"Parc Gratuit", DT_ATTENTE});
    d_cases.push_back(new rue{"Avenue Matignon", DT_ROUGE, 220, {18, 90, 250, 700, 875, 1150}, 3, 150});
    d_cases.push_back(new pioche{"Chance", DT_CHANCE, this});
    d_cases.push_back(new rue{"Boulevard Malesherbes", DT_ROUGE, 220, {18, 90, 250, 700, 875, 1150}, 3, 150});
    d_cases.push_back(new rue{"Avenue Henri-Martin", DT_ROUGE, 240, {20, 100, 300, 750, 925, 1100}, 3, 150});
    d_cases.push_back(new gare{"Gare du Nord", 200, loyerGare});
    d_cases.push_back(new rue{"Faubourg Saint-Honore", DT_JAUNE, 260, {22, 110, 330, 800, 975, 1150}, 3, 150});
    d_cases.push_back(new rue{"Place de la Bourse", DT_JAUNE, 260, {22, 110, 330, 800, 975, 1150}, 3, 150});
    d_cases.push_back(new servicePublic{"Compagnie de distribution des eaux", 140});
    d_cases.push_back(new rue{"Rue la Fayette", DT_JAUNE, 280, {24, 120, 360, 850, 1025, 1200}, 3, 150});
    d_cases.push_back(new allerEnPrison{"Allez en Prison", DT_PRISON});
    d_cases.push_back(new rue{"Avenue DE Breteuil", DT_VERT, 300, {26, 130, 390, 900, 1100, 1275}, 3, 200});
    d_cases.push_back(new rue{"Avenue Foch", DT_VERT, 300, {26, 130, 390, 900, 1100, 1275}, 3, 200});
    d_cases.push_back(new pioche{"Caisse de communaute", DT_COMMUNAUTE, this});
    d_cases.push_back(new rue{"Boulevard des Capucines", DT_VERT, 320, {28, 150, 450, 1000, 1200, 1400}, 3, 200});
    d_cases.push_back(new gare{"Gare Saint-Lazare", 200, loyerGare});
    d_cases.push_back(new pioche{"Chance", DT_CHANCE, this});
    d_cases.push_back(new rue{"Avenue des Champs-Elysees", DT_BLEU, 350, {35, 175, 500, 1100, 1300, 1500}, 2, 200});
    d_cases.push_back(new rue{"Rue de la Paix", DT_BLEU, 400, {50, 200, 600, 1400, 1700, 2000}, 2, 200});


    /**
     * CARTES PIOCHE CHANCE ET CAISSE DE COMMUNAUTE
     */
    d_piocheCaisseCommunaute.push(new carteFlux{"Commission d'expert immobilier. Recevez 25 euros.", 25});
    d_piocheCaisseCommunaute.push(new carteFlux{"Erreur de la banque en votre faveur. Recevez 200 euros.", 200});
    d_piocheCaisseCommunaute.push(new carteFlux{"Votre assurance vie vous rapporte 100 euros.",100});
    d_piocheCaisseCommunaute.push(new carteFlux{"Frais de scolarite. Payez 50 euros",-50});
    d_piocheCaisseCommunaute.push(new carteFlux{"Vous avez gagne le deuxieme prix de beaute. Recevez 10 euros.",10});
    d_piocheCaisseCommunaute.push(new carteFlux{"Visite chez le medecin : payez 50 euros.",-50});
    d_piocheCaisseCommunaute.push(new carteFlux{"La vente de votre stock vous rapporte 50 euros.",50});
    d_piocheCaisseCommunaute.push(new carteFlux{"Vous heritez de 100 euros.",100});
    d_piocheCaisseCommunaute.push(new carteFlux{"Votre placement vous rapporte. Recevez 100 euros.",100});
    d_piocheCaisseCommunaute.push(new carteFlux{"Frais d'hospitalisation. Payez 100 euros.",-100});
    d_piocheCaisseCommunaute.push(new carteFlux{"Les impots vous remboursent 20 euros.",20});
    d_piocheCaisseCommunaute.push(new carteAllerVers{"Avancez jusqu'a la case depart (recevez 200 euros).",0});
    d_piocheCaisseCommunaute.push(new carteAllerEnPrison{"Allez en prison. Allez tout droit en prison. Ne passez par la case depart, ne recevez pas 200 euros."});

    d_piocheChance.push(new carteFlux{"La banque vous verse un dividence de 50 euros", 50});
    d_piocheChance.push(new carteFlux{"Amende pour exces de vitesse : Payez 15 euros", -15});
    d_piocheChance.push(new carteDeplacement{"Reculez de trois cases", 3, false});
    d_piocheChance.push(new carteAllerVers{"Avancez au Boulevard de la Villette. Si vous passez par la case Depart, recevez 200 euros", 11});
    d_piocheChance.push(new carteAllerVers{"Rendez-vous a l'Avenue Henri-Martin. Si vous passez par la case Depart, recevez 200 euros", 24});
    d_piocheChance.push(new carteAllerVers{"Rendez-vous a Rue de la Paix", 39});
    d_piocheChance.push(new carteAllerVers{"Allez a la gare Montparnasse. Si vous passez par la case Depart, recevez 200 euros", 5});
    d_piocheChance.push(new carteAllerVers{"Avancez jusqu'a la case Depart, recevez 200 euros", 0});
    d_piocheChance.push(new carteAllerEnPrison{"Allez en Prison. Ne passez pas par la case depart, ne recevez pas 200 euros"});
    d_piocheChance.push(new carteSortiePrison{"Vous etes libere de prison. Cette carte peut etre conservee jusqu'a ce qu'elle soit utilisee"});
    d_piocheChance.push(new carteFlux{"Votre immeuble et votre pret rapportent. Touchez 150 euros", 150});

}

void plateau::sortirDePrison(joueur &j) {
    // j.mettreEnPrison(false);
    j.deplacerA(10, false); //se déplace sur la case visite de prison
}

vector<caseMonopoly> plateau::proprietesRestantes() const {
    vector<caseMonopoly> p;
    for (int i = 0; i < d_cases.size(); i++) {
        /*if(d_cases[i].getType() == DT_PROPRIETES) {
            if(d_cases[i].getJoueur() != nullptr) {
                p.push_back(d_cases[i]);
            }
        }*/
    }
    return p;
}

const queue<carte *> &plateau::getPiocheChance() const {
    return d_piocheChance;
}

const queue<carte *> &plateau::getPiocheCaisseCommunaute() const {
    return d_piocheCaisseCommunaute;
}

void plateau::piocherCarte(joueur &j, int type) {
    carte *c;
    if (type == DT_COMMUNAUTE){
        c = d_piocheCaisseCommunaute.front();
    }
    else {
        c = d_piocheChance.front();
    }
    c->action(j);
    if (type == DT_COMMUNAUTE){
        d_piocheCaisseCommunaute.pop();
        d_piocheCaisseCommunaute.push(c);
    } else {
        d_piocheChance.pop();
        d_piocheChance.push(c);
    }
}

caseMonopoly &plateau::getCase(int index) const {
    return *d_cases[index];
}

vector<caseMonopoly *> plateau::getCases() const {
    return d_cases;
}

