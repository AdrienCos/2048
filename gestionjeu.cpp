#include "gestionjeu.h"
#include <iostream>
using namespace std;

//Constructeur
GestionJeu::GestionJeu(QObject *parent) : QObject(parent)
{
    etat="en cours";
    alloc(4,4);
    newCell();
    newCell();
    arretJeu();    //permet de lancer la partie(met le focus à true)
}

// Nouvelle Partie
void GestionJeu::newGame(int nb_lig, int nb_col)
{
    free();     // liberation de memoire
    alloc(nb_lig, nb_col);
    newCell();
    newCell();
    etat="en cours";
    arretJeu();
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
    //on vérifie d'abord s'il y a encore de la place
    int compteur=0;
    for(int x=0;x<nb_lig;x++) {
        for(int y=0;y<nb_lig;y++){
            if(tableau[x][y]==0){
                compteur+=1;
            }
        }
    }

    //s'il reste de la place:
    if(compteur!=0){
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
        finPartie();            //verif s'il y a un 2048
        arret();
        }

    //sinon, on ne peut plus remplir, donc on arrête on arrête la partie en verifiant si c'est gagné ou perdu
    //mais il est possible qu'on soit arriver ici parce qu'une direction n'est plus possible
    //cad à gauche: ça ne bouge plus, par contre vers le bas c'est possible
    //Revoir les conditions... exceptions?...
    else
    {
        finPartie();
        arret();
    }
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
    for(int j=nb_col-2;j>=0;--j){
        //on commence a l'avant-derniere colonne car la derniere ne se déplace pas à droite
        for(int i=0;i<nb_lig;i++){
            value=tableau[i][j];                    //valeur de la case traitée
            num_colonne=j;
            if (tableau[i][num_colonne+1]==0){
                while( (num_colonne+1<nb_col) && (tableau[i][num_colonne+1]==0)){
                    //tant que la case à droite est vide, on se déplace à droite
                    tableau[i][num_colonne]=0;
                    tableau[i][num_colonne+1]=value;    //déplacement à droite
                    num_colonne+=1;
                }
            }
            if ((num_colonne+1<nb_col) && (tableau[i][num_colonne+1]==value))  // en cas de probleme regarder ici (scinder les deux if)
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
        for (int j=0;j<nb_col;j++){
            value=tableau[i][j];
            num_ligne=i;
            if(tableau[num_ligne-1][j]==0){
                while((num_ligne-1>=0) && (tableau[num_ligne-1][j]==0)){
                    if(num_ligne>nb_lig){ cout<<"probleme"<<endl;}
                    tableau[num_ligne-1][j]=value;
                    tableau[num_ligne][j]=0;
                    num_ligne-=1;
                }
            }
            if((num_ligne>0) && (tableau[num_ligne-1][j]==value)){
                tableau[num_ligne-1][j]=2*value;
                tableau[num_ligne][j]=0;
            }
        }

    }

    newCell();
    statesChanged();

}

void GestionJeu::deplBas(){
    int value;
    int num_ligne;
    for(int i=nb_lig-2;i>=0;--i){
        //on commence à l'avant dernière ligne et on remplit d'abord la dernière ligne
        for(int j=0;j<nb_col;j++){
            value=tableau[i][j];
            num_ligne=i;
            if(tableau[num_ligne+1][j]==0){
                while((num_ligne+1<nb_lig) && (tableau[num_ligne+1][j]==0)){
                    tableau[num_ligne][j]=0;
                    tableau[num_ligne+1][j]=value;
                    num_ligne+=1;
                }
            }

            if((num_ligne+1<nb_lig) && tableau[num_ligne+1][j]==value){
                tableau[num_ligne+1][j]=2*value;
                tableau[num_ligne][j]=0;
            }
        }
    }

    newCell();
    //gestion fin de la partie:
    // on peut rajouter ici un appel à une fonction "verifFinPartie()"
    // qui parcourt le tableau
    // Si elle trouve la valeur 2048, on renvoie un message "Vous avez gagné"
    // Si elle ne trouve aucun zéro, on renvoie un message "Vous avez perdu"
    // Dans le cas où il n'y a plus de zéron il faut trouver comment arrêter le jeu
    // par exemple essayer de mettre le focus à false pour le Keys.onPressed


    statesChanged();


}

//----------------Gestion Fin de Partie ------------------//

QString GestionJeu::verifFinPartie(){
    //permet d'envoyer un message au joueur lorsqu'il gagne ou perd

    QString res;             //resultat envoyé au QML
    res="";
    for(int i=0;i<nb_lig;i++){
        for(int j=0;j<nb_col;j++){
            if(tableau[i][j]==2048){
                etat="gagne";
                res="gagne";
                return res;
            }

        }
    }
   if((etat!="en cours") && (etat!="gagne")){
       res="perdu";
       }
   return res;
}

bool GestionJeu::arretJeu(){
    //permet d'arrêter la partie en mettant le focus à false
    if(etat=="gagne" || etat=="perdu")
    {
        return false;
    }
    else{
        return true;
    }
}
