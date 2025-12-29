#ifndef PARADA_HPP
#define PARADA_HPP
#include "Demanda.hpp"

enum stop {
    embarque, 
    desembarque
};

struct parada {
  coord localizacao;
  stop tipo;
  int passageiro;
  
  // Construtors
  parada();
  parada(coord l, stop t, int p);
    
  bool isValida() const;
  
  //setters
  void setParada(coord l, stop t, int p);
  void setEmbarque(coord origem, int passageiroId);
  void setDesembarque(coord destino, int passageiroId);
};


#endif