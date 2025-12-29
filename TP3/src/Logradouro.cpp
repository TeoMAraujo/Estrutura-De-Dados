#include "Logradouro.hpp"

// construtor padrão
Logradouro::Logradouro() {
    this->idLog = 0;
    this->quantEnderecos = 0;
    this->centroGravidadeX = 0.0;
    this->centroGravidadeY = 0.0;
    this->nomeCompleto = "";
}

// construtor com id para busca
Logradouro::Logradouro(int id) {
    this->idLog = id;
    this->quantEnderecos = 0;
    this->centroGravidadeX = 0.0;
    this->centroGravidadeY = 0.0;
    this->nomeCompleto = "";
}

// construtor com primeiro endereço
Logradouro::Logradouro(const Endereco& end) {
    this->idLog = end.IdLog;
    this->quantEnderecos = 1;
    this->centroGravidadeX = end.Long;
    this->centroGravidadeY = end.Lat;
    this->nomeCompleto = end.Log;
    this->enderecos.push_back(end);
}

// adiciona endereço e recalcula centro de gravidade
void Logradouro::adicionarEndereco(const Endereco& end) {
    double somaX = centroGravidadeX * quantEnderecos + end.Long;
    double somaY = centroGravidadeY * quantEnderecos + end.Lat;
    
    quantEnderecos++;
    centroGravidadeX = somaX / quantEnderecos;
    centroGravidadeY = somaY / quantEnderecos;
    
    enderecos.push_back(end);
}

// operadores de comparação por id
bool Logradouro::operator < (const Logradouro& other) const {
    return idLog < other.idLog;
}

bool Logradouro::operator > (const Logradouro& other) const {
    return idLog > other.idLog;
}

bool Logradouro::operator == (const Logradouro& other) const {
    return idLog == other.idLog;
}

// insere ou atualiza logradouro com novo endereço
void GerenciadorLogradouros::inserirEndereco(const Endereco& end) {
    Logradouro temp(end);
    
    Logradouro* existente = arvoreLogradouros.searchPtr(temp);
    
    if (existente == nullptr) {
        arvoreLogradouros.insert(temp);
    } else {
        existente->adicionarEndereco(end);
    }
}

// busca logradouro por id
Logradouro* GerenciadorLogradouros::buscarPorId(int idLog) {
    Logradouro temp(idLog);
    return arvoreLogradouros.searchPtr(temp);
}

const Logradouro* GerenciadorLogradouros::buscarPorId(int idLog) const {
    Logradouro temp(idLog);
    return arvoreLogradouros.searchPtr(temp);
}

// calcula distância euclidiana
double GerenciadorLogradouros::calcularDistancia(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}
