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
    Q_PROPERTY(QString resultat READ verifFinPartie NOTIFY finPartie)
    Q_PROPERTY(bool resume READ arretJeu NOTIFY arret)

    Q_INVOKABLE void newGame(int nb_lig, int nb_col);
    Q_INVOKABLE void newCell();
    Q_INVOKABLE void deplGauche();
    Q_INVOKABLE void deplDroite();
    Q_INVOKABLE void deplHaut();
    Q_INVOKABLE void deplBas();
    QList<QString> readStates();
    QString verifFinPartie();
    bool arretJeu();


private:
    string etat;
    int nb_lig;
    int nb_col;
    int** tableau;          //matrice des valeurs des cellules

    void free();
    void alloc(int nb_lig , int nb_col);

signals:
    void statesChanged();
    void finPartie();
    void arret();

public slots:

};

#endif // GESTIONJEU_H
