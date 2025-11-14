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
calcularDistancia(coord i, coord f)
class trecho {
private:
    parada inicio, fim;
    int tempo;
    double distancia;
    natureza do_trecho;
    
public:
    trecho(parada in, parada fi);
    void printinfo();
};

#endif