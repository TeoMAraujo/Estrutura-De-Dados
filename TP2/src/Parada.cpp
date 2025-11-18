#include "Parada.hpp"

// Construtor padrão
parada::parada() : localizacao({0.0, 0.0}), tipo(embarque), passageiro(-1) {}

// Construtor com parâmetros
parada::parada(coord l, stop t, int p) {
    this->localizacao = l;
    this->tipo = t;
    this->passageiro = p;
}

// Método para verificar se a parada é válida
bool parada::isValida() const {
    return passageiro >= 0;
}

// Setter para definir todos os atributos da parada
void parada::setParada(coord l, stop t, int p) {
    this->localizacao = l;
    this->tipo = t;
    this->passageiro = p;
}

// Setter para parada de embarque
void parada::setEmbarque(coord origem, int passageiroId) {
    setParada(origem, embarque, passageiroId);
}

// Setter para parada de desembarque  
void parada::setDesembarque(coord destino, int passageiroId) {
    setParada(destino, desembarque, passageiroId);
}
