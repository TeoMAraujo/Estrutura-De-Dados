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
    trecho(); // Construtor padrão
    trecho(parada in, parada fi);
    void printinfo();
    double getDistancia() const;
    
    // Getters públicos para acessar as paradas
    parada getInicio() const { return inicio; }
    parada getFim() const { return fim; }
};

#endif