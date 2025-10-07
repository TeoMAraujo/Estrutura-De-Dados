#ifndef CENA_HPP
#define CENA_HPP

#include "Objeto.hpp"
#include "vector.hpp"

class Cena {
private:
    vector<vector<objeto>> objetos;
    vector<objeto> cena;
public:
    //constructor
    Cena();

    //kinda getters and setters
    vector<objeto>& getCena();
    void addObject(const float &x, const float &y, const float &largura);
    void addMovement(const int &object, const int &tempo, const float &x, const float &y, const float &largura);

    // Sorting methods
    void cenaSortTime(const int &time);
    void merge(vector<int>& arr, int left, int mid, int right);
    void mergeSort(vector<objeto>& arr, int left, int right);
    void sortOverlap();
    void gerarCena(const int &time); //all the previous sorts concatenates into major function
};

#endif // CENA_HPP
