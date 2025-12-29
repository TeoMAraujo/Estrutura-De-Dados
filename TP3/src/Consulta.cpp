#include "Consulta.hpp"

// construtor
ProcessadorConsultas::ProcessadorConsultas(GerenciadorLogradouros* gl, GerenciadorPalavras* gp) {
    this->gerencLogradouros = gl;
    this->gerencPalavras = gp;
}

// calcula distância euclidiana
double ProcessadorConsultas::calcularDistancia(double x1, double y1, double x2, double y2) const {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

// merge auxiliar para merge sort
void ProcessadorConsultas::merge(vector<LogradouroDistancia>& lista, int esq, int meio, int dir) const {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    
    vector<LogradouroDistancia> L, R;
    
    for (int i = 0; i < n1; i++) {
        L.push_back(lista[esq + i]);
    }
    for (int j = 0; j < n2; j++) {
        R.push_back(lista[meio + 1 + j]);
    }
    
    int i = 0, j = 0, k = esq;
    
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            lista[k] = L[i];
            i++;
        } else {
            lista[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        lista[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        lista[k] = R[j];
        j++;
        k++;
    }
}

// merge sort recursivo
void ProcessadorConsultas::mergeSortRec(vector<LogradouroDistancia>& lista, int esq, int dir) const {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        
        mergeSortRec(lista, esq, meio);
        mergeSortRec(lista, meio + 1, dir);
        
        merge(lista, esq, meio, dir);
    }
}

// ordena por distância usando merge sort
void ProcessadorConsultas::ordenarPorDistancia(vector<LogradouroDistancia>& lista) const {
    if (lista.get_size() > 1) {
        mergeSortRec(lista, 0, lista.get_size() - 1);
    }
}

// processa consulta e retorna logradouros ordenados por distância
vector<LogradouroDistancia> ProcessadorConsultas::processarConsulta(const ConsultaData& consulta, int maxResultados) {
    vector<LogradouroDistancia> resultado;
    
    vector<int> idsLogradouros = gerencPalavras->processarConsulta(consulta.consulta);
    
    for (int i = 0; i < idsLogradouros.get_size(); i++) {
        int idLog = idsLogradouros[i];
        const Logradouro* log = gerencLogradouros->buscarPorId(idLog);
        
        if (log != nullptr) {
            double dist = calcularDistancia(
                consulta.longOrigem, consulta.latOrigem,
                log->getCentroX(), log->getCentroY()
            );
            
            LogradouroDistancia ld(idLog, log->getNomeCompleto(), dist);
            resultado.push_back(ld);
        }
    }
    
    ordenarPorDistancia(resultado);
    
    if (resultado.get_size() > maxResultados) {
        vector<LogradouroDistancia> resultadoLimitado;
        for (int i = 0; i < maxResultados; i++) {
            resultadoLimitado.push_back(resultado[i]);
        }
        return resultadoLimitado;
    }
    
    return resultado;
}
