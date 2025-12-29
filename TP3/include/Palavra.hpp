/*
O TAD Palavra é o mais fundamental para as consultas. Entre outras funções, ele vai
permitir retornar uma lista dos logradouros onde uma palavra ocorre. Há diversos compro-
missos e desafios na sua implementação, desde a busca eficiente por uma palavra quanto
a manipulação das listas de logradouros. Pelo menos uma versão do índice de palavras
deve ser implementado como uma árvore de pesquisa balanceada.
*/
#ifndef PALAVRA_HPP
#define PALAVRA_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "vector.hpp"
#include "AVL.hpp"

struct IndicePalavra {
    std::string palavra;
    vector<int> idsLogradouros;
    
    IndicePalavra() {
        this->palavra = "";
    }
    
    IndicePalavra(const std::string& p) {
        this->palavra = p;
    }
    
    // operadores
    bool operator < (const IndicePalavra& other) const;
    bool operator > (const IndicePalavra& other) const;
    bool operator == (const IndicePalavra& other) const;
};

class GerenciadorPalavras {
private:
    AVL<IndicePalavra> indicePalavras;
    
    std::string normalizar(const std::string& str) const;
    vector<int> intersecao(const vector<int>& v1, const vector<int>& v2) const;
    
public:
    GerenciadorPalavras() {}
    
    // métodos
    void processarLogradouro(const std::string& nomeLogradouro, int idLog);
    void inserirPalavra(const std::string& p, int idLog);
    vector<int> buscarPalavra(const std::string& p) const;
    vector<int> processarConsulta(const std::string& consulta) const;
};

#endif
