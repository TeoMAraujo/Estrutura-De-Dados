#include "Cena.hpp"
#include "Objeto.hpp"
#include "vector.hpp"


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
                                const float &x, const float &y,
                                const float &largura) {
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
    for(int i = 0; i < cena.get_size(); i++){
        for(int j = cena.get_size(); i <= j; j--){ //compare the first term until it own term
            if (cena[j].getX() > cena[i].getX()){ //that implies that somepart it will be visible
                if(cena[j].getX() >= (cena[i].getX() + cena[i].getLargura() - 1)){
                    continue; //when theres nothing to change
                }     
                else{ 
                    if((cena[j].getX() + cena[j].getLargura() - 1) > (cena[i].getX() + cena[i].getLargura() - 1)){ //if the behind object exceeds size
                        objeto temp = cena[i];
                        temp.setX(cena[j].getX() + cena[j].getLargura() - 1); //after the final of the front obj
                        temp.setLargura((cena[i].getX() + cena[i].getLargura() - 1) - (cena[j].getX() + cena[j].getLargura() - 1));
                        cena.insert(i+1, temp);
                        cena[i].setLargura(cena[j].getX()); //after the final of the front obj
                    }
                    else{
                        cena[i].setLargura(cena[j].getX()); //if the object shows just left side 
                    }
                } 
            } 
            else{ 
                if((cena[j].getX() + cena[j].getLargura() - 1) <= cena[i].getX()){
                    break; //when theres nothing to change
                }
                else{
                    if((cena[j].getX() + cena[j].getLargura() - 1) >= (cena[i].getX() + cena[i].getLargura())){ //if inside of other vector 
                        cena.remove(i);//if the size size +largura is less than vertor remove ]
                        break;
                    }
                    else{
                        cena[i].setX(cena[j].getX());
                        cena[i].setLargura(cena[j].getX() + cena[i].getX()); // if the object shows just right side
                    }
                }
            }
        }
    }
}


  void Cena::gerarCena(const int &time) {
    cena.clear();
    cenaSortTime(time); //make a new scene based on time
    mergeSort(cena, 0, cena.get_size()); //then sorts all Y, basically checking who's is first, then placing overlaping all the next cases, ocupping atrbuing it to a new object spaceOverlap, where its stores x1 and x2, where its sets boundries, that the next objects cannot occupy 
    sortOverlap();

    mergeSortById(cena, 0, cena.get_size());

    
  };

