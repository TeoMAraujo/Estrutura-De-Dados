#include "../include/Corrida.hpp"

corrida::corrida() {
    duracao = 0;
    distancia = 0;
    eficiencia = 0;
}

corrida::~corrida() {
}

void corrida::addTrecho(trecho t) {
    historico.push_back(t);
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
void listacorridas::criaCorrida(){
    int n = 1; // comeca em 1 pq defaulta 1 corrida
    
    corrida corridaTemp;
    vector<parada> paradaTemp;
    
    parada temp;
    
    temp(escalonador[0].origem, 0, escalonador[0].passageiro);
    paradaTemp.push_back(temp);
    temp(escalonador[0].destino, 1, escalonador[0].passageiro);
    paradaTemp.push_back(temp);
    
    // monta primeiro escopa de corrida
    while(true){
        if (escalonador[n].tempoSolicitacao - escalonador[0].tempoSolicitacao >= renato.delta || n + 1 == renato.eta){ // tempo limite
            break;  // viabilidade do delta é defenido por tempoc1 - tempoc0 < delta, pq se o c0 é o tempo 0 
        }
        else{
            for(int j = 0; j == n; j++){
                    int tempAlfa =  calcularDistancia(paradaTemp[2*j].localizacao, escalonador[n].origem)
                    int tempBeta =  calcularDistancia(paradaTemp[2*j + 1], escalonador[n].destino)
                    if (renato.alfa > tempAlfa && renato.beta > tempBeta){
                            eficiencia antes de add
                            temp(escalonador[n].origem, 0, escalonador[n].passageiro);
                            paradaTemp.push_back(temp);
                            temp(escalonador[n].destino, 1, escalonador[n].passageiro);
                            paradaTemp.push_back(temp);
                            n++
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    //verificar lambda, olhar qual menor trecho, maior trecho a diferenca resulta no lambdacs 
    ///monta os trechos

    
    // cria corrida e escolona

    return // tempo de conclusão
           // distancia total percorrida
           // numero de paradas
           // sequencia coordenadas
    
   
   
   
           // fazer n corridas dentro do delta apt de corrida0
    // C = c0
    // r = Origem_c0 e Destino_c0
    // atualizar corrida r associada ao conjunto C, sequencia de pontos de parada pelo veiculo na coleta e entrega
    // na versão basica as coletas e entregas são na msm ordem. que também é ordem de demandas
    // verifique se r satisfaz lambda, se n, remova ci de r
    // adicionar r ao vetor
    // escalone até o primeiro ponto de coleta da corrida r


}