#include "gestionjeu.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//Constructeur
GestionJeu::GestionJeu(QObject *parent) : QObject(parent)
{
    maxUndo = 2048;      // choix du nombre max de coups annulables, si on joue plus que ce nombre de coup, on crash
    coupActuel = 0;
    coupActuelDir = 0;
    couleursActuelles = 0;
    initCouleurs();
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
    coupActuelDir = 0;
    alloc(nb_lig, nb_col);
    maxscore = max(maxscore, score);       // conservation en mémoire du meilleur score
    score = 0;
    perduChanged();
    statesChanged();
    xdir[coupActuel] = 1;       // animation de newgame différente d'un déplacement
    ydir[coupActuel] = -1;      // idem
    newCell();
    newCell();
}

// Initialisation de la liste des couleurs
void GestionJeu::initCouleurs()
{
    // Allocation de la liste des couleurs
    couleurs = new QString*[nbJeuxCouleurs];
    for (int i=0 ; i<nbJeuxCouleurs ; i++)
    {
        couleurs[i] = new QString[nbCouleursParJeu];
        for(int j=0; j<nbCouleursParJeu;j++)
        {
            couleurs[i][j]="";
        }
    }
    // Remplissage du tableau
    // Premier set de couleurs
    couleurs[0][0] = "#ece2d8"; // 2
    couleurs[0][1] = "#ede0c7"; // 4
    couleurs[0][2] = "#f2b179"; //...
    couleurs[0][3] = "#f59563";
    couleurs[0][4] = "#f97c60";
    couleurs[0][5] = "#f65e3c";
    couleurs[0][6] = "#ecce6e";
    couleurs[0][7] = "#eccb61"; // ...
    couleurs[0][8] = "#edc750"; // 512
    couleurs[0][9] = "#edc440"; // 1024
    couleurs[0][10] = "#ecc12d"; // 2048

    // Second set de couleurs
    couleurs[1][0] = "#5b5b83"; // 2
    couleurs[1][1] = "#44449f"; // 4
    couleurs[1][2] = "#4b4ac8"; //...
    couleurs[1][3] = "#8484fb";
    couleurs[1][4] = "#a6a6f7";
    couleurs[1][5] = "#adadde";
    couleurs[1][6] = "#575738";
    couleurs[1][7] = "#a6a64a"; // ...
    couleurs[1][8] = "#95955d"; // 512
    couleurs[1][9] = "#efef32"; // 1024
    couleurs[1][10] = "#e2e284"; // 2048

    // Troisième set de couleurs
    couleurs[2][0] = "#5c707b"; // 2
    couleurs[2][1] = "#42b5a6"; // 4
    couleurs[2][2] = "#9d600f"; //...
    couleurs[2][3] = "#b92c92";
    couleurs[2][4] = "#ffd203";
    couleurs[2][5] = "#00abd6";
    couleurs[2][6] = "#018752";
    couleurs[2][7] = "#ff6d00"; // ...
    couleurs[2][8] = "#c6d601"; // 512
    couleurs[2][9] = "#00457c"; // 1024
    couleurs[2][10] = "#f3426e"; // 2048
}

// Annulation du coup précédent
void GestionJeu::undo()
{
    if(coupActuel>0)
    {
        coupActuel--;
        score -= 16;
        statesChanged();
        perduChanged();     // annule un éventuel Game Over
        coupActuelDir--;
    }
}

// Changement du set de couleurs
void GestionJeu::swapColors()
{
    couleursActuelles++;
    couleursActuelles %= nbJeuxCouleurs;        // on évite de dépasser l'index de couleurs
    statesChanged();
}


// Allocation du tableau pour une nouvelle partie
void GestionJeu::alloc(int nb_l, int nb_c)
{
    xdir = new int[maxUndo];
    ydir = new int[maxUndo];
    tableau = new int**[maxUndo];
    for (int k = 0; k<maxUndo ; k++)
    {
        tableau[k] = new int*[nb_l];     //tableau d'entiers (valeurs cellules)
        xdir[k] = 0;
        ydir[k] = 0;
        for (int i=0 ; i<nb_l ; i++)
        {
            tableau[k][i] = new int[nb_c];
            for(int j=0; j<nb_c;j++)
            {
                tableau[k][i][j]=0;
            }
        }
    }
    nb_lig=nb_l;
    nb_col=nb_c;
}

// Suppression du jeu pour une nouvelle partie
void GestionJeu::free()
{
    for (int k = 0 ; k<maxUndo ; k++)
    {
        for (int i = 0; i<nb_lig; i++)
        {
            delete [] tableau[k][i];
        }
        delete [] tableau[k];
    }
    delete [] tableau;
    delete [] xdir;
    delete [] ydir;
}

// Création d'une copie de travail de tableau[coupActuel]
int** GestionJeu::copieActuel()
{
    int** tableauCopie;
    tableauCopie = new int*[nb_lig];
    for (int i = 0 ; i<nb_lig ; i++)
    {
        tableauCopie[i] = new int[nb_col];
        for (int j = 0 ; j<nb_col ; j++)
        {
            tableauCopie[i][j] = tableau[coupActuel][i][j];
        }
    }
    return tableauCopie;
}

// Remplacement de tableau[coupActuel] par une copie de travail fournie
void GestionJeu::remplacementCoupSuivant(int** copieTableau)
{
    for(int i = 0 ; i<nb_lig ; i++)
    {
        for (int j = 0 ; j<nb_col ; j++)
        {
            tableau[coupActuel][i][j] = copieTableau[i][j];
        }
        delete [] copieTableau[i];      // on supprime cette ligne dont on n'a plus besoin
    }
    delete [] copieTableau;     // on supprime la variable pour libérer de la mémoire
}

// Appel de cette fonction suite au signal statesChanged
// Aggrège les valeurs de toutes les variables utilisées dans le QML
// Transmet ces valeurs au QML
QList<QString> GestionJeu::readStates()
{
    QList<QString> liste;
    for (int i = 0 ; i<nb_lig ; i++)
    {
        for (int j = 0 ; j<nb_col ; j++)
        {
            if (tableau[coupActuel][i][j]==0)
            {
                liste.append(" ");      // si la case est vide, on n'affiche rien
            }
            else{
                liste.append(QString::number(tableau[coupActuel][i][j]));   // si elle est pleine, on affiche sa valeur
            }
        }
    }
    // Gestion de l'ajout des couleurs aux cases
    // TODO : ajouter encore quelques couleurs (aller jusqu'à 8192 ?)
    for (int i = 0 ; i<nb_lig ; i++)
    {
        for (int j = 0 ; j<nb_col ; j++)
        {
            if (tableau[coupActuel][i][j] == 0 || (tableau[coupActuel][i][j] > (pow(2,nbCouleursParJeu-1))))
            {
                liste.append("#b48f8f");        // la case est vide ou comporte une couleur non supportée
            }
            else
            {
                liste.append(couleurs[couleursActuelles][(int)log2(tableau[coupActuel][i][j])-1]); // on colorie la case avec la bonne couleur
            }
        }
    }
    liste.append((QString::number(score)));     // on transmet aussi le score actuel ...
    liste.append((QString::number(maxscore)));  // ... et le score max
    liste.append((QString::number(xdir[coupActuelDir])));      // on transmet le sens de déplacement vertical...
    liste.append((QString::number(ydir[coupActuelDir])));      // ... et horizontal
    return liste;
}

// Appel à cette fonction suite au signal perduChanged
// On verifie si la partie est perdue
// Si oui, on renvoie true, sinon false
// La partie est perdue si le tableau est plein ET que aucun mouvement n'est possible
bool GestionJeu::perduCheck()
{
    bool existNeighbour = false;       // variable déterminant si deux cases identiques sont voisines
    bool isFull = true;     // variable déterminant si le tableau est plein
    for (int i = 0 ; i<nb_lig-1 ; i++)
    {
        for (int j = 0 ; j<nb_col-1 ; j++)
        {
            if ((tableau[coupActuel][i][j] == tableau[coupActuel][i+1][j]) || (tableau[coupActuel][i][j] == tableau[coupActuel][i][j+1]))
                // si le voisin de droite ou du dessous sont identiques à la case étudiée...
            {
                existNeighbour = true; // ... on a trouvé des voisins identiques
            }
        }
    }
//    // on traite maintenant la case en bas à droite de la grille
//    if ((tableau[coupActuel][nb_lig-1][nb_col-1] == tableau[coupActuel][nb_lig-2][nb_col-1]) || (tableau[coupActuel][nb_lig-1][nb_col-1] == tableau[coupActuel][nb_lig-1][nb_col-2]))
//    {
//        existNeighbour = true;
//    }
//    // on traite la dernière ligne
//    if ((tableau[coupActuel][nb_lig-1][nb_col-1] == tableau[coupActuel][nb_lig-2][nb_col-1]) || (tableau[coupActuel][nb_lig-1][nb_col-1] == tableau[coupActuel][nb_lig-1][nb_col-2]))
//    {
//        existNeighbour = true;
//    }
    // on traite maintenant la dernière ligne
    for (int j = 1; j< nb_col-1;j++ )
    {
        if ((tableau[coupActuel][nb_lig-1][j] == tableau[coupActuel][nb_lig-1][j-1]) || (tableau[coupActuel][nb_lig-1][j] == tableau[coupActuel][nb_lig-1][j+1]))
        {
            existNeighbour = true;
        }
    }
    // on traite maintenant la dernière colonne
    for (int i = 1; i< nb_lig-1;i++ )
    {
        if ((tableau[coupActuel][i][nb_col-1] == tableau[coupActuel][i-1][nb_col-1]) || (tableau[coupActuel][i][nb_col-1] == tableau[coupActuel][i+1][nb_col-1]))
        {
            existNeighbour = true;
        }
    }





    if (!existNeighbour)        // il n'y a pas deux cases voisines identiques
    {
        for (int i = 0 ; i<nb_lig; i++)
        {
            for (int j = 0 ; j<nb_col; j++)
            {
                if (tableau[coupActuel][i][j] == 0)     // on vérifie si le tableau est plein
                {
                    isFull = false;
                }
            }
        }
        return isFull;
    }
    else        // deux cases voisines sont identiques, la partie n'est pas perdue
    {
        return false;
    }
}


// Génération d'une nouvelle cellule dans le jeu, à un emplacement aléatoire
// Quand cette fonction est appelée, on sait qu'il y a au moins une place libre
void GestionJeu::newCell()
{
    bool trouve = false;
    int i = 0;  // variables de recherche de case libre
    int j = 0;
    int num = 0;    // variable pour le choix de la valeur de la nouvelle case
    srand(clock());     // initialisation du seed de manière pseudo-aléatoire
    while(!trouve)
    {
        i = rand()%nb_lig;  // entier aleatoire entre 0 et nb_lig
        j = rand()%nb_col;  // idem avec nb_col
        if ((tableau[coupActuel][i][j])==0)  // case vide trouvee
        {
            trouve = true;
        }
    }
    num = rand() % 10;  // renvoie un entier aleatoire entre 0 et 9
    if(num==0)  // une fois sur dix, on a un 4
    {
        tableau[coupActuel][i][j]=4;
        //tableau[i][j].setColor("#fb7b7b");
    }
    else
    {
        tableau[coupActuel][i][j]=2;
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
    int** copieTableau = copieActuel();       // on créé une copie de travail du tableau[coupActuel]
    for(int j=1;j<nb_col;j++){
        //on commence à la deuxieme colonne car la première ne se déplace pas à gauche
        for(int i=0;i<nb_lig;i++){
            value=copieTableau[i][j];                    //valeur de la case traitée
            num_colonne=j;
            if (copieTableau[i][num_colonne-1]==0 && copieTableau[i][num_colonne]!=0){
                while((copieTableau[i][num_colonne-1]==0) && (num_colonne-1>=0)){
                    //tant que la case à gauche est vide, on se déplace à gauche
                    copieTableau[i][num_colonne]=0;
                    copieTableau[i][num_colonne-1]=value;    //déplacement à gauche
                    aBouge = true;      // un deplacement a eu lieu
                    num_colonne-=1;
                }
            }
            if ((num_colonne>0) && (copieTableau[i][num_colonne-1]==value) && copieTableau[i][num_colonne]!=0)  // en cas de probleme regarder ici (scinder les deux if)
            {
                copieTableau[i][num_colonne]=0;
                copieTableau[i][num_colonne-1]=2*value;
                score += 2*value;
                maxscore = max(maxscore, score);
                aBouge = true;    // un deplacement a eu lieu
            }
        }
    }
    if (aBouge)     // une nouvelle case n'apparait que si un mouvement a eu lieu
    {
        coupActuel += 1;    // on a joué un coup de plus
        coupActuelDir++;
        remplacementCoupSuivant(copieTableau);
        xdir[coupActuel] = 0;
        ydir[coupActuel] = -1;
        newCell();
        statesChanged();
    }
    else
    {
        perduChanged();
    }
}

void GestionJeu::deplDroite(){
    int value;
    int num_colonne;
    bool aBouge = false;
    int** copieTableau = copieActuel();
    for(int j=nb_col-2;j>=0;--j){
        //on commence a l'avant-derniere colonne car la derniere ne se déplace pas à droite
        for(int i=0;i<nb_lig;i++){
            value=copieTableau[i][j];                    //valeur de la case traitée
            num_colonne=j;
            if (copieTableau[i][num_colonne+1]==0 && copieTableau[i][num_colonne]!=0){
                while( (num_colonne+1<nb_col) && (copieTableau[i][num_colonne+1]==0)){
                    //tant que la case à droite est vide, on se déplace à droite
                    copieTableau[i][num_colonne]=0;
                    copieTableau[i][num_colonne+1]=value;    //déplacement à droite
                    aBouge = true;
                    num_colonne += 1;
                }
            }
            if ((num_colonne+1<nb_col) && (copieTableau[i][num_colonne+1]==value && copieTableau[i][num_colonne]!=0))  // en cas de probleme regarder ici (scinder les deux if)
            {
                copieTableau[i][num_colonne]=0;
                copieTableau[i][num_colonne+1]=2*value;
                score += 2*value;
                maxscore = max(maxscore, score);
                aBouge = true;
            }
        }
    }
    if(aBouge)
    {
        coupActuel += 1;
        coupActuelDir++;
        remplacementCoupSuivant(copieTableau);
        xdir[coupActuel] = 0;
        ydir[coupActuel] = 1;
        newCell();
        statesChanged();
    }
    else
    {
        perduChanged();
    }
}

void GestionJeu::deplHaut(){
    int value;
    int num_ligne;
    bool aBouge = false;
    int** copieTableau = copieActuel();
    for(int i=1;i<nb_lig;i++){
        for (int j=0;j<nb_col;j++){
            value=copieTableau[i][j];
            num_ligne=i;
            if(copieTableau[num_ligne-1][j]==0 && copieTableau[num_ligne][j]!=0){
                while((num_ligne-1>=0) && (copieTableau[num_ligne-1][j]==0)){
                    //if(num_ligne>nb_lig){ cout<<"probleme"<<endl;}
                    copieTableau[num_ligne-1][j]=value;
                    copieTableau[num_ligne][j]=0;
                    aBouge = true;
                    num_ligne-=1;
                }
            }
            if((num_ligne>0) && (copieTableau[num_ligne-1][j]==value) && copieTableau[num_ligne][j]!=0){
                copieTableau[num_ligne-1][j]=2*value;
                copieTableau[num_ligne][j]=0;
                score += 2*value;
                maxscore = max(maxscore, score);
                aBouge = true;
            }
        }

    }
    if(aBouge)
    {
        coupActuel += 1;
        coupActuelDir++;
        remplacementCoupSuivant(copieTableau);
        xdir[coupActuel] = -1;
        ydir[coupActuel] = 0;
        newCell();
        statesChanged();
    }
    else
    {
        perduChanged();
    }
}

void GestionJeu::deplBas(){
    int value;
    int num_ligne;
    bool aBouge = false;
    int** copieTableau = copieActuel();
    for(int i=nb_lig-2;i>=0;--i){
        //on commence à l'avant dernière ligne et on remplit d'abord la dernière ligne
        for(int j=0;j<nb_col;j++){
            value=copieTableau[i][j];
            num_ligne=i;
            if(copieTableau[num_ligne+1][j]==0 && copieTableau[num_ligne][j]!=0){
                while((num_ligne+1<nb_lig) && (copieTableau[num_ligne+1][j]==0)){
                    copieTableau[num_ligne][j]=0;
                    copieTableau[num_ligne+1][j]=value;
                    aBouge = true;
                    num_ligne+=1;
                }
            }

            if((num_ligne+1<nb_lig) && copieTableau[num_ligne+1][j]==value && copieTableau[num_ligne][j]!=0){
                copieTableau[num_ligne+1][j]=2*value;
                copieTableau[num_ligne][j]=0;
                score += 2*value;
                maxscore = max(maxscore, score);
                aBouge = true;
            }
        }
    }
    if(aBouge)
    {
        coupActuel += 1;
        coupActuelDir++;
        remplacementCoupSuivant(copieTableau);
        xdir[coupActuel] = 1;
        ydir[coupActuel] = 0;
        newCell();
        statesChanged();
        //cout << coupActuel << endl;
    }
    else
    {
        perduChanged();
    }
}


//-------------GESTION SAUVEGARDE------------------//


void GestionJeu::saveGame(){

    ofstream fichier("sauvegarde.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    if(fichier)
        {
        int taille;
        taille=min(coupActuel,maxUndo);             //nombre d'éléments du tableau à stocker

        fichier<<"Nombres lignes et colonnes :"<<endl;
        fichier<<nb_lig<<endl;
        fichier<<nb_col<<endl;
        fichier<<"Coup actuel :"<<endl;
        fichier<<coupActuel<<endl;

        fichier<<"Tableau :"<<endl;
        for(int coup=0;coup<=taille;coup++){
            for(int i=0;i<nb_lig;i++){
                for(int j=0;j<nb_col;j++){
                    fichier << tableau[coup][i][j]<<endl;
                }
            }
        }

        fichier<<"Numéro couleurs actuelles :"<<endl;
        fichier<<couleursActuelles<<endl;
        fichier<<"Score et maxscore :"<<endl;
        fichier<<score<<endl;
        fichier<<maxscore<<endl;
        fichier<<"Historique déplacements :"<<endl;
        //fichier<<xdir<<endl;          //nécessaire à stocker?
        //fichier<<ydir<<endl;

        fichier.close();
        }

    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void GestionJeu::loadGame(){
    ifstream fichier("sauvegarde.txt", ios::in); //ouverture du fichier en lecture
    if (fichier){

        string ligne;                 //variable contenant la ligne lue

        getline(fichier,ligne);       //première ligne, texte
        //récupération nb_lig, nb_col
        getline(fichier,ligne);
        nb_lig=stoi(ligne);           //conversion string -> entier
        getline(fichier,ligne);
        nb_col=stoi(ligne);

        //création d'un nouveau tableau
        free();
        alloc(nb_lig,nb_col);

        //récupération coupActuel
        getline(fichier,ligne);
        getline(fichier,ligne);
        coupActuel=stoi(ligne);
        coupActuelDir=stoi(ligne);

        //récupération du tableau
        int taille;
        taille=min(coupActuel,maxUndo);
        cout<<taille<<endl;
        cout<<coupActuel<<endl;
        cout<<nb_lig<<endl;
        cout<<nb_col<<endl;

        getline(fichier,ligne);
        for(int coup=0;coup<=taille;coup++){
            for(int i=0;i<nb_lig;i++){
                for(int j=0;j<nb_col;j++){
                    getline(fichier,ligne);
                    tableau[coup][i][j]=stoi(ligne);
                }
            }
        }

        //récupération des couleurs
        getline(fichier,ligne);
        getline(fichier,ligne);
        couleursActuelles=stoi(ligne);

        //récupération des scores
        getline(fichier,ligne);
        getline(fichier,ligne);
        score=stoi(ligne);
        getline(fichier,ligne);
        maxscore=stoi(ligne);

        //relance de la partie
        perduChanged();         //à mettre?
        statesChanged();

        fichier.close();

        for(int n=0;n<nb_lig;n++){
            for(int m=0;m<nb_col;m++){
                cout<<"tableau: "<<tableau[coupActuel][n][m];
            }
            cout<<endl;
        }
    }
    else
        cerr<<"Impossible d'ouvrir le fichier"<<endl;
}

