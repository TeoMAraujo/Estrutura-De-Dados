#include "Objeto.hpp"

objeto::objeto(const int &id, const int &tempo, const float &x, const float &y, const float &largura) {
    this->id = id;
    this->tempo = tempo;
    this->x = x;
    this->y = y;
    this->largura = largura;
}

int objeto::getId() const { return id; }

int objeto::getTempo() const { return tempo; }

float objeto::getX() const { return x; }

float objeto::getY() const { return y; }

float objeto::getLargura() const { return largura; }

void objeto::setX(float X) { x = X; }

void objeto::setY(float Y) { y = Y; }

void objeto::setLargura(float L) { largura = L; }