/*
Trabalho Prático 3 - Estruturas de Dados
Sistema de Consulta de Endereços CabeAí
*/

#include <iostream>
#include <string>
#include "Endereco.hpp"
#include "Logradouro.hpp"
#include "Palavra.hpp"
#include "Consulta.hpp"

using namespace std;

int main() {
    // leitura do número de endereços
    int N;
    cin >> N;
    cin.ignore(); // ignora newline
    
    // inicializa estruturas de dados
    GerenciadorLogradouros gerencLogradouros;
    GerenciadorPalavras gerencPalavras;
    
    // lê e processa cada endereço
    for (int i = 0; i < N; i++) {
        Endereco end = lerEndereco();
        
        // adiciona ao gerenciador de logradouros
        gerencLogradouros.inserirEndereco(end);
        
        // indexa as palavras do logradouro
        string nomeCompleto = end.TipoLog + " " + end.Log;
        gerencPalavras.processarLogradouro(nomeCompleto, end.IdLog);
    }
    
    // lê número de consultas e máximo de respostas
    int M, R;
    cin >> M >> R;
    cin.ignore(); // ignora newline
    
    // inicializa processador de consultas
    ProcessadorConsultas processador(&gerencLogradouros, &gerencPalavras);
    
    // imprime número de consultas
    cout << M << endl;
    
    // processa cada consulta
    for (int i = 0; i < M; i++) {
        ConsultaData consulta = lerConsulta();
        
        // processa a consulta
        vector<LogradouroDistancia> resultados = processador.processarConsulta(consulta, R);
        
        // imprime resultados
        cout << consulta.idConsulta << ";" << resultados.get_size() << endl;
        
        for (int j = 0; j < resultados.get_size(); j++) {
            cout << resultados[j].idLog << ";" << resultados[j].nomeCompleto << endl;
        }
    }
    
    return 0;
}
