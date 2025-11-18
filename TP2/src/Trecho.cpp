#include "Trecho.hpp"

double abs(double x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

double calcularDistancia(coord i, coord f){
    double dx = abs(f.x - i.x);
    double dy = abs(f.y - i.y);

    return sqrt(dx * dx + dy * dy);
}

trecho::trecho() {
    parada paradaVazia;
    this->inicio = paradaVazia;
    this->fim = paradaVazia;
    this->distancia = 0.0;
    this->do_trecho = deslocamento;
}

trecho::trecho(parada in, parada fi) {
    this->inicio = in;
    this->fim = fi;
    
    
    this->distancia = calcularDistancia(inicio.localizacao, fim.localizacao);
     
    //natureza
    if (inicio.tipo == embarque && fim.tipo == embarque) {
        do_trecho = coleta;
    }
    else if (inicio.tipo == desembarque && fim.tipo == desembarque) {
        do_trecho = entrega;
    }
    else {
        do_trecho = deslocamento;
    }
}

trecho::~trecho() {
    // Destrutor vazio - membros são POD e destruídos automaticamente
}

double trecho::getDistancia() const {
    return distancia;
}
