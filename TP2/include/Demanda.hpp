#ifndef DEMANDA_HPP
#define DEMANDA_HPP

enum tipoCorrida {
  Demandada,
  Individual,
  Combinada,
  Concluida
};

struct coord {
  double x, y;
};

struct demanda {
  int passageiro;
  int tempoSolicitacao;
  coord origem, destino;
  tipoCorrida tipo;
  
  // é necessario esses operadores pro minheap funcionar
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