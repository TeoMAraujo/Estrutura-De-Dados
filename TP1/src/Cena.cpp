#include "Cena.hpp"
#include "Objeto.hpp"
#include "vector.hpp"

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

  void Cena::cenaSortTime(const int &time){
    for (int i = 0; i < objetos.get_size() - 1; i++) { //iterate over objects
      for (int j = objetos[i].get_size() - 1; j > -1; j--) { //iterate over movements
        if (objetos[i][j].getTempo() <= time){ // find the movement for the time
          cena.push_back(objetos[i][j]);
          break;
        }
      }
    }
  }


  void::Cena::merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //create temp vector with half size of arr
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
      L.push_back(arr[left + i]);
    for (int j = 0; j < n2; j++)
      R.push_back(arr[mid + 1 + j]);

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2){ //iterete over both vectors
      if (L[i] <= R[j]){ // because the previous vectors are sorted, we can just compare the first element of each vector
        arr[k] = L[i];
        i++;
      }else{
        arr[k] = R[j];
        j++;
      }
      k++;
    }
      if (i < n1){ //if there are still elements in L, add them to arr
        arr[k] = L[i];
        i++;
        k++;
      }
  }

void::Cena::mergeSort(vector<objeto> &arr, int left, int right){
  if (left <= right)
    return;

  int mid = left + ((right - left) / 2);
  mergeSort(arr(), left, mid); // if array was 0,1,2,3,4,5,6,7 goes to 0,1,2,3
  mergeSort(arr(), mid + 1, right);   // then goes to 4,5,6,7
  merge(arr(), left, mid, right); //every subset is sorted and merged back together
}

void Cena::sortOverlap(){
    for(int i = 1; i < cena.get_size(); i++){
        for(int j = 0; i < j; j++){ //compare the first term until it own term
            if (cena[j].getX() > cena[i].getX()){ //that implies that somepart it will be visible
                if(cena[j].getX() >= (cena[i].getX() + cena[i].getLargura() - 1)){
                    continue; //when theres nothing to change
                }     
                else{ 
                    if((cena[j].getX() + cena[j].getLargura() - 1) < (cena[i].getX() + cena[i].getLargura() - 1)){ //if the bhind object exceeds size
                        objeto temp = cena[i];
                        temp.setX(cena[j].getX() + cena[j].getLargura() - 1); //after the final of the front obj
                        temp.setLargura((cena[i].getX() + cena[i].getLargura() - 1) - (cena[j].getX + cena[j].getLargura() - 1))
                        cena.insert(i+1, temp);
                        cena[i].setLargura(cena[j].getX()); //after the final of the front obj
                    }
                    else{
                        cena[i].setLargura(cena[j].getX())
                    }
                } 
            } 
            else{ 
                if((cena[j].getX() + largura - 1) <= cena[i].getX()){
                    break; //when theres nothing to change
                }
                else{
                    if((cena[j].getX() + largura - 1) >= (cena[i].getX() + cena[i].getLargura())){ //if inside of other vector 
                        cena.remove(i)//if the size size +largura is less than vertor remove ]
                        break;
                    }
                    else{
                        cena[i].setX(cena[j].getX())
                        cena[i].setLargura(cena[j].getX()+ cena[i].getX())//need to resize the vector X to cena[j].getX() + largura -1, and change largura
                    }
                }
            }
        }
    }
}


  void Cena::gerarCena(const int &time) {
    cena.clear();
    cenaSortTime(time); //make a new scene based on time
    mergeSort(cena.getY(), 0, cena.get_size()); //then sorts all Y, basically checking who's is first, then placing overlaping all the next cases, ocupping atrbuing it to a new object spaceOverlap, where its stores x1 and x2, where its sets boundries, that the next objects cannot occupy 
    sortOverlap();

    mergeSort(cena.getX(), 0, cena.get_:size());

    
  };

