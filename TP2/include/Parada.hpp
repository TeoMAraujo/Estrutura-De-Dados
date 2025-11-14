#ifndef PARADA_HPP
#define PARADA_HPP
#include "demanda.hpp"

enum stop {
    embarque, 
    desembarque
};

struct parada {
  coord localizacao;
  stop tipo;
  int passageiro;
  parada(localizacao l, stop t, int p);
};


#endif