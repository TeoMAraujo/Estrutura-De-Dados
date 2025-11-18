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
  
  // Construtor padrão
  parada();
  
  // Construtor com parâmetros
  parada(coord l, stop t, int p);
  
  // Método para verificar se a parada é válida
  bool isValida() const;
  
  // Setter para definir todos os atributos da parada
  void setParada(coord l, stop t, int p);
  
  // Setter para parada de embarque
  void setEmbarque(coord origem, int passageiroId);
  
  // Setter para parada de desembarque  
  void setDesembarque(coord destino, int passageiroId);
};


#endif