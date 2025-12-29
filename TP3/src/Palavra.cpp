#include "Palavra.hpp"

// operadores de comparação por palavra
bool IndicePalavra::operator < (const IndicePalavra& other) const {
    return palavra < other.palavra;
}

bool IndicePalavra::operator > (const IndicePalavra& other) const {
    return palavra > other.palavra;
}

bool IndicePalavra::operator == (const IndicePalavra& other) const {
    return palavra == other.palavra;
}

// normaliza palavra para maiúscula
std::string GerenciadorPalavras::normalizar(const std::string& str) const {
    std::string resultado = str;
    for (size_t i = 0; i < resultado.length(); i++) {
        resultado[i] = std::toupper(static_cast<unsigned char>(resultado[i])); //coloca em maiscula e assinala tipo correto
    }
    return resultado;
}

// calcula interseção entre dois vetores
vector<int> GerenciadorPalavras::intersecao(const vector<int>& v1, const vector<int>& v2) const {
    vector<int> resultado;
    
    for (int i = 0; i < v1.get_size(); i++) {
        for (int j = 0; j < v2.get_size(); j++) {
            if (v1[i] == v2[j]) {
                resultado.push_back(v1[i]);
                break;
            }
        }
    }
    
    return resultado;
}

// processa logradouro e indexa suas palavras
void GerenciadorPalavras::processarLogradouro(const std::string& nomeLogradouro, int idLog) {
    std::istringstream iss(nomeLogradouro);
    std::string palavra;
    
    while (iss >> palavra) {
        inserirPalavra(palavra, idLog);
    }
}

// insere palavra associada a um id de logradouro
void GerenciadorPalavras::inserirPalavra(const std::string& p, int idLog) {
    std::string palavraNorm = normalizar(p);
    IndicePalavra temp(palavraNorm);
    
    IndicePalavra* existente = indicePalavras.searchPtr(temp);
    
    if (existente == nullptr) {
        temp.idsLogradouros.push_back(idLog);
        indicePalavras.insert(temp);
    } else {
        bool jaExiste = false;
        for (int i = 0; i < existente->idsLogradouros.get_size(); i++) {
            if (existente->idsLogradouros[i] == idLog) {
                jaExiste = true;
                break;
            }
        }
        
        if (!jaExiste) {
            existente->idsLogradouros.push_back(idLog);
        }
    }
}

// busca palavra e retorna ids dos logradouros
vector<int> GerenciadorPalavras::buscarPalavra(const std::string& p) const {
    std::string palavraNorm = normalizar(p);
    IndicePalavra temp(palavraNorm);
    vector<int> resultado;
    
    const IndicePalavra* encontrado = indicePalavras.searchPtr(temp);
    
    if (encontrado != nullptr) {
        for (int i = 0; i < encontrado->idsLogradouros.get_size(); i++) {
            resultado.push_back(encontrado->idsLogradouros[i]);
        }
    }
    
    return resultado;
}

// processa consulta e retorna interseção dos logradouros
vector<int> GerenciadorPalavras::processarConsulta(const std::string& consulta) const {
    vector<int> resultado;
    std::istringstream iss(consulta);
    std::string palavra;
    bool primeira = true;
    
    while (iss >> palavra) {
        vector<int> idsAtual = buscarPalavra(palavra);
        
        if (primeira) {
            resultado = idsAtual;
            primeira = false;
        } else {
            resultado = intersecao(resultado, idsAtual);
        }
        
        if (resultado.get_size() == 0) {
            break;
        }
    }
    
    return resultado;
}
