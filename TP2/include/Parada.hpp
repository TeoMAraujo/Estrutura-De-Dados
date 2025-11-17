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
  parada() : localizacao({0.0, 0.0}), tipo(embarque), passageiro(-1) {}
  
  // Construtor com parâmetros
  parada(coord l, stop t, int p){
    this->localizacao = l;
    this->tipo = t;
    this->passageiro = p;
  }
  
  // Método para verificar se a parada é válida
  bool isValida() const {
    return passageiro >= 0;
  }
  
  // Setter para definir todos os atributos da parada
  void setParada(coord l, stop t, int p) {
    this->localizacao = l;
    this->tipo = t;
    this->passageiro = p;
  }
  
  // Setter para parada de embarque
  void setEmbarque(coord origem, int passageiroId) {
    setParada(origem, embarque, passageiroId);
  }
  
  // Setter para parada de desembarque  
  void setDesembarque(coord destino, int passageiroId) {
    setParada(destino, desembarque, passageiroId);
  }
};


#endif