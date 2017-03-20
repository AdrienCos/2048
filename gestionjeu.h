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

    Q_INVOKABLE void newGame(int nb_lig, int nb_col);

    // Méthodes de déplacement
    Q_INVOKABLE void deplGauche();
    Q_INVOKABLE void deplDroite();
    Q_INVOKABLE void deplHaut();
    Q_INVOKABLE void deplBas();

    // Methode de transmission des infos au QML
    QList<QString> readStates();


private:

    int nb_lig;
    int nb_col;
    int** tableau;          //matrice des valeurs des cellules

    void free();
    void alloc(int nb_lig , int nb_col);
    void newCell();

    int score;      // score actuel de la partie
    int maxscore;   // score maximal sur toute la durée de jeu

signals:
    void statesChanged();

public slots:

};

#endif // GESTIONJEU_H
