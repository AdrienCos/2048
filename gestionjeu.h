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
    //Q_PROPERTY( READ finPartie NOTIFY grillePleine)
    Q_PROPERTY(bool grillePleine READ readGrillePleine NOTIFY grillePleineSignal)

    Q_INVOKABLE void newGame(int nb_lig, int nb_col);
    Q_INVOKABLE void newCell();

    // Méthodes de déplacement
    Q_INVOKABLE void deplGauche();
    Q_INVOKABLE void deplDroite();
    Q_INVOKABLE void deplHaut();
    Q_INVOKABLE void deplBas();

    Q_INVOKABLE void finPartie();

    QList<QString> readStates();
    bool readGrillePleine();
    void verifieGrille();       // methode de recherche d'espace libre sur la grille
    //QString finPartie();



private:
    bool grillePleine;
    bool arretJeu();
    bool partieFinie;
    int nb_lig;
    int nb_col;
    int** tableau;          //matrice des valeurs des cellules

    void free();
    void alloc(int nb_lig , int nb_col);

    int score;      // score actuel de la partie
    int maxscore;   // score maximal sur toute la durée de jeu

signals:
    void statesChanged();
    void grillePleineSignal();

public slots:

};

#endif // GESTIONJEU_H
