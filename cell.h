#ifndef CELL_H
#define CELL_H

#include <QObject>
using namespace std
#include <string>

class Cell : public QObject
{
    Q_OBJECT

public:
    // Constructeurs
    explicit Cell(QObject *parent = 0);
    explicit Cell(QObject *parent = 0 , string color , bool existe);

    // Gestion de la couleur de la Cell
    Q_INVOKABLE string getColor();
    Q_INVOKABLE void setColor(string color);

    // Gestion de l'existence de la Cell
    Q_INVOKABLE bool getExiste();
    Q_INVOKABLE void setExiste(bool existe);

private:
    string color;
    bool existe;
};

#endif // CELL_H
