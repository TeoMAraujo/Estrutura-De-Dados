/*
O TAD Endereço basicamente armazena os dados de entrada. Uma função que nos parece
pertencer a esse TAD é o cálculo das coordenadas médias, necessário para construir o TAD
Logradouro.
*/
#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include <string>

struct Endereco {
    std::string IdEnd;
    int IdLog;
    std::string TipoLog;
    std::string Log; 
    int Num;
    std::string Bairro;
    std::string Regiao;
    std::string CEP;
    double Lat;
    double Long;
    
    Endereco() {
        this->IdEnd = "";
        this->IdLog = 0;
        this->TipoLog = "";
        this->Log = "";
        this->Num = 0;
        this->Bairro = "";
        this->Regiao = "";
        this->CEP = "";
        this->Lat = 0.0;
        this->Long = 0.0;
    }
};

struct ConsultaData {
    int idConsulta;
    std::string consulta;
    double latOrigem;
    double longOrigem;
    
    ConsultaData() {
        this->idConsulta = 0;
        this->consulta = "";
        this->latOrigem = 0.0;
        this->longOrigem = 0.0;
    }
};

// funções de leitura
Endereco lerEndereco();
ConsultaData lerConsulta();

#endif



