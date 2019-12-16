//
//
//

#include "propriete.h"
#include <iostream>

propriete::propriete(std::string &nom, int valeurHypotheque, int prix, std::vector<int> &loyers):
        caseMonopoly{nom},
        d_prix{prix},
        d_valeurHypotheque{valeurHypotheque},
        d_loyers{loyers}
{}

int propriete::getValeurHypotheque() const {
    return d_valeurHypotheque;
}

int propriete::getPrix() const {
    return d_prix;
}

joueur *propriete::getJoueur() const {
    return d_joueur;
}

propriete::~propriete() {

}

int propriete::getChoixJoueur() const {
    std::cout << "Vous tombez sur " << affiche();
    int choix = 0;
    if (!d_joueur) {
        std::cout << "Cette case n'apartient à personne. Que voulez-vous faire ?" << std::endl << "1. Acheter"
                  << std::endl <<
                  "2. Ne rien faire" << std::endl;
        int choix = 0;
        while (choix == 0) {
            std::cin >> choix;
        }
    } else {
        std::cout << "Cette case apartient à " << d_joueur << ". Vous lui devez " << getLoyer() << std::endl << "1. Acheter"
                  << std::endl <<
                  "2. Ne rien faire" << std::endl;
    }
    return choix;
};


void propriete::action(joueur *j) {
    std::cout << "Vous tombez sur " << affiche();
    if (!d_joueur) {
        std::cout << "Cette case n'apartient à personne. Que voulez-vous faire ?" << std::endl << "1. Acheter" << std::endl <<
            "2. Ne rien faire" << std::endl;
        int choix = 0;
        while (choix == 0) {
            std::cin >> choix;
        }

        if (choix == 1) {
            if (j.getArgent() >= getPrix()) {
                std::cout << "Vous avez les fonds suffisants. Il vous reste"
                j.operation(getPrix());
            }
        }


    }
}
