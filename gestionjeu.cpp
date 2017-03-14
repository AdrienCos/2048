#include "gestionjeu.h"

//Constructeur
GestionJeu::GestionJeu(QObject *parent) : QObject(parent)
{

}

// Nouvelle Partie
void GestionJeu::newGame(int nb_lig, int nb_col)
{
    Free();     // liberation de memoire
    this->nb_col = nb_col;
    this->nb_lig = nb_lig;
    Alloc();
    NewCell();
    NewCell();
}


// Allocation du tableau pour une nouvelle partie
void GestionJeu::alloc(int nb_lig, int nb_col)
{
    tableau = new Cell**[nb_lig];
    for (int i=0 ; i<nb_col ; i++)
    {
        tableau[i] = new Cell*[nb_col];
    }
}

// Suppression du jeu pour une nouvelle partie
void GestionJeu::free()
{
    for (int i = 0; i<nb_lig; i++)
    {
        delete [] tableau[i];
    }
    delete [] tableau;
}

// Génération d'une nouvelle Cell dans le jeu, a un emplacement aléatoire
// TODO : gestion de la fin de la partie
void GestionJeu::newCell()
{
    bool trouve=false;
    int i;  // variables de recherche de case libre
    int j;
    int num;    // variable pour le choix de la valeur
    while(!trouve)
    {
        i = rand() % this->nb_lig;  // entier aleatoire entre 0 et nb_lig
        j = rand() % this->nb_col;  // idem avec nb_col
        if (!(tableau[i][j]->getExiste()))  // case vide trouvée
        {
            trouve = true;
        }
    }
    tableau[i][j]->setExiste(true);
    num = rand() % 10;  // renvoie un entier aleatoire entre 0 et 9
    if(num==0)  // une fois sur dix, on a un 4
    {
        tableau[i][j]->setValue(4);
        tableau[i][j]->setColor("#fb7b7b");
    }
    else
    {
        tableau[i][j]->setValue(2);
        tableau[i][j]->setColor("#fc9e9e");
    }

}
