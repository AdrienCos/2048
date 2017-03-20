#ifndef GESTIONJEU_H
#define GESTIONJEU_H

#include <QObject>
#include <time.h>

class GestionJeu : public QObject
{
    Q_OBJECT
public:
    explicit GestionJeu(QObject *parent = 0);

    Q_PROPERTY(QList<QString> states READ readStates NOTIFY statesChanged)

    Q_INVOKABLE void newGame(int nb_lig, int nb_col);
    Q_INVOKABLE void newCell();
    Q_INVOKABLE void deplGauche();
    Q_INVOKABLE void deplDroite();
    Q_INVOKABLE void deplHaut();
    QList<QString> readStates();


private:
    int nb_lig;
    int nb_col;
    int** tableau;          //matrice des valeurs des cellules

    void free();
    void alloc(int nb_lig , int nb_col);

signals:
    void statesChanged();

public slots:

};

#endif // GESTIONJEU_H
