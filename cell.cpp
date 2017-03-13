#include "cell.h"

// Constructeur
Cell::Cell(QObject *parent) : QObject(parent)
{

}

// Gestion de la couleur de la Cell
string Cell::getColor(){
    return this->color;
}
void Cell::setColor(string col)
{
    this->color = col;
}

// Gestion de l'existence de la Cell
bool Cell::getExiste()
{
    return this->existe
}
void Cell::setExiste(bool exi)
{
    this->existe = exi;
}
