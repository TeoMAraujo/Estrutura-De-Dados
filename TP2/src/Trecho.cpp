#include "../include/Trecho.hpp"

int abs(int x) {
    if (x < 0) {
        x -= 2 * x;
    }
    return x;
}

int trecho::calcularDistancia(coord i, coord f){
    int temp;

    temp.y = abs(f.x - i.x);
    temp.y = abs(f.y - i.y);

    return sqrt(temp.x * temp.x + temp.y *temp.y);
}

trecho::trecho(parada in, parada fi) {
    this->inicio = in;
    this->fim = fi;
    
    
    this->distancia = calcularDistancia(inicio.localizacao, fim.localizacao);
    
    if (inicio.tipo == 0 && fim.tipo == 0) {
        do_trecho = coleta;
    }
    else if (inicio.tipo == 1 && fim.tipo == 1) {
        do_trecho = entrega;
    }
    else {
        do_trecho = deslocamento;
    }
}

void trecho::printinfo() {
    std::cout << inicio << fim;
}
