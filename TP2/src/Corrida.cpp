#include "Corrida.hpp"
#include <iostream>
#include <iomanip>

corrida::corrida() {
    tempo = 0.0;
    distancia = 0.0;
    eficiencia = 1.0; // eficiência inicial 
}

corrida::~corrida() {
}

void corrida::addTrecho(trecho t, double velocidade) {
    historico.push_back(t);
    distancia += t.getDistancia();
    tempo += t.getDistancia() / velocidade; // t = d/v
}

double corrida::getDuracao() const {
    return tempo;
}

double corrida::getDistancia() const {
    return distancia;
}

double corrida::getEficiencia() const {
    return eficiencia;
}

int corrida::getNumTrechos() const {
    return historico.get_size();
}

trecho corrida::getTrechoByIndex(int index) const {
    if (index < 0 || index >= historico.get_size()) {
        throw std::out_of_range("Invalid trecho index");
    }
    return historico[index];
}
listacorridas::listacorridas(motorista m) {
    renato = m;
    corridas = 0.0;
}

listacorridas::~listacorridas() {
}

void listacorridas::addCorrida(corrida c) {
    lista.push_back(c);
}

void listacorridas::addDemanda(demanda d) {
    escalonador.push(d);
}

corrida listacorridas::getCorrida(int index) const {
    return lista[index];
}
// fazer uma função que cria todas as corridas
void listacorridas::criaCorridas(){
    while(escalonador.get_size() > 0){
        corrida corridaTemp;
        vector<parada> paradaTemp;
        vector<demanda> demandasDaCorrida; // Armazena demandas que vão nesta corrida
        
        // Adiciona primeira demanda (remove do heap)
        demanda primeira = escalonador[0];
        escalonador.pop();
        demandasDaCorrida.push_back(primeira);
        
    
        while(demandasDaCorrida.get_size() < renato.eta && escalonador.get_size() > 0){
            demanda candidata = escalonador[0]; // Próxima demanda em ordem de tempo
            
            if(candidata.tempoSolicitacao - primeira.tempoSolicitacao >= renato.delta){
                break;
            }
            
            bool podeAdicionar = true;
            

            double distanciaUtil = 0.0;
            double distanciaTotal = 0.0;
            
            for(int j = 0; j < demandasDaCorrida.get_size(); j++) {
                distanciaUtil += calcularDistancia(demandasDaCorrida[j].origem, demandasDaCorrida[j].destino);
            }
            distanciaUtil += calcularDistancia(candidata.origem, candidata.destino);
            
            for(int j = 0; j < demandasDaCorrida.get_size() - 1; j++) {
                distanciaTotal += calcularDistancia(demandasDaCorrida[j].origem, demandasDaCorrida[j+1].origem);
            }
            distanciaTotal += calcularDistancia(demandasDaCorrida[demandasDaCorrida.get_size()-1].origem, candidata.origem);
            distanciaTotal += calcularDistancia(candidata.origem, demandasDaCorrida[0].destino);
            for(int j = 0; j < demandasDaCorrida.get_size() - 1; j++) {
                distanciaTotal += calcularDistancia(demandasDaCorrida[j].destino, demandasDaCorrida[j+1].destino);
            }
            distanciaTotal += calcularDistancia(demandasDaCorrida[demandasDaCorrida.get_size()-1].destino, candidata.destino);
            
            double eficiencia = (distanciaTotal > 0) ? (distanciaUtil / distanciaTotal) : 1.0;
            
            // Verifica condições alfa, beta e lambda
            for(int j = 0; j < demandasDaCorrida.get_size(); j++){
                double tempAlfa = calcularDistancia(demandasDaCorrida[j].origem, candidata.origem);
                double tempBeta = calcularDistancia(demandasDaCorrida[j].destino, candidata.destino);
                if (renato.alfa < tempAlfa || renato.beta < tempBeta || renato.lambda > eficiencia){
                    podeAdicionar = false;
                    break;
                }
            }
            
            if(podeAdicionar) {
                demandasDaCorrida.push_back(candidata);
                escalonador.pop();
            } else {
                break; 
            }
        }
        
        
        parada paradaAtual;
        for(int i = 0; i < demandasDaCorrida.get_size(); i++) {
            paradaAtual.setEmbarque(demandasDaCorrida[i].origem, demandasDaCorrida[i].passageiro);
            paradaTemp.push_back(paradaAtual);
            paradaAtual.setDesembarque(demandasDaCorrida[i].destino, demandasDaCorrida[i].passageiro);
            paradaTemp.push_back(paradaAtual);
        }
        
        for (int j = 0; j < paradaTemp.get_size()-3; j +=2){
            trecho t(paradaTemp[j], paradaTemp[j+2]);
            corridaTemp.addTrecho(t, renato.gama);
        }
        {
            trecho x(paradaTemp[paradaTemp.get_size()-2], paradaTemp[1]);
            corridaTemp.addTrecho(x, renato.gama);
        }
        
        for (int j = 1; j < paradaTemp.get_size()-2; j += 2){
            trecho t(paradaTemp[j], paradaTemp[j+2]);
            corridaTemp.addTrecho(t, renato.gama);
        }
        
        corridas = primeira.tempoSolicitacao + corridaTemp.getDuracao();
        lista.push_back(corridaTemp);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << corridas << " " << corridaTemp.getDistancia() << " " << (corridaTemp.getNumTrechos() + 1);
        
        if(corridaTemp.getNumTrechos() > 0) {
            trecho primeiroTrecho = corridaTemp.getTrechoByIndex(0);
            parada inicioTrecho = primeiroTrecho.getInicio();
            std::cout << " " << inicioTrecho.localizacao.x << " " << inicioTrecho.localizacao.y;
        }
        
        for(int j = 0; j < corridaTemp.getNumTrechos(); j++){
            trecho trechoAtual = corridaTemp.getTrechoByIndex(j);
            parada fimTrecho = trechoAtual.getFim();
            std::cout << " " << fimTrecho.localizacao.x << " " << fimTrecho.localizacao.y;
        }
        std::cout << '\n';
    }
}


















