#ifndef GESTIONJEU_H
#define GESTIONJEU_H

#include <QObject>
#include "cell.h"

class GestionJeu : public QObject
{
    Q_OBJECT
public:
    explicit GestionJeu(QObject *parent = 0);
    Q_INVOKABLE void NewGame(int nb_lig, int nb_col);

private:
    int nb_lig;
    int nb_col;
    Cell** tableau[];

    void Free();
    void Alloc();

signals:

public slots:
};

#endif // GESTIONJEU_H
