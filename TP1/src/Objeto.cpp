#include "Objeto.hpp"

objeto::objeto() {
    this->id = 0;
    this->tempo = 0;
    this->x = 0.0;
    this->y = 0.0;
    this->largura = 0;
}

objeto::objeto(const int &id, const int &tempo, const double &x, const double &y, const double &largura) {
    this->id = id;
    this->tempo = tempo;
    this->x = x;
    this->y = y;
    this->largura = largura;
}

int objeto::getId() const { return id; }

int objeto::getTempo() const { return tempo; }

double objeto::getX() const { return x; }

double objeto::getY() const { return y; }

double objeto::getLargura() const { return largura; }

void objeto::setX(double X) { x = X; }

void objeto::setY(double Y) { y = Y; }

void objeto::setLargura(double L) { largura = L; }