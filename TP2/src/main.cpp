
#include <iostream>
#include "Corrida.hpp"

int main() {
    motorista tempmotor;
    
    std::cin >> tempmotor.eta;      // capacidade do veículo
    std::cin >> tempmotor.gama;     // velocidade do veículo
    std::cin >> tempmotor.delta;    // intervalo temporal máximo entre corridas combinadas
    std::cin >> tempmotor.alfa;     // distância máxima entre origens de corridas combinadas
    std::cin >> tempmotor.beta;     // distância máxima entre destinos de corridas combinadas
    std::cin >> tempmotor.lambda;   // eficiência mínima da corrida combinada
    std::cin >> tempmotor.numdemandas; // número de demandas a serem simuladas 

    // ROBUSTEZ: Validação dos parâmetros
    if (tempmotor.eta <= 0 || tempmotor.gama <= 0.0 || tempmotor.delta < 0.0 || 
        tempmotor.alfa < 0.0 || tempmotor.beta < 0.0 || 
        tempmotor.lambda < 0.0 || 
        tempmotor.numdemandas < 0) {
        return 1; // Parâmetros inválidos
    }

    listacorridas percursos(tempmotor); //inicia os percursos inicializando o motorista

    for (int i = 0; i < tempmotor.numdemandas; i++){
        demanda p;
        std::cin >> p.passageiro >> p.tempoSolicitacao >> p.origem.x >> p.origem.y >> p.destino.x >> p.destino.y;
        
        // ROBUSTEZ: Validar tempo da demanda
        if (p.tempoSolicitacao < 0.0) {
            return 1; // Tempo inválido
        }
        
        percursos.addDemanda(p);
    }

    if (tempmotor.numdemandas > 0) {
        percursos.criaCorridas();
    }
 
//tempo de conclusão da corrida
// distancia total percorrida
// numero de paradas
// sequencia de coordenanadas associadas   
    
    return 0;
}