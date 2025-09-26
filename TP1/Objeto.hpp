#ifndef OBJETO_HPP
#define OBJETO_HPP

#include "vector.hpp"

class objeto {
private:
  int id;
  int tempo;
  float x, y;
  float largura;

public:
  objeto(const float &x, const float &y,
         const float &largura); // all arguments are in & to use less memory
  float getX() const;
  float getY() const;
  float getLargura() const;
};

#endif // OBJETO_HPP
