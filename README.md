# L3_miage_monopoly
Le jeu sera une retranscription du jeu “Monopoly”.

Le jeu se déroule sur un plateau qui comporte au moins 2 joueurs ainsi que 40 cases. Les cases peuvent être soit :
    - de cases propriétés, qui sont des cases pouvant être achetées par un joueur pour le prix de la case, et qui peuvent être soit :
        - 22 rues, sur lesquelles figurent un nom de rue, une catégorie (couleur) ainsi que différents tarifs (prix des maisons/hypothèque), et un loyer qui varie en fonction du nombre de maison
        - 4 gares. le loyer dépend du nombre de gare que le joueur possède.
        - 2 compagnies (electricité/eau).
    - de cases à effet direct :
        - les cases où l’on paie la somme indiquée
        - les cases où l’on pioche une carte chance
        - les cases où l’on pioche une carte communauté
        - la case aller en prison
    - des cases sans effet (visite de prison/parking gratuit).
La prison peut être représentée par une “case” qui serait hors du plateau (quand on en sort, on atterrit sur la case visite de prison).
Les cartes possèdent un texte et  seront classées en différents types également :
    - les cartes changeant la position du joueur, comprenant donc une position (exemple : la carte ‘retour à la case départ’ aurait un texte “Allez à la case départ.” et comme position la case 0. Lorsque cette carte est piochée, l’on ferait appel à une méthode prenant en paramètre le joueur afin d’appliquer l’effet directement).
    - les cartes faisant payer le joueur ou qui lui donne de l’argent, comprenant donc une somme positive ou négative
Les joueurs possèdent une somme d’argent ainsi que des propriétés. Il possède aussi des cartes (ex: sortie de prison).


Le monopoly étant un jeu déjà défini avec des règles bien précises, ces différents paramètres du plateau seront fixé avant que l’on commence la partie. Cela comprend donc :
    - l’ordre des cases et leur nombre
        - tous les paramètres des cases seront prédéfinis
        - toutes les cartes sont prédéfinies.

La partie se termine lorsqu’il n’y a plus qu’un seul joueur avec de l’argent, ou que tous les autres joueurs ont abandonné.

