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
     objeto() : id(0), tempo(0), x(0.0f), y(0.0f), largura(0.0f) {}
    objeto(const int &id, const int &tempo, const float &x, const float &y,
         const float &largura); // all arguments are in & to use less memory
  
    int getId() const; 
    int getTempo() const;  
    float getX() const;
    float getY() const;
    float getLargura() const;

    void setX(float X);
    void setY(float Y);
    void setLargura(float L);
};

#endif // OBJETO_HPP
