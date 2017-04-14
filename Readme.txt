Application 2048 par Adrien Cosson et Alexandre Cartier


Fonctionnalités de l'application :

-Lorsque l'utilisateur lance le jeu, une nouvelle partie de 2048 commence (deux nouvelles cellules sont générées).
Il peut alors jouer en utilisant les flèches ou les touches z,q,s,d afin de déplacer les cellules.
Lorsque deux cellules contenant des chiffres sont identiques, elles fusionnent et leur valeurs s'additionnent.
Une animation s'exécute quand une cellule se déplace ou apparait.

-Lorsqu'il y a un déplacement, une nouvelle cellule est créée aléatoirement dans les cases libres.
La probabilité d'apparition d'un 4 est de 1/10.
Il ne se passe rien si on déclenche un déplacement dans une direction où aucune cellule ne peut se déplacer.

-La fusion de cellules génère du score pour le joueur. Celui-ci s'affiche dans un rectangle en haut à droite.
Le meilleur score est aussi comptabilisé et s'affiche en haut à droite dans le rectangle "Best".

-Le joueur peut relancer une nouvelle partie avec le bouton "New Game" ou dans le menu "File".

-Le joueur peut changer le jeu de couleurs (3 jeux au total) avec le bouton "Swap Colors". 
Il est à noter qu'un de ces jeux de couleurs est optimisé les daltoniens, peu importe leur type de daltonisme.

-Le joueur peut annuler ses mouvements avec le bouton "Undo", jusqu'à 256 fois.
Chaque Undo enlève des points au joueur, afin de garder un score juste.
Les mouvements de Undo sont conservés en mémoire, afin de permettre d'animer également ces transitions dans le bon sens.

-Lorsqu'aucun déplacement n'est possible, le jeu s'arrête et affiche une fenêtre "Game Over".
Le joueur peut relancer un nouveau jeu depuis cette fenêtre, ou quitter le jeu.

-La partie actuelle peut être sauvegardée depuis le menu "File", cliquer sur "Save Game" pour
sauvegarder la partie actuelle et "Load Game" pour charger la partie sauvegardée.
Une seule partie peut être sauvegardée.


Fonctionnalités à implémenter :

- Taille dynamique de texte : avoir une taille de police liée au nombre de chiffres du nombre de la case, afin d'éviter de déborder de la case, ce qui peut actuellement arriver pour les très gros nombres.

- Couleur dynamique du texte : ajouter la possibilité si souhaité d'avoir le texte des cases systématiquement de la couleur complémentaire au fond de la case, afin de maximiser la lisibilité

- Ajout de différents niveaux de difficulté : le jeu peut soit se faire en mode "facile" (le mode standard), ou en mode "difficile". 
En mode difficile, le placement des nouvelles cases sur le plateau n'est plus aléatoire, mais est pensé pour rendre la vie la plus dure possible au joueur, en suivant ces deux règles :
	- chaque nouvelle case est placée le plus possible dans la direction du dernier déplacement (on empêche ainsi souvent le joueur de jouer deux fois le même mouvement)
	- chaque nouvelle case est placée juste à coté de la case de plus haute valeur possible parmi les quatre disponibles (on empêche ainsi le joueur de pouvoir éventuellement empiler la nouvelle case immédiatement avec un autre 2)

- Ajout de la gestion dynamique du nombre de coups stockés : actuellement, on peut jouer au maximum 2048 coups à la suite, avant que la variable gardant en mémoire les coups joués soit pleine.
Dans l'idéal, il faudrait que cette variable puisse changer de taille en fonction du coup actuel, afin d'éviter de la saturer, et pour réduire la place prise en mémoire par l'exécution du programme.


Bugs connus : 

Aucun à ce jour