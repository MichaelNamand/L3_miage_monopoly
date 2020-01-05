//
//
//

#include "propriete.h"
#include "../../jeu.h"
#include "rue.h"
#include <iostream>

propriete::propriete(const string &nom, int prix, const std::vector<int> &loyers, int type) :
        caseMonopoly{nom, type},
        d_prix{prix},
        d_type{type},
        d_loyers{loyers} {}

int propriete::getValeurHypotheque() const {
    return d_prix / 2;
}

int propriete::getPrix() const {
    return d_prix;
}

propriete::~propriete() {

}

void propriete::action(joueur &j) {
    std::cout << "Vous tombez sur " << afficheCase() << " !" << std::endl;
}

void propriete::afficherResultatPaiement(bool succes, joueur &j) {
    if (succes) {
        std::cout << std::endl << "Le paiement s'est bien deroule. Il vous reste " << j.getArgent() << " euros." << std::endl;
    } else {
        std::cout << "Oups, il semblerait qu'il vous manque " << getPrix() - j.getArgent() <<
                  " euros pour effectuer le paiement. L'operation a ete annulee." << std::endl;
    }
}

void propriete::choixActions(int montantPaiement, joueur &j) {
    int selection = 0;
    if (!d_proprietaire) {
        string question = "Cette case n'apartient a personne. Celle-ci coute " +
                          std::to_string(d_prix) + " euros. Votre solde est de " + std::to_string(j.getArgent()) +
                          " euros. Que voulez-vous faire ?";
        vector<string> choix = {"Acheter", "Ne rien faire"};
        selection = jeu::afficherEtRecupererChoix(question, choix);
        switch (selection) {
            case 1:
                std::cout << "Confirmez l'achat ? Appuyez sur -o  pour continuer ou -a pour annuler...";
                if (jeu::getConfirmationJoueur()) {
                    afficherResultatPaiement(j.acheterPropriete(this), j);
                } else choixActions(montantPaiement, j);
                break;
            case 2:
                std::cout << "Voulez-vous vraiment ne rien faire ? La propriete sera mise aux encheres... " << std::endl
                          << "Appuyez sur -o pour continuer ou -a pour annuler..." << std::endl;
                if (jeu::getConfirmationJoueur()) {

                }
                break;
            default:
                std::cout << "Votre choix n'est pas valide." << std::endl;
        }
    } else if (d_proprietaire != &j){
        string question = "Cette case appartient a " + d_proprietaire->getNom() + ". Vous lui devez : " + std::to_string(montantPaiement)
                          + " euros. Comment souhaitez-vous regler ? Votre solde est de " + std::to_string(j.getArgent()) + " euros.";
        vector<string> choix = {"Avec mon solde" ,"En hypothequant", "En vendant mes maisons/hotels" };
        int selection = jeu::afficherEtRecupererChoix(question, choix);
            switch (selection) {
                case 1:
                    std::cout << "Confirmez le paiement ? Appuyez sur -o  pour continuer ou -a pour annuler...";
                    if (jeu::getConfirmationJoueur()) {
                        afficherResultatPaiement(j.payerRedevanceJoueur(getProprietaire(), montantPaiement), j);
                    } else choixActions(montantPaiement, j);
                    break;
                case 2:{
                    string message = "Voici la liste de vos proprietes avec leurs valeurs hypothequaires. Selectionnez-en jusqu'a obtenir"
                                 " un solde suffisant pour payer vos dettes :";
                     vector<string> choixProprietes;
                     for (auto &prop : j.getProprietes(DT_ALL)) {
                         choixProprietes.push_back("Nom : " + prop->afficheCase() + " Valeur hypothequaire : " +
                         to_string(prop->getValeurHypotheque()) + " euros");
                     }
                     int index = jeu::afficherEtRecupererChoix(message, choixProprietes) - 1;
                     propriete *selectionProp = j.getProprietes(DT_ALL)[index];
                     cout << "Confirmer ? Vous recevrez " << selectionProp->getValeurHypotheque() << " euros pour "
                     << selectionProp->afficheCase() << "." << endl;
                     if (jeu::getConfirmationJoueur()) {
                         j.hypothequerPropriete(selectionProp, index);
                         cout << "L'operation a reussi. Votre nouveau solde est maintenant de " << j.getArgent() << " euros." << endl;
                     } else choixActions(montantPaiement, j);
                }
                    break;
                case 3: {
                    string message = "Voici la liste de vos proprietes avec leurs nombres de maisons/hotels. Selectionnez-en jusqu'a obtenir"
                                     " un solde suffisant pour payer vos dettes :";
                    vector<string> choixProprietes;
                    for (auto &prop : j.getProprietes(DT_RUE)) {
                        choixProprietes.push_back(prop->affichePropriete());
                    }
                    int index = jeu::afficherEtRecupererChoix(message, choixProprietes) - 1;
                    propriete *selectionProp = j.getProprietes(DT_ALL)[index];
                    cout << "Selectionnez maintenant le nombre de maisons puis d'hotels que vous souhaitez vendre :";
                    int nbMaisons, nbHotels;
                    cin >> nbMaisons >> nbHotels;
                    if (rue* r = dynamic_cast<rue*>(selectionProp)) {
                        if (nbHotels > r->getNbHotels()) nbHotels = r->getNbHotels();
                        if (nbMaisons > r->getNbMaisons()) nbMaisons = r->getNbMaisons();
                        cout << "Confirmer ? Vous recevrez (" << nbMaisons << " * " << r->getPrixMaisonHotelVente() << ") + (" <<
                            nbHotels * r->getPrixMaisonHotelVente() << ") = " << r->getPrixVenteHotelsMaisons(nbMaisons, nbHotels) << " euros pour "
                             << selectionProp->afficheCase() << "." << endl;
                        if (jeu::getConfirmationJoueur() && j.vendreMaisonsHotels(nbMaisons, nbHotels, r))
                            cout << "L'operation a reussi. Votre nouveau solde est maintenant de " << j.getArgent() << " euros." << endl;
                        } else choixActions(montantPaiement, j);
                    }
                    break;
                default:
                    std::cout << "Votre choix n'est pas valide." << std::endl;
            }
    } else {
        std::cout << "Vous etes chez vous ! Detendez-vous, rien ne se passe." << std::endl;
    }
}

int propriete::getType() const {
    return d_type;
}

void propriete::setProprietaire(joueur *j) {
    d_proprietaire = j;
}

joueur *propriete::getProprietaire() {
    return d_proprietaire;
}

string propriete::affichePropriete() const {
    return "Nom : " + afficheCase() + "\nValeur hypotheque : " + to_string(getValeurHypotheque()) + '\n';
}

bool propriete::estHypothequee() const {
    return d_estHypothequee;
}

void propriete::setHypotheque(bool estHypothequee) {
    d_estHypothequee = estHypothequee;
}
