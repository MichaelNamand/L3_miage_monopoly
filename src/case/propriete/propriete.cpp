//
//
//

#include "propriete.h"
#include <iostream>
#include <limits>
#include <winuser.h>

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

void propriete::action(joueur *j) {
    std::cout << "Vous tombez sur " << affiche();
}

void propriete::choixActions(int montantPaiement) {
    int choix = 0;
    if (!d_joueur) {
        std::cout << "Cette case n'apartient a personne. Celle-ci coute " <<
            d_prix << ". Que voulez-vous faire ?" << std::endl << "1. Acheter"
                  << std::endl <<"2. Ne rien faire" << std::endl;
        while (choix <= 0  || choix > 2) {
            std::cin >> choix;
            switch (choix) {
                case 1:
                    std::cout << "Confirmez l'achat ? Appuyez sur Entree  pour continuer ou Echap pour annuler...";
                    if(getConfirmationJoueur()) {
                        // TODO opération achat joueur + push propriété.
                    } else choix = 100;
                    break;
                case 2:
                    std::cout << "Voulez-vous vraiment ne rien faire ? La propriete sera mise aux encheres... " <<std::endl <<
                              "Appuyez sur Entree pour continuer ou Echap pour annuler...";
                    break;
                default:
                    std::cout << "Votre choix n'est pas valide." << std::endl;
            }
        }
    } else {
        std::cout << "Cette case appartient a " << d_joueur->getNom() << ". Vous lui devez : " << montantPaiement << "€." <<
        std::endl << "Comment souhaitez-vous regler ?" << std::endl <<

        "1. Avec mon solde" << std::endl <<
        "2. En hypothequant";
        choix = 0;
        while (choix <= 0  || choix > 2) {
            std::cin >> choix;
            switch (choix) {
                case 1:
                    std::cout << "Confirmez le paiement ? Appuyez sur Entree  pour continuer ou Echap pour annuler...";
                    if(getConfirmationJoueur()) {
                        // TODO opération achat joueur + push propriété.
                    } else choix = 100;

                    break;
                case 2:
                    std::cout << "Voulez-vous vraiment ne rien faire ? La propriete sera mise aux encheres... " <<std::endl <<
                              "Appuyez sur Entree pour continuer ou Echap pour annuler...";
                    if(getConfirmationJoueur()) {
                        
                    } else choix = 100;
                    break;
                default:
                    std::cout << "Votre choix n'est pas valide." << std::endl;
            }
        }
    }
}

bool propriete::getConfirmationJoueur() {
    while (true) {
        if(GetAsyncKeyState(VK_ESCAPE) {
            std::cout << "Operation annulee !" <<endl;
            return false;
        }
        if(GetAsyncKeyState(VK_ENTER) {
            return true;
        }
    }
}
