#include "Objeto.hpp"

// Implementação dos métodos da classe objeto

objeto::objeto(const int &id, const float &x, const float &x,const float &largura) {
  this->id = id;
  this->x = x, this->y = y;
  this->largura = largura
}

float objeto::getX() const { return x; }

float objeto::getY() const { return y; }

float objeto::getLargura() const { return largura; }
// tem que ter validação de colisão
float objeto::getId() const { return id; }
