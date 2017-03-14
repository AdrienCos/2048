#include "cell.h"

// Constructeur
Cell::Cell(QObject *parent, int val, string color, bool existe) : QObject(parent)
{
    setValue(val);
    setColor(color);
    setExiste(existe);
}


// Gestion de la valeur de la Cell
int Cell::getValue()
{
    return this->value;
}
void Cell::setValue(int value)
{
    this->value = value;
}


// Gestion de la couleur de la Cell
string Cell::getColor()
{
    return this->color;
}
void Cell::setColor(string col)
{
    this->color = col;
}


// Gestion de l'existence de la Cell
bool Cell::getExiste()
{
    return this->existe;
}
void Cell::setExiste(bool exi)
{
    this->existe = exi;
}

// Remise a zero de la Cell
void Cell::resetCell()
{
    setValue(0);
    setColor("#b48f8f"); // couleur de base du damier
    setExiste(false);
}
