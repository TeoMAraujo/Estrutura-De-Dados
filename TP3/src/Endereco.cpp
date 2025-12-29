#include "Endereco.hpp"
#include <iostream>

// função para ler um endereço de uma linha
Endereco lerEndereco() {
    Endereco end;
    char delim;
    
    std::getline(std::cin, end.IdEnd, ';');
    std::cin >> end.IdLog >> delim;
    
    std::getline(std::cin, end.TipoLog, ';');
    std::getline(std::cin, end.Log, ';');
    std::cin >> end.Num >> delim;
    
    std::getline(std::cin, end.Bairro, ';');
    std::getline(std::cin, end.Regiao, ';');
    std::getline(std::cin, end.CEP, ';');
    std::cin >> end.Lat >> delim >> end.Long;
    
    std::cin.ignore();
    
    return end;
}

// função para ler uma consulta de uma linha
ConsultaData lerConsulta() {
    ConsultaData consulta;
    char delim;
    
    std::cin >> consulta.idConsulta >> delim;
    std::getline(std::cin, consulta.consulta, ';');
    std::cin >> consulta.latOrigem >> delim >> consulta.longOrigem;
    std::cin.ignore();
    
    return consulta;
}
