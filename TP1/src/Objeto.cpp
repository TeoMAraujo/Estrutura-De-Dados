#include "Objeto.hpp"

// Implementação dos métodos da classe objeto

objeto::objeto(const int &id, const float &x, const float &y,const float &largura) {
  this->id = id;
  this->x = x, this->y = y;
  this->largura = largura
}

int objeto::getId() const { return id; }

float objeto::getX() const { return x; }

float objeto::getY() const { return y; }

float objeto::getLargura() const { return largura; }

void objeto::setX(int X) { x = X; }

void objeto::setY(int Y) { y = Y; }

void objeto::setLargura(int l) { Largura = L; }
// tem que ter validação de colisão