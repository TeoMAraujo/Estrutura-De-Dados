#ifndef CORRIDA_HPP
#define CORRIDA_HPP

#include "vector.hpp"
#include "minheap.hpp"
#include "Trecho.hpp"
#include "Demanda.hpp"
#include "Parada.hpp"

struct motorista{
    int eta; //capacidade do veículo
    double gama; // velocidade dos veiculos
    double delta; // intervalo de tempo
    double alfa; //distancia max entre origens
    double beta; // dist max entre destinos
    double lambda; // eficiencia minima da corrida
    int numdemandas; // num de demandas a serem simuladas
};
class corrida {
    private:
        vector<trecho> historico; // msm numero de trechos de coleta e entrega numero total menos 
        trecho de_deslocamento; // so 1 trecho de deslocamento 1
        double tempo, distancia, eficiencia;
    public:
        corrida();
        ~corrida();
        
        // Add methods as needed
        void addTrecho(trecho t, double velocidade);
        int getTrecho(int i) const;
        
        double getDuracao() const;
        double getDistancia() const;
        double getEficiencia() const;
        
        // Métodos para acessar o histórico
        int getNumTrechos() const;
        trecho getTrechoByIndex(int index) const;
};

class listacorridas{
    private:
        minHeap<demanda> escalonador;
        vector<corrida> lista;
        motorista renato; //nome do motorista hipotetico
        double corridas;
    public:
        listacorridas(motorista m);
        ~listacorridas();
        
        // Add methods as needed
        void addCorrida(corrida c);
        void addDemanda(demanda d);
        corrida getCorrida(int index) const;
        void criaCorridas();
};
#endif
