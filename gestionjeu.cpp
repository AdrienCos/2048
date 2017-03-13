#include "gestionjeu.h"

//Constructeur
GestionJeu::GestionJeu(QObject *parent) : QObject(parent)
{

}

// Nouvelle Partie
void GestionJeu::NewGame(int nb_lig, int nb_col)
{
    Free();     // liberation de memoire
    this->nb_col = nb_col;
    this->nb_lig = nb_lig;
    Alloc();

}


// Allocation du tableau
void GestionJeu::Alloc(int nb_lig, int nb_col)
{
    tableau = new Cell**[nb_lig];
    for (int i=0 ; i<nb_col ; i++)
    {
        tableau[i] = new Cell*[nb_col];
    }
}

void GestionJeu::Free()
{
    for (int i = 0; i<nb_lig; i++)
    {
        delete [] tableau[i];
    }
    delete [] tableau;
}
