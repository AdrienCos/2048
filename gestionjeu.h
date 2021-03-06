#ifndef GESTIONJEU_H
#define GESTIONJEU_H

#include <QObject>
#include <time.h>
#include <string>
using namespace std;

class GestionJeu : public QObject
{
    Q_OBJECT
public:
    explicit GestionJeu(QObject *parent = 0);

    Q_PROPERTY(QList<QString> states READ readStates NOTIFY statesChanged)
    Q_PROPERTY(bool perdu READ perduCheck NOTIFY perduChanged)

    // Méthode de création d'une nouvelle partie
    Q_INVOKABLE void newGame(int nb_lig, int nb_col);

    // Méthode d'annulation du coup précédent
    Q_INVOKABLE void undo();

    // Méthode de changement du set de couleurs
    Q_INVOKABLE void swapColors();

    //Méthode de sauvegarde du jeu
    Q_INVOKABLE void saveGame();

    //Méthode de chargement d'un jeu sauvegardé
    Q_INVOKABLE void loadGame();

    // Méthodes de création et suppression de copie de travail de tableau[coupActuel]
    int** copieActuel();
    void remplacementCoupSuivant(int** copieTableau);

    // Méthodes de déplacement
    Q_INVOKABLE void deplGauche();
    Q_INVOKABLE void deplDroite();
    Q_INVOKABLE void deplHaut();
    Q_INVOKABLE void deplBas();

    // Methode de transmission des infos au QML
    QList<QString> readStates();
    bool perduCheck();     // permet de savoir si la partie est perdue

    // Méthode d'initialisation de la liste de couleurs
    void initCouleurs();

private:

    int nb_lig;
    int nb_col;
    int*** tableau;         //liste des valeurs des cellules
    QString** couleurs;     // tableau des couleurs disponibles
    int couleursActuelles;  // position des couleurs utilisées
    int nbJeuxCouleurs = 3;     // nombre de jeux de couleurs
    int nbCouleursParJeu = 11;   // nombre de couleurs par jeu

    int maxUndo;        // nombre max d'undo réalisables à la suite
    int coupActuel;     // suivi du numéro du coup actuel
    int coupActuelDir;  // vaut coupActuel, sauf lors de l'appel de Undo, où il se met à jour après l'animation

    void free();
    void alloc(int nb_lig , int nb_col);
    void newCell();

    int score;      // score actuel de la partie
    int maxscore;   // score maximal sur toute la durée de jeu

    int* xdir;   // historique des déplacements dans le sens vertical
    int* ydir;   // historique des déplacements dans le sens horizontal



signals:
    void statesChanged();
    void perduChanged();

public slots:

};

#endif // GESTIONJEU_H
