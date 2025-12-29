/*
O TAD Logradouro vai conter as informações para os logradouros, em particular as coor-
denadas médias dos mesmos. Ele também fará a associação entre identificadores e nomes
dos logradouros.
*/
#ifndef LOGRADOURO_HPP
#define LOGRADOURO_HPP

#include <string>
#include <cmath>
#include "Endereco.hpp"
#include "AVL.hpp"
#include "vector.hpp"

class Logradouro {
private:
    int idLog;
    int quantEnderecos;
    vector<Endereco> enderecos;
    double centroGravidadeX;
    double centroGravidadeY;
    std::string nomeCompleto;
    
public:
    // construtores
    Logradouro();
    Logradouro(int id);
    Logradouro(const Endereco& end);

    // métodos
    void adicionarEndereco(const Endereco& end);
    
    // getters
    int getIdLog() const { return idLog; }
    int getQuantEnderecos() const { return quantEnderecos; }
    double getCentroX() const { return centroGravidadeX; }
    double getCentroY() const { return centroGravidadeY; }
    std::string getNomeCompleto() const { return nomeCompleto; }
    const vector<Endereco>& getEnderecos() const { return enderecos; }

    // operadores
    bool operator < (const Logradouro& other) const;
    bool operator > (const Logradouro& other) const;
    bool operator == (const Logradouro& other) const;
};

class GerenciadorLogradouros {
private:
    AVL<Logradouro> arvoreLogradouros;

public:
    GerenciadorLogradouros() {}
    
    // métodos
    void inserirEndereco(const Endereco& end);
    Logradouro* buscarPorId(int idLog);
    const Logradouro* buscarPorId(int idLog) const;
    static double calcularDistancia(double x1, double y1, double x2, double y2);
};

#endif
