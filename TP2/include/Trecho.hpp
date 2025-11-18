#ifndef TRECHO_HPP
#define TRECHO_HPP

#include "Parada.hpp"
#include <cmath>
#include <iostream>

enum natureza {
  coleta, // (caracterizado por duas paradas de embarque)
  entrega, // duas paradas de desembarque)
  deslocamento // deslocamento (caracterizado por um embarque e um desembarque)
};

int abs(int x);
double calcularDistancia(coord i, coord f);

class trecho {
private:
    parada inicio, fim;
    double distancia;
    natureza do_trecho;
    
public:
    //constructor
    trecho(); // Construtor padrão
    trecho(parada in, parada fi);
    ~trecho(); // Destrutor
    
    // getters 
    parada getInicio() const { return inicio; }
    parada getFim() const { return fim; }
    double getDistancia() const;
    
};

#endif