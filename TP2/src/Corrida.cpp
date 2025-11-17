#include "../include/Corrida.hpp"
#include <iostream>
#include <iomanip>

corrida::corrida() {
    tempo = 0.0;
    distancia = 0.0;
    eficiencia = 1.0; // eficiência inicial = 1 (máxima)
    
    // Vector historico é inicializado automaticamente
    // trecho de_deslocamento usa construtor padrão
}

corrida::~corrida() {
}

void corrida::addTrecho(trecho t, double velocidade) {
    historico.push_back(t);
    distancia += t.getDistancia();
    tempo += t.getDistancia() / velocidade; // calcula tempo = distância / velocidade
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
        int n = 1; // comeca em 1 pq defaulta 1 corrida
        
        corrida corridaTemp;
        vector<parada> paradaTemp;
        
        // Adiciona primeira demanda usando setter
        parada paradaAtual;
        paradaAtual.setEmbarque(escalonador[0].origem, escalonador[0].passageiro);
        paradaTemp.push_back(paradaAtual);
        paradaAtual.setDesembarque(escalonador[0].destino, escalonador[0].passageiro);
        paradaTemp.push_back(paradaAtual);
        double eficiencia = 1.0;
        // monta primeiro escopa de corrida
        while(true){
            if (n >= escalonador.get_size() || escalonador[n].tempoSolicitacao - escalonador[0].tempoSolicitacao >= renato.delta || n >= renato.eta){ // tempo limite
                break;  // viabilidade do delta é definido por tempoc1 - tempoc0 < delta, pq se o c0 é o tempo 0 
            }
            else{
                bool podeAdicionar = true;
                // Calcula eficiência da rota combinada
                double distanciaUtil = 0.0;
                double distanciaTotal = 0.0;
                
                for(int j = 0; j <= n; j++) {
                    distanciaUtil += calcularDistancia(escalonador[j].origem, escalonador[j].destino);
                }
                
                // Simula distância da rota: embarques → desembarques
                for(int j = 0; j < n; j++) {
                    distanciaTotal += calcularDistancia(escalonador[j].origem, escalonador[j+1].origem);
                }
                distanciaTotal += calcularDistancia(escalonador[n].origem, escalonador[0].destino);
                for(int j = 0; j < n; j++) {
                    distanciaTotal += calcularDistancia(escalonador[j].destino, escalonador[j+1].destino);
                }
                
                eficiencia = distanciaUtil / distanciaTotal;
                
                for(int j = 0; j < n; j++){
                    double tempAlfa = calcularDistancia(paradaTemp[2*j].localizacao, escalonador[n].origem);
                    double tempBeta = calcularDistancia(paradaTemp[2*j + 1].localizacao, escalonador[n].destino);
                    if (renato.alfa < tempAlfa || renato.beta < tempBeta || renato.lambda > eficiencia ){
                        podeAdicionar = false;
                        break;
                    }
                }
                if(podeAdicionar && n < escalonador.get_size()) {
                    // Adiciona nova demanda usando setter
                    paradaAtual.setEmbarque(escalonador[n].origem, escalonador[n].passageiro);
                    paradaTemp.push_back(paradaAtual);
                    paradaAtual.setDesembarque(escalonador[n].destino, escalonador[n].passageiro);
                    paradaTemp.push_back(paradaAtual);
                    n++;
                } else {
                    break;
                }
            }
        }
        for (int j = 0; j < paradaTemp.get_size()-3; j +=2){
            trecho t(paradaTemp[j], paradaTemp[j+2]);
            corridaTemp.addTrecho(t, renato.gama); // embarque
        }
        {
            trecho x(paradaTemp[paradaTemp.get_size()-2], paradaTemp[1]);
            corridaTemp.addTrecho(x, renato.gama); // embarque
        }
        
        for (int j = 1; j < paradaTemp.get_size()-2; j += 2){
            trecho t(paradaTemp[j], paradaTemp[j+2]);
            corridaTemp.addTrecho(t, renato.gama); // passa a velocidade do motorista
        }
        
        
        
        //verificar lambda, olhar qual menor trecho, maior trecho a diferenca resulta no lambdacs 
        ///monta os trechos
        corridas = escalonador[0].tempoSolicitacao + corridaTemp.getDuracao();
        lista.push_back(corridaTemp);
       
        for (int j = 0; j < n; j++){
            escalonador.pop();
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << corridas << " " << corridaTemp.getDistancia() << " " << (corridaTemp.getNumTrechos() + 1);
        
        // Imprime primeiro ponto do primeiro trecho
        if(corridaTemp.getNumTrechos() > 0) {
            trecho primeiroTrecho = corridaTemp.getTrechoByIndex(0);
            parada inicioTrecho = primeiroTrecho.getInicio();
            std::cout << " " << inicioTrecho.localizacao.x << " " << inicioTrecho.localizacao.y;
        }
        
        // Imprime pontos finais de cada trecho (sequência da rota)
        for(int j = 0; j < corridaTemp.getNumTrechos(); j++){
            trecho trechoAtual = corridaTemp.getTrechoByIndex(j);
            parada fimTrecho = trechoAtual.getFim();
            std::cout << " " << fimTrecho.localizacao.x << " " << fimTrecho.localizacao.y;
        }
        std::cout << '\n';
    }
}


















