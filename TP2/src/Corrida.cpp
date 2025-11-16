#include "../include/Corrida.hpp"

corrida::corrida() {
    duracao = 0.0;
    distancia = 0.0;
    eficiencia = 0.0;
}

corrida::~corrida() {
}

void corrida::addTrecho(trecho t, int velocidade) {
    historico.push_back(t);
    distancia += t.getDistancia();   
    tempo += corridaTemp.distancia /velocidade
    
}

int corrida::getDuracao() const {
    return duracao;
}

int corrida::getDistancia() const {
    return distancia;
}

int corrida::getEficiencia() const {
    return eficiencia;
}
listacorridas::listacorridas(motorista m) {
    renato = m;
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
    while(escalonador > 0){
        int n = 1; // comeca em 1 pq defaulta 1 corrida
        
        corrida corridaTemp;
        vector<parada> paradaTemp;
        
        parada temp;
        
        temp(escalonador[0].origem, embarque, escalonador[0].passageiro);
        paradaTemp.push_back(temp);
        temp(escalonador[0].destino, desembarque, escalonador[0].passageiro);
        paradaTemp.push_back(temp);
        double eficiencia = 1
        int i = 1
        // monta primeiro escopa de corrida
        while(true){
            if (n >= escalonador.get_size() || escalonador[n].tempoSolicitacao - escalonador[0].tempoSolicitacao >= renato.delta || n + 1 == renato.eta){ // tempo limite
                break;  // viabilidade do delta é definido por tempoc1 - tempoc0 < delta, pq se o c0 é o tempo 0 
            }
            else{
                for(int j = 0; j < n; j++){
                    double tempAlfa = calcularDistancia(paradaTemp[2*j].localizacao, escalonador[n].origem);
                    double tempBeta = calcularDistancia(paradaTemp[2*j + 1].localizacao, escalonador[n].destino);
                    eficiencia = calcularDistancia(escalonador[0].origem, escalonador[0].destino) / calcularDistancia(escalonador[n].origem, escalonador[n].destino);
                    if (renato.alfa < tempAlfa || renato.beta < tempBeta || renato.lambda > eficiencia ){
                        i = 0;
                        break;
                    }
                if(i == 1)
                    temp(escalonador[n].origem, embarque, escalonador[n].passageiro);
                    paradaTemp.push_back(temp);
                    temp(escalonador[n].destino, desembarque, escalonador[n].passageiro);
                    paradaTemp.push_back(temp);
                    n++;
                }
                else {
                    i = 1;
                    break;
                }
            }
        }
        for (int j = 0; j < paradaTemp.getsize()-1; j++){
            corridaTemp.addTrecho(paradaTemp[j], paradaTemp[j+1], renato.gama)
        }
        for (int j = 0; j =< n; j++){
            escalonador.pop();
            escalonador.pop();
        }
        //verificar lambda, olhar qual menor trecho, maior trecho a diferenca resulta no lambdacs 
        ///monta os trechos
        corridas += corridaTemp.getTempo();
        lista.push_back(criaCorrida())
        
        std::cout << corridas << lista[i].getDistancia();
        for(int j = 0; j < paradaTemp.getsize(); j++){
            std::cout << ParadaTemp.localizacao.x << ParadaTemp.localizacao.y;  
        }
        std::cout << '\n';
    }
}