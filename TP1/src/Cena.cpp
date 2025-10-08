#include "Cena.hpp"
#include "Objeto.hpp"
#include "vector.hpp"

#define BEHIND_LEFT  (cena[j].getX())                                      
#define BEHIND_RIGHT (cena[j].getX() + cena[j].getLargura()) 
#define FRONT_LEFT   (cena[i].getX())                          
#define FRONT_RIGHT  (cena[i].getX() + cena[i].getLargura())  
 

// vou até sair do inglês aq  
 // maybe até seria uma prática melhor, mas uma área que pretendo trabalhar é embarcados, coisas que 
 // normalmente o mínimo manejamento de memória faz diferença, já que, inicialmente afim de melhorar                           
// a legibilidade eu substitui os statemems por floats, porém isso ocuparia 64bits, porém bolei uma
 // solução pré compilador que poderia melhorar a legibiilidade nesse caso, isso é mais um teste msm, 
                                                              // nem precisaria


Cena::Cena() {
    // Constructor can be empty if there's no special setup to do.
    // Or you can initialize variables here if needed.
}

vector<objeto>& Cena::getCena() {
    return cena;
}

  void Cena::addObject(const float &x, const float &y,
                              const float &largura) {
    objeto temp(objetos.get_size(),0, x, y, largura);
// O VPL N TEM NENHUM CASO MAS CASO OUVESSE UM OBJETO ADICIONADO DPS IA DA O CACETE, mas ia ta la
    vector<objeto> newObject;
    newObject.push_back(temp);    // Creates the first movement
    objetos.push_back(newObject); // adds an object to the list

  }
  void Cena::addMovement(const int &object, const int &tempo,
                                const float &x, const float &y) {
    // Get the largura from the most recent movement of this object
    float largura = objetos[object][objetos[object].get_size() - 1].getLargura();
    objeto temp(object, tempo, x, y, largura);
    objetos[object].push_back(temp);
  }

void Cena::cenaSortTime(const int &time) {
    cena.clear();
    for (int i = 0; i < objetos.get_size(); i++) {
        for (int j = objetos[i].get_size() - 1; j >= 0; j--) {
            if (objetos[i][j].getTempo() <= time) { 
                cena.push_back(objetos[i][j]);
                break;
            }
        }
    }
}

void Cena::merge(vector<objeto>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<objeto> L, R;
    for (int i = 0; i < n1; i++) L.push_back(arr[left + i]);
    for (int j = 0; j < n2; j++) R.push_back(arr[mid + 1 + j]);

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].getY() <= R[j].getY()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arr[k++] = L[i++]; }
    while (j < n2) { arr[k++] = R[j++]; }
}

void Cena::mergeSort(vector<objeto>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void Cena::mergeById(vector<objeto>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<objeto> L, R;
    for (int i = 0; i < n1; i++) L.push_back(arr[left + i]);
    for (int j = 0; j < n2; j++) R.push_back(arr[mid + 1 + j]);

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].getId() <= R[j].getId()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arr[k++] = L[i++]; }
    while (j < n2) { arr[k++] = R[j++]; }
}

void Cena::mergeSortById(vector<objeto>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortById(arr, left, mid);
    mergeSortById(arr, mid + 1, right);
    mergeById(arr, left, mid, right);
}
void Cena::sortOverlap(){
    // Objects are sorted by Y coordinate (front to back)
    // Objects with smaller Y are in front and can hide objects behind them
    for(int i = 0; i < cena.get_size(); i++){
        for(int j = i+1; j < cena.get_size(); j++){
            float frontLeft = cena[i].getX();
            float frontRight = cena[i].getX() + cena[i].getLargura();
            float backLeft = cena[j].getX();
            float backRight = cena[j].getX() + cena[j].getLargura();
            
            // Check if objects overlap horizontally
            if (frontLeft < backRight && backLeft < frontRight) {
                // Objects overlap - front object (i) occludes back object (j)
                
                if (backLeft >= frontLeft && backRight <= frontRight) {
                    // Back object is completely hidden
                    cena.remove(j);
                    j--;
                }
                else if (backLeft < frontLeft && backRight > frontRight) {
                    // Front object splits back object into two parts
                    // Left part: [backLeft, frontLeft]
                    float leftWidth = frontLeft - backLeft;
                    cena[j].setLargura(leftWidth);
                    
                    // Right part: [frontRight, backRight]
                    float rightWidth = backRight - frontRight;
                    objeto rightPart(cena[j].getId(), cena[j].getTempo(), frontRight, cena[j].getY(), rightWidth);
                    cena.insert(j+1, rightPart);
                }
                else if (backLeft < frontLeft && backRight <= frontRight) {
                    // Back object extends to the left of front object
                    // Keep only the left visible part
                    float newWidth = frontLeft - backLeft;
                    cena[j].setLargura(newWidth);
                }
                else if (backLeft >= frontLeft && backRight > frontRight) {
                    // Back object extends to the right of front object
                    // Keep only the right visible part
                    float newWidth = backRight - frontRight;
                    cena[j].setX(frontRight);
                    cena[j].setLargura(newWidth);
                }
            }
        }
    }
}

void Cena::gerarCena(const int &time) {
    cena.clear();
    cenaSortTime(time); //make a new scene based on time
    if (cena.get_size() > 0) {
        mergeSort(cena, 0, cena.get_size() - 1); //then sorts all Y, basically checking who's is first, then placing overlaping all the next cases, ocupping atrbuing it to a new object spaceOverlap, where its stores x1 and x2, where its sets boundries, that the next objects cannot occupy 
        sortOverlap();
        mergeSortById(cena, 0, cena.get_size() - 1);
    }
  };




  