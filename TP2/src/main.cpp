
#include <iostream>
#include "Corrida.hpp"

int main {
    motorista tempmotor;
    
    std::cin >> tempmotor.eta;  
    std::cin >> tempmotor.gama; 
    std::cin >> tempmotor.delta;  
    std::cin >> tempmotor.alfa;
    std::cin >> tempmotor.beta;  
    std::cin >> tempmotor.lambda;
    std::cin >> tempmotor.numdemandas; 

    listacorridas percursos(tempmotor); //inicia os percursos inicializando o motorista

    for (int i = 0; i < tempmotor.numdemandas; i++){
        demanda p;
        cin >> p.passageiro >> p.tempoSolicitacao >> p.origem.x >> p.origem.y >> p.destino.x >> p.destino.y;
        percursos.addDemanda(p);
    }

 
//tempo de conclusão da corrida
// distancia total percorrida
// numero de paradas
// sequencia de coordenanadas associadas   
    
    return 0;
}