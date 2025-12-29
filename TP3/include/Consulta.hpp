/*
O TAD consulta contém as informações necessárias para satisfazer uma consulta. Ele
vai obter informações dos TADs Logradouro e Palavra para poder gerar a resposta da
consulta.
*/
#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include <string>
#include <sstream>
#include <cmath>
#include "vector.hpp"
#include "Endereco.hpp"
#include "Logradouro.hpp"
#include "Palavra.hpp"

struct LogradouroDistancia {
    int idLog;
    std::string nomeCompleto;
    double distancia;
    
    LogradouroDistancia() {
        this->idLog = 0;
        this->nomeCompleto = "";
        this->distancia = 0.0;
    }
    
    LogradouroDistancia(int id, const std::string& nome, double dist) {
        this->idLog = id;
        this->nomeCompleto = nome;
        this->distancia = dist;
    }
    
    bool operator < (const LogradouroDistancia& other) const {
        return distancia < other.distancia;
    }
};

class ProcessadorConsultas {
private:
    GerenciadorLogradouros* gerencLogradouros;
    GerenciadorPalavras* gerencPalavras;
    
    double calcularDistancia(double x1, double y1, double x2, double y2) const;
    void merge(vector<LogradouroDistancia>& lista, int esq, int meio, int dir) const;
    void mergeSortRec(vector<LogradouroDistancia>& lista, int esq, int dir) const;
    void ordenarPorDistancia(vector<LogradouroDistancia>& lista) const;
    
public:
    ProcessadorConsultas(GerenciadorLogradouros* gl, GerenciadorPalavras* gp);
    vector<LogradouroDistancia> processarConsulta(const ConsultaData& consulta, int maxResultados);
};

#endif