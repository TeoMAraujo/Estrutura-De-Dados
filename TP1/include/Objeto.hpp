#ifndef OBJETO_HPP
#define OBJETO_HPP

#include "vector.hpp"

class objeto {
private:
    int id;
    int tempo;
    double x, y;
    double largura;

public:
    objeto();
    objeto(const int &id, const int &tempo, const double &x, const double &y,
         const double &largura); // all arguments are in & to use less memory
  
    int getId() const; 
    int getTempo() const;  
    double getX() const;
    double getY() const;
    double getLargura() const;

    void setX(double X);
    void setY(double Y);
    void setLargura(double L);
};

#endif // OBJETO_HPP
