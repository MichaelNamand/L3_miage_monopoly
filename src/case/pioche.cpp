//
//
//

#include "pioche.h"

pioche::pioche(const string& nom, int type) : caseMonopoly{nom,type} {

    for(int i = 0; i < 1; ++i) //2 : Chance ou Communauté
    {
        for(int j = 0; j < 15 ; ++j) //16: Dans le monopoly il y a 16 cartes/communauté
        {
            //remplir le tableau de cartes
            //vous avez parlé d'une méthode de lecture depuis un fichier json ou truc du genre
        }
    }

}

pioche::~pioche() {}

void pioche::action() {

    random_shuffle(d_cartesPlateau.begin(), d_cartesPlateau.end()); //mélange des cartes
    d_indexPioche[0] = rand() % 2; //pioche indexCarte aléatoire
    d_indexPioche[1] = rand() % 16;
    if(d_indexPioche[0] == 0)
    {
        cout<<"Vous piochez une carte chance :";
        cout<<d_cartesPlateau[d_indexPioche[0]][d_indexPioche[1]].contenuCarte(); //Si la méthode contenuCarte n'existe
                                                                                  //pas il faudra la créer qui retourne
                                                                                  //le champs texte de carte
        //d_cartesPlateau[d_indexPioche[0]][d_indexPioche[1]].action(); //je ne suis pas sûr de cette ligne, il faudra
                                                                        //changer le nom de la méthode action dans
                                                                        //carte car j'ai le même nom dans case.
    }
}