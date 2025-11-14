#ifndef DEMANDA_HPP
#define DEMANDA_HPP

enum corrida {
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
  corrida tipo;
};

#endif