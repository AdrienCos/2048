#include "gestionjeu.h"

//Constructeur
GestionJeu::GestionJeu(QObject *parent) : QObject(parent)
{
    alloc(4,4);
    newCell();
    newCell();
}

// Nouvelle Partie
void GestionJeu::newGame(int nb_lig, int nb_col)
{
    free();     // liberation de memoire
    alloc(nb_lig, nb_col);
    newCell();
    newCell();
}


// Allocation du tableau pour une nouvelle partie
void GestionJeu::alloc(int nb_l, int nb_c)
{
    tableau = new int*[nb_l];     //tableau d'entiers (valeurs cellules)
    for (int i=0 ; i<nb_l ; i++)
    {
        tableau[i] = new int[nb_c];
        for(int j=0; j<nb_c;j++)
        {
            tableau[i][j]=0;
        }
    }
    nb_lig=nb_l;
    nb_col=nb_c;
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

// Appel de cette fonction suite au signal statesChanged
QList<QString> GestionJeu::readStates()
{

    QList<QString> liste;
    int cpt=0;
    for (int i = 0 ; i<nb_lig ; i++)
    {
        for (int j = 0 ; j<nb_col ; j++)
        {
            liste.append(QString::number(tableau[i][j]));
            cpt++;
        }
    }
    return liste;
}

// Génération d'une nouvelle cellule dans le jeu, à un emplacement aléatoire
// TODO : gestion de la fin de la partie
void GestionJeu::newCell()
{
    bool trouve=false;
    int i=0;  // variables de recherche de case libre
    int j=0;
    int num;    // variable pour le choix de la valeur
    while(!trouve)
    {
        i = rand()%nb_lig;  // entier aleatoire entre 0 et nb_lig
        j = rand()%nb_col;  // idem avec nb_col
        if ((tableau[i][j])==0)  // case vide trouvee
        {
            trouve = true;
        }
    }

    num = rand() % 10;  // renvoie un entier aleatoire entre 0 et 9
    if(num==0)  // une fois sur dix, on a un 4
    {
        tableau[i][j]=4;
        //tableau[i][j].setColor("#fb7b7b");
    }
    else
    {
        tableau[i][j]=2;
        //tableau[i][j].setColor("#fc9e9e");
    }
    statesChanged();
}

//-------GESTION DES DEPLACEMENTS------------//

void GestionJeu::deplGauche(){
    int value;
    int num_colonne;
    for(int j=1;j<nb_col;j++){
        //on commence à la deuxieme colonne car la première ne se déplace pas à gauche
        for(int i=0;i<nb_lig;i++){
            value=tableau[i][j];                    //valeur de la case traitée
            num_colonne=j;
            if (tableau[i][num_colonne-1]==0){
                while((tableau[i][num_colonne-1]==0) && (num_colonne-1>=0)){
                    //tant que la case à gauche est vide, on se déplace à gauche
                    tableau[i][num_colonne]=0;
                    tableau[i][num_colonne-1]=value;    //déplacement à gauche
                    num_colonne-=1;
                }
            }
            if ((num_colonne>0) && (tableau[i][num_colonne-1]==value))  // en cas de probleme regarder ici (scinder les deux if)
            {
                tableau[i][num_colonne]=0;
                tableau[i][num_colonne-1]=2*value;

            }
        }
    }
    statesChanged();

}
