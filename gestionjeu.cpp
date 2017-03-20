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
    for (int i = 0 ; i<nb_lig ; i++)
    {
        for (int j = 0 ; j<nb_col ; j++)
        {
            if (tableau[i][j]==0)
            {
                liste.append(" ");      // si la case est vide, on n'affiche rien
            }
            else{
                liste.append(QString::number(tableau[i][j]));   // si elle est pleine, on affiche sa valeur
            }
        }
    }
    return liste;
}

// Génération d'une nouvelle cellule dans le jeu, à un emplacement aléatoire
// TODO : gestion de la fin de la partie
void GestionJeu::newCell()
{
    bool trouve = false;
    int i = 0;  // variables de recherche de case libre
    int j = 0;
    int num = 0;    // variable pour le choix de la valeur
    srand(time(0));     // initialisation du seed
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
/* Info pour Alexandre : l'algo actuel pose un souci dans le cas suivant :
 *
 *  - - - -
 *  - 2 4 -
 *  - - - -
 *  - - - -
 *
 * si on demande un mouvement à droite ou a gauche, seule une des cases bouge (le 2 en cas de mouvement à gauche, la 4 en cas de mouvement à droite)
 * car sa voisine détecte que la case d'a coté n'est pas vide (elle n'a pas encore été vidée par l'algo)
 * Une solution possible selon moi est de repasser plusieurs fois l'algo (tourner nb_col-1 fois en cas de déplacement gauche-droite, et (nb_lig-1)
 * fois en cas de déplacement haut-bas.
 */

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
    newCell();
    statesChanged();
}

void GestionJeu::deplDroite(){
    int value;
    int num_colonne;
    for(int j=0;j<(nb_col-1);j++){
        //on finit a l'avant-derniere colonne car la derniere ne se déplace pas à gauche
        for(int i=0;i<nb_lig;i++){
            value=tableau[i][j];                    //valeur de la case traitée
            num_colonne=j;
            if (tableau[i][num_colonne+1]==0){
                while((tableau[i][num_colonne+1]==0) && (num_colonne+2<=nb_col)){
                    //tant que la case à droite est vide, on se déplace à droite
                    tableau[i][num_colonne]=0;
                    tableau[i][num_colonne+1]=value;    //déplacement à droite
                    num_colonne+=1;
                }
            }
            if ((num_colonne<nb_col) && (tableau[i][num_colonne+1]==value))  // en cas de probleme regarder ici (scinder les deux if)
            {
                tableau[i][num_colonne]=0;
                tableau[i][num_colonne+1]=2*value;
            }
        }
    }
    newCell();
    statesChanged();
}

void GestionJeu::deplHaut(){
    int value;
    int num_ligne;
    for(int i=1;i<nb_lig;i++){
        //on commence a la seconde ligne car la permiere ne se déplace pas en haut
        for(int j=0;i<nb_col;j++){
            value=tableau[i][j];                    //valeur de la case traitée
            num_ligne=i;
            if (tableau[num_ligne-1][j]==0){
                while((tableau[num_ligne-1][j]==0) && (num_ligne-1>=0)){
                    //tant que la case à droite est vide, on se déplace à droite
                    tableau[num_ligne][j]=0;
                    tableau[num_ligne-1][j]=value;    //déplacement à droite
                    num_ligne-=1;
                }
            }
            if ((num_ligne>0) && (tableau[num_ligne-1][j]==value))  // en cas de probleme regarder ici (scinder les deux if)
            {
                tableau[num_ligne][j]=0;
                tableau[num_ligne-1][j]=2*value;
            }
        }
    }
    newCell();
    statesChanged();
}
