#include "Objeto.hpp"
#include "vector.hpp"

class list_objeto {
private:
  vector<vector<objeto>> objetos; // 1° = obj 2° movimentos
  vector<objeto> cena;

public:
  list_objeto() {}

  int getSize() const { return objetos.get_size(); }

  objeto &getObjeto(int index) { return objetos[index]; }
  // Add more methods as needed

  void list_objeto::addMovement(const int &object.const int &tempo,
                                const float &x, const float &y,
                                const float &largura) {
    objeto temp;
    temp.tempo = tempo;
    temp.x = x;
    temp.y = y;
    temp.largura = largura;
    int id = objetos;
    get_size;:
    objetos[object].push_back(temp);
  }
  void list_objeto::addObject(const float &x, const float &y,
                              const float &largura) {
    objeto temp;
    temp.tempo = 0;
    temp.x = x;
    temp.y = y;
    temp.largura = largura;
    vector<objeto> newObject;
    newObject.push_back(temp);    // cria o primeiro movimento
    objetos.push_back(newObject); // adiciona o objeto na lista
  }
  oid gerarCena(int Tempo) {
    // adds info
    cena.clear;
    for (int i = 0; i < objetos.get_size() - 1; i++) {
      for (int i = objetos[i].get_size() - 1; i > -1; i--) {
        if (objetos[i][j].tempo <= Tempo)
          cena.push_back(objetos[i][j]);
      }
      else {
        continue;
      }
    }
  };
