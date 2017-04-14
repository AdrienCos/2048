Application 2048 par Adrien Cosson et Alexandre Cartier


Fonctionnalit�s de l'application :

-Lorsque l'utilisateur lance le jeu, une nouvelle partie de 2048 commence (deux nouvelles cellules sont g�n�r�es).
Il peut alors jouer en utilisant les fl�ches ou les touches z,q,s,d afin de d�placer les cellules.
Lorsque deux cellules contenant des chiffres sont identiques, elles fusionnent et leur valeurs s'additionnent.
Une animation s'ex�cute quand une cellule se d�place ou apparait.

-Lorsqu'il y a un d�placement, une nouvelle cellule est cr��e al�atoirement dans les cases libres.
La probabilit� d'apparition d'un 4 est de 1/10.
Il ne se passe rien si on d�clenche un d�placement dans une direction o� aucune cellule ne peut se d�placer.

-La fusion de cellules g�n�re du score pour le joueur. Celui-ci s'affiche dans un rectangle en haut � droite.
Le meilleur score est aussi comptabilis� et s'affiche en haut � droite dans le rectangle "Best".

-Le joueur peut relancer une nouvelle partie avec le bouton "New Game" ou dans le menu "File".

-Le joueur peut changer le jeu de couleurs (3 jeux au total) avec le bouton "Swap Colors". 
Il est � noter qu'un de ces jeux de couleurs est optimis� les daltoniens, peu importe leur type de daltonisme.

-Le joueur peut annuler ses mouvements avec le bouton "Undo", jusqu'� 256 fois.
Chaque Undo enl�ve des points au joueur, afin de garder un score juste.
Les mouvements de Undo sont conserv�s en m�moire, afin de permettre d'animer �galement ces transitions dans le bon sens.

-Lorsqu'aucun d�placement n'est possible, le jeu s'arr�te et affiche une fen�tre "Game Over".
Le joueur peut relancer un nouveau jeu depuis cette fen�tre, ou quitter le jeu.

-La partie actuelle peut �tre sauvegard�e depuis le menu "File", cliquer sur "Save Game" pour
sauvegarder la partie actuelle et "Load Game" pour charger la partie sauvegard�e.
Une seule partie peut �tre sauvegard�e.


Fonctionnalit�s � impl�menter :

- Taille dynamique de texte : avoir une taille de police li�e au nombre de chiffres du nombre de la case, afin d'�viter de d�border de la case, ce qui peut actuellement arriver pour les tr�s gros nombres.

- Couleur dynamique du texte : ajouter la possibilit� si souhait� d'avoir le texte des cases syst�matiquement de la couleur compl�mentaire au fond de la case, afin de maximiser la lisibilit�

- Ajout de diff�rents niveaux de difficult� : le jeu peut soit se faire en mode "facile" (le mode standard), ou en mode "difficile". 
En mode difficile, le placement des nouvelles cases sur le plateau n'est plus al�atoire, mais est pens� pour rendre la vie la plus dure possible au joueur, en suivant ces deux r�gles :
	- chaque nouvelle case est plac�e le plus possible dans la direction du dernier d�placement (on emp�che ainsi souvent le joueur de jouer deux fois le m�me mouvement)
	- chaque nouvelle case est plac�e juste � cot� de la case de plus haute valeur possible parmi les quatre disponibles (on emp�che ainsi le joueur de pouvoir �ventuellement empiler la nouvelle case imm�diatement avec un autre 2)

- Ajout de la gestion dynamique du nombre de coups stock�s : actuellement, on peut jouer au maximum 2048 coups � la suite, avant que la variable gardant en m�moire les coups jou�s soit pleine.
Dans l'id�al, il faudrait que cette variable puisse changer de taille en fonction du coup actuel, afin d'�viter de la saturer, et pour r�duire la place prise en m�moire par l'ex�cution du programme.


Bugs connus : 

Aucun � ce jour