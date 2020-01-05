//
// Created by Michael on 04/01/2020.
//

#include "jeu.h"
#include "case/propriete/rue.h"
#include <iostream>
#include <limits>
#include <curses.h>

using namespace std;

void jeu::lancerJeu() {
    cout << "*******************MONOPOLY*******************" << endl << "Bienvenue dans le jeu console Monopoly."
         << endl <<
         "Utilisez les touches du pave numerique pour selectionner les differentes options qui s'offriront a vous tout au long du jeu..."
         << endl << endl << "Pour commencer, inscrivez au minimum 2 joueurs." << endl;

    int selection = 0;
    vector<joueur> joueurs {joueur{"Michael"}, joueur{"Julien"}};
    while (joueurs.size() < 2 || selection != 3) {
        string question = "Actuellement, il y a " + to_string(joueurs.size()) +
                          " joueur(s) enregistre(s). Que souhaitez-vous faire ?";
        vector<string> choix = {"Creer de nouveaux joueurs", "Supprimer un joueur", "Lancer la partie"};
        selection = afficherEtRecupererChoix(question, choix);
        switch (selection) {
            case 1: {
                string nomJoueur;
                do {
                    cout << "Entrer un nom pour le nouveau joueur (tapez 0 lorsque vous avez termine) : ";
                    cin >> nomJoueur;
                    bool existe = false;
                    for (auto &joueur : joueurs) {
                        if (joueur.getNom() == nomJoueur) {
                            cout << "Impossible d'enregistrer ce joueur. Ce nom existe deja." << endl;
                            existe = true;
                        }
                    }
                    if (!existe && nomJoueur != "0") {
                        joueurs.emplace_back(nomJoueur);
                        cout << "Le joueur a bien ete enregistre. " << endl;
                    }
                } while (nomJoueur != "0");
            }
                break;
            case 2: {
                question = "Choisir le joueur a supprimer. -1 pour revenir.";
                vector<string> listeJoueurs;
                listeJoueurs.reserve(joueurs.size());
                for (auto &joueur : joueurs) {
                    listeJoueurs.push_back(joueur.getNom());
                }
                int selectionJoueur = afficherEtRecupererChoix(question, listeJoueurs) - 1;
                if (selectionJoueur <= joueurs.size() && selectionJoueur >= 0) {
                    cout << joueurs[selectionJoueur].getNom() << " a bien ete supprime." << endl;
                    joueurs.erase(joueurs.begin() + selectionJoueur);
                }
            }
                break;
            case 3:
                if (joueurs.size() < 2) {
                    cout << "Impossible de lancer la partie. Au moins 2 joueurs sont necessaires pour jouer." << endl;
                }
                break;
            default:
                cout << "Entree incorrecte. Reessayer" << endl;
        }
    }

    cout << "***********************LA PARTIE COMMENCE***********************" << endl;
    // plateau d_plateau{};
    int tourJoueur = 0;
    d_joueurs = joueurs;
    while (joueurs.size() != 1) {
        joueur &joueurPrecedent = joueurs[tourJoueur];
        if (joueurPrecedent.getNbDoubles() == 0) {
            tourJoueur++;
            if (tourJoueur >= joueurs.size()) tourJoueur = 0;
        } else if (!joueurPrecedent.estEnPrison()){
            cout << "C'est au joueur precedent de rejouer : ";
        }
        joueur &j = joueurs[tourJoueur];

        cout << "C'est au tour de " << j.getNom() << "." << endl;
        if (j.estEnPrison()) {
            cout << "Vous etes actuellement en prison..." << endl;
        }
        string question = "Choisir une des options suivantes : ";
        vector<string> choix = {"Lancer les des", "Gerer ses proprietes"};
        if (j.estEnPrison()) choix.emplace_back("Payer directement les frais de sortie 50 euros");
        selection = afficherEtRecupererChoix(question, choix);
        switch (selection) {
            case 1: {
                vector<int> valeurDes = j.lancerDes();
                cout << j.getNom() << " joue (" << valeurDes[0] << " + " << valeurDes[1] << ") = "
                     << valeurDes[0] + valeurDes[1] << endl;
                if (valeurDes[0] == valeurDes[1]) {
                    cout << "Vous venez de faire un double. " << endl;
                    if (!j.estEnPrison() && j.faitUnDoubleEtVaEnPrison()) {
                        cout << "Vous avez fait trois doubles... Direction la case prison !";
                        j.setEnPrison(true);
                        continuerJoueur();
                    } else if (!j.estEnPrison()){
                        cout <<  "Attention, encore " << 3 - j.getNbDoubles() << " et c'est la prison..." << endl;
                        continuerJoueur();
                    } else {
                        cout << "Super ! Vous pouvez sortir de prison sans frais !" << endl;
                        j.setEnPrison(false);
                        continuerJoueur();
                    }
                } else {
                    if (!j.estEnPrison()) {
                        j.reinitDoubles();
                    } else {
                        if (j.ajouterEtVerifierTourEnPrison()) {
                            cout << "Vous venez de tenter votre derniere chance pour sortir de prison en vain. 50 euros "
                                    "ont ete preleves de votre solde pour sortir. Votre solde est maintenant de " <<
                                    j.getArgent() << " euros";
                            continuerJoueur();
                        } else {
                            cout << "Pas de chance pour cette fois. Vous restez en prison... Il vous reste encore " <<
                            3 - j.getTourEnPrison() << " essai(s)." << endl;
                            continuerJoueur();
                        }
                    }
                }
                if (!j.estEnPrison()) {
                    j.deplacerA(j.getIndexCase() + valeurDes[0] + valeurDes[1], true);
                    d_plateau.getCase(j.getIndexCase()).action(j);
                }
            }
                break;
            case 2: {
                while (jeu::getConfirmationJoueur()) {
                    if (!j.getProprietes(DT_ALL).empty())  {
                        string message = "Voici la liste de vos biens. Selectionnez celle que vous voulez gerer :";
                        vector<string> choixListe;
                        for (auto &prop : j.getProprietes(DT_ALL)) {
                            choixListe.push_back(prop->affichePropriete());
                        }
                        int selectionProp = jeu::afficherEtRecupererChoix(message, choixListe);
                        propriete *propChoisi = j.getProprietes(DT_ALL)[selectionProp];
                        message = "Que voulez-vous faire avec cette propriete ?";
                        vector<string> choixPropriete;
                        if (propChoisi->estHypothequee()) {
                            choixPropriete.emplace_back("Retirer l'hypotheque");
                        } else {
                            choixPropriete.emplace_back("Hypothequer");
                        }
                        if (rue *r = dynamic_cast<rue *>(propChoisi)) {
                            choixPropriete.emplace_back("Acheter des maisons");
                            choixPropriete.emplace_back("Acheter des hotels");
                        }
                        int selectionAction = jeu::afficherEtRecupererChoix(message, choixPropriete);
                        switch (selectionAction) {
                            case 1: {
                                if (propChoisi->estHypothequee()) {
                                    cout << "Confirmer ? Vous recevrez " << propChoisi->getValeurHypotheque() << " euros pour" <<
                                         " la mise en hypotheque de ce bien" << endl;
                                    if (jeu::getConfirmationJoueur()) {
                                        propChoisi->setHypotheque(true);
                                        j.operation(propChoisi->getValeurHypotheque());
                                        cout << "Votre bien a bien ete hypotheque. Votre nouveau solde est de " << j.getArgent() <<
                                             " euros." << endl;
                                        jeu::continuerJoueur();
                                    }
                                } else {
                                    cout << "Confirmer ? Vous devrez payer " << propChoisi->getValeurHypotheque() << " euros pour" <<
                                         " retirer l'hypotheque de ce bien" << endl;
                                    if (jeu::getConfirmationJoueur()) {
                                        propChoisi->setHypotheque(false);
                                        j.operation(-propChoisi->getValeurHypotheque());
                                        cout << "Votre bien est de nouveau disponible. Votre nouveau solde est de " << j.getArgent() <<
                                             " euros." << endl;
                                        jeu::continuerJoueur();
                                    }
                                }
                            }
                                break;
                            case 2: {
                                if (rue *r = dynamic_cast<rue *>(propChoisi)) {
                                    if (r->getGroupeCouleur().sontToutesPossedeesParJoueur(j)) {
                                        int nbHotels, nbMaisons;
                                        cout << "Renseignez le nombre de maisons et d'hotels a constuire : " << endl;
                                        cin >> nbHotels >> nbMaisons;
                                        int prixTotal = r->getPrixAchatHotelsMaisons(nbMaisons, nbHotels);
                                        if (prixTotal <= j.getArgent()) {
                                            cout << "Confirmer ? Vous devrez payer au total " << prixTotal << " euros.";
                                            if (jeu::getConfirmationJoueur() && j.achatMaisonsHotels(nbMaisons, nbHotels, r)) {
                                                cout << "L'operation s'est bien passee. Votre nouveau solde est de " << j.getArgent()
                                                << " euros. Votre rue possede maintenant " << r->getNbMaisons() << " maison(s) et " <<
                                                r->getNbHotels() << " hotel(s)." << endl;
                                            }
                                        }
                                    } else {
                                        cout << "Vous ne pouvez rien construire tant que vous ne possedez pas toute les cartes d'une famille !" << endl;
                                    }
                                }

                            }
                        }
                    } else {
                        cout << "Vous ne possédez aucune propriete !";
                    }
                }
            }
            break;
            case 3: {
                cout << "Payer 50 euros pour sortir de prison. Appuyer sur -o pour confirmer, -a pour annuler";
                if (getConfirmationJoueur()) {
                    j.operation(-50);
                    j.setEnPrison(false);
                    cout << "Vous etes sorti de prison. Votre solde est maintenant de " << j.getArgent() << " euros. "
                            "Pour pouvoir avancer, attendez jusqu'au prochain tour." << endl;
                    jeu::continuerJoueur();
                }
            }

        }
    }
}

jeu::jeu(plateau &plateau) : d_plateau{plateau} {
}

int jeu::afficherEtRecupererChoix(const string &question, const vector<string> &choix) {
    cout << question << endl;
    for (int i = 0; i < choix.size(); i++) {
        cout << i + 1 << ". " << choix[i] << endl;
    }
    int selection = 0;
    cout << "Votre choix : ";
    while (!(cin >> selection)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Votre choix n'est pas un nombre. Reessayer..." << endl << "Votre choix :";
    }
    return selection;
}

bool jeu::getConfirmationJoueur() {
    while (true) {
        char choix;
        std::cin >> choix;
        if (choix == 'a') {
            std::cout << "Operation annulee !" << std::endl;
            return false;
        } else if (choix == 'o') {
            return true;
        }
    }
}

void jeu::continuerJoueur() {
    cout << "Appuyez sur Entree pour continuer...";
    getch();

}
