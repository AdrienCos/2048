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
    explicit Cell(QObject *parent = 0 ,int value, string color , bool existe);

    // Gestion de la valeur de la cell
    int getValue();
    void setValue(int val);

    // Gestion de la couleur de la Cell
    Q_INVOKABLE string getColor();
    Q_INVOKABLE void setColor(string color);

    // Gestion de l'existence de la Cell
    Q_INVOKABLE bool getExiste();
    Q_INVOKABLE void setExiste(bool existe);

    // Remise a zero de la Cell
    Q_INVOKABLE void resetCell();


private:
    int value;
    string color;
    bool existe;
};


/*     Memos jeux de couleurs utilisés
#b48f8f : cellule vide
#fc9e9e : 2
#fb7b7b : 4
*/


#endif // CELL_H
