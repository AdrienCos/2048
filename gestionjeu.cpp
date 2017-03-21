#include "gestionjeu.h"
#include <iostream>
using namespace std;

//Constructeur
GestionJeu::GestionJeu(QObject *parent) : QObject(parent)
{
    maxUndo = 256;      // choix du nombre max de coups annulables
    coupActuel = 0;
    alloc(4,4);
    score = 0;
    maxscore = 0;       // initialisation du score maximum
    newCell();
    newCell();
}

// Nouvelle Partie
void GestionJeu::newGame(int nb_lig, int nb_col)
{
    free();     // liberation de memoire
    coupActuel = 0;
    alloc(nb_lig, nb_col);
    maxscore = max(maxscore, score);       // conservation en mémoire du meilleur score
    score = 0;
    newCell();
    newCell();
}

// Annulation du coup précédent
void GestionJeu::undo()
{
    if(coupActuel>0)
    {
        coupActuel--;
    }
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
// Transmet les valeurs des cases et les scores
// TODO : transmettre aussi les couleurs des cases
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
    // Gestion de l'ajout des couleurs aux cases
    // TODO : ajouter encore quelques couleurs (aller jusqu'à 8192 ?)
    for (int i = 0 ; i<nb_lig ; i++)
    {
        for (int j = 0 ; j<nb_col ; j++)
        {
            if (tableau[i][j]==2)
            {
                liste.append("#ece2d8");
            }
            else if(tableau[i][j]==4)
            {
                liste.append("#eadec6");
            }
            else if(tableau[i][j] == 8)
            {
                liste.append("#f0b17a");
            }
            else if(tableau[i][j] == 16)
            {
                liste.append("#F49563");
            }
            else if(tableau[i][j] == 32)
            {
                liste.append("#F57E61");
            }
            else if(tableau[i][j] == 64)
            {
                liste.append("#F55F3C");
            }
            else if(tableau[i][j] == 128)
            {
                liste.append("#EDCF75");
            }
            else if(tableau[i][j] == 256)
            {
                liste.append("#EDCF5B");
            }
            else if(tableau[i][j] == 512)
            {
                liste.append("#ECC955");
            }
            else
            {
                liste.append("#b48f8f");
            }
        }
    }
    liste.append((QString::number(score)));     // on transmet aussi le score actuel ...
    liste.append((QString::number(maxscore)));  // ... et le score max
    return liste;
}

// Génération d'une nouvelle cellule dans le jeu, à un emplacement aléatoire
// Quand cette fonction est appelée, on sait qu'il y a au moins une place libre
// TODO : gestion de la fin de la partie
void GestionJeu::newCell()
{
    bool trouve = false;
    int i = 0;  // variables de recherche de case libre
    int j = 0;
    int num = 0;    // variable pour le choix de la valeur de la nouvelle case
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
    //sinon, on ne peut plus remplir, donc on arrête on arrête la partie en verifiant si c'est gagné ou perdu
    //mais il est possible qu'on soit arriver ici parce qu'une direction n'est plus possible
    //cad à gauche: ça ne bouge plus, par contre vers le bas c'est possible
    //Revoir les conditions... exceptions?...
}


//-------GESTION DES DEPLACEMENTS------------//

void GestionJeu::deplGauche(){
    int value;
    int num_colonne;
    bool  aBouge = false;       // test pour voir si un mouvement a eu lieu
    for(int j=1;j<nb_col;j++){
        //on commence à la deuxieme colonne car la première ne se déplace pas à gauche
        for(int i=0;i<nb_lig;i++){
            value=tableau[i][j];                    //valeur de la case traitée
            num_colonne=j;
            if (tableau[i][num_colonne-1]==0 && tableau[i][num_colonne]!=0){
                while((tableau[i][num_colonne-1]==0) && (num_colonne-1>=0)){
                    //tant que la case à gauche est vide, on se déplace à gauche
                    tableau[i][num_colonne]=0;
                    tableau[i][num_colonne-1]=value;    //déplacement à gauche
                    aBouge = true;      // un deplacement a eu lieu
                    num_colonne-=1;
                }
            }
            if ((num_colonne>0) && (tableau[i][num_colonne-1]==value) && tableau[i][num_colonne]!=0)  // en cas de probleme regarder ici (scinder les deux if)
            {
                tableau[i][num_colonne]=0;
                tableau[i][num_colonne-1]=2*value;
                score += 2*value;
                maxscore = max(maxscore, score);
                aBouge = true;    // un deplacement a eu lieu
            }
        }
    }
    if (aBouge)     // une nouvelle case n'apparait que si un mouvement a eu lieu
    {
        newCell();
        statesChanged();
        coupActuel += 1;    // on a joué un coup de plus
    }
}

void GestionJeu::deplDroite(){
    int value;
    int num_colonne;
    bool aBouge = false;
    for(int j=nb_col-2;j>=0;--j){
        //on commence a l'avant-derniere colonne car la derniere ne se déplace pas à droite
        for(int i=0;i<nb_lig;i++){
            value=tableau[i][j];                    //valeur de la case traitée
            num_colonne=j;
            if (tableau[i][num_colonne+1]==0 && tableau[i][num_colonne]!=0){
                while( (num_colonne+1<nb_col) && (tableau[i][num_colonne+1]==0)){
                    //tant que la case à droite est vide, on se déplace à droite
                    tableau[i][num_colonne]=0;
                    tableau[i][num_colonne+1]=value;    //déplacement à droite
                    aBouge = true;
                    num_colonne += 1;
                }
            }
            if ((num_colonne+1<nb_col) && (tableau[i][num_colonne+1]==value && tableau[i][num_colonne]!=0))  // en cas de probleme regarder ici (scinder les deux if)
            {
                tableau[i][num_colonne]=0;
                tableau[i][num_colonne+1]=2*value;
                score += 2*value;
                maxscore = max(maxscore, score);
                aBouge = true;
            }
        }
    }
    if(aBouge)
    {
        newCell();
        statesChanged();
        coupActuel += 1;
    }
}

void GestionJeu::deplHaut(){
    int value;
    int num_ligne;
    bool aBouge = false;
    for(int i=1;i<nb_lig;i++){
        for (int j=0;j<nb_col;j++){
            value=tableau[i][j];
            num_ligne=i;
            if(tableau[num_ligne-1][j]==0 && tableau[num_ligne][j]!=0){
                while((num_ligne-1>=0) && (tableau[num_ligne-1][j]==0)){
                    if(num_ligne>nb_lig){ cout<<"probleme"<<endl;}
                    tableau[num_ligne-1][j]=value;
                    tableau[num_ligne][j]=0;
                    aBouge = true;
                    num_ligne-=1;
                }
            }
            if((num_ligne>0) && (tableau[num_ligne-1][j]==value) && tableau[num_ligne][j]!=0){
                tableau[num_ligne-1][j]=2*value;
                tableau[num_ligne][j]=0;
                score += 2*value;
                maxscore = max(maxscore, score);
                aBouge = true;
            }
        }

    }
    if(aBouge)
    {
        newCell();
        statesChanged();
        coupActuel += 1;
    }
}

void GestionJeu::deplBas(){
    int value;
    int num_ligne;
    bool aBouge = false;
    for(int i=nb_lig-2;i>=0;--i){
        //on commence à l'avant dernière ligne et on remplit d'abord la dernière ligne
        for(int j=0;j<nb_col;j++){
            value=tableau[i][j];
            num_ligne=i;
            if(tableau[num_ligne+1][j]==0 && tableau[num_ligne][j]!=0){
                while((num_ligne+1<nb_lig) && (tableau[num_ligne+1][j]==0)){
                    tableau[num_ligne][j]=0;
                    tableau[num_ligne+1][j]=value;
                    aBouge = true;
                    num_ligne+=1;
                }
            }

            if((num_ligne+1<nb_lig) && tableau[num_ligne+1][j]==value && tableau[num_ligne][j]!=0){
                tableau[num_ligne+1][j]=2*value;
                tableau[num_ligne][j]=0;
                score += 2*value;
                maxscore = max(maxscore, score);
                aBouge = true;
            }
        }
    }
    if(aBouge)
    {
        newCell();
        statesChanged();
        coupActuel += 1;
        cout << coupActuel << endl;
    }
}



//----------------Gestion Fin de Partie ------------------//
