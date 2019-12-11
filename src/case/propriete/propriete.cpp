//
//
//

#include "propriete.h"

propriete::propriete(int valeurHypotheque, int prix): d_prix{prix}, d_valeurHypotheque{valeurHypotheque} {}

int propriete::getValeurHypotheque() const {
    return d_valeurHypotheque;
}

int propriete::getPrix() const {
    return d_prix;
}

joueur *propriete::getJoueur() const {
    return d_joueur;
}
