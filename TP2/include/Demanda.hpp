#ifndef DEMANDA_HPP
#define DEMANDA_HPP

enum tipoCorrida {
  Demandada,
  Individual,
  Combinada,
  Concluída
};

struct coord {
  double x, y;
};

struct demanda {
  int passageiro;
  int tempoSolicitacao;
  coord origem, destino;
  tipoCorrida tipo;
  
  // Operadores de comparação para minHeap
  bool operator<(const demanda& other) const {
    return tempoSolicitacao < other.tempoSolicitacao;
  }
  
  bool operator>(const demanda& other) const {
    return tempoSolicitacao > other.tempoSolicitacao;
  }
  
  bool operator>=(const demanda& other) const {
    return tempoSolicitacao >= other.tempoSolicitacao;
  }
};

#endif