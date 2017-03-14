#ifndef GESTIONJEU_H
#define GESTIONJEU_H

#include <QObject>
#include "cell.h"

class GestionJeu : public QObject
{
    Q_OBJECT
public:
    explicit GestionJeu(QObject *parent = 0);

    Q_INVOKABLE void newGame(int nb_lig, int nb_col);
    Q_INVOKABLE void newCell();

private:
    int nb_lig;
    int nb_col;
    Cell** tableau;

    void free();
    void alloc(int nb_lig , int nb_col);

signals:

public slots:
};

#endif // GESTIONJEU_H
