#include "Objeto.hpp"
#include "vector.hpp"

class list_objeto {
private:
  vector<vector<objeto>> objetos; // 1° = obj 2° mov
  vector<objeto> cena;

public:
  list_objeto() {}

  int getSize() const { return objetos.get_size(); }

  objeto &getObjeto(int index) { return objetos[index]; }
  // Add more methods as needed

  void list_objeto::addMovement(const int &object, const int &tempo,
                                const float &x, const float &y,
                                const float &largura) {
    objeto temp(tempo, x, y, largura);
    objetos[object].push_back(temp);
  }
  void list_objeto::addObject(const float &x, const float &y,
                              const float &largura) {
    objeto temp(objetos.size(), x, y, largura);
    vector<objeto> newObject;
    newObject.push_back(temp);    // Creates the first movement
    objetos.push_back(newObject); // adds an object to the list
  }
  
  void list_objeto::cenaSortTime(const int &time){
    for (int i = 0; i < objetos.get_size() - 1; i++) { //iterate over objects
      for (int i = objetos[i].get_size() - 1; i > -1; i--) { //iterate over movements
        if (objetos[i][j].id <= time){ // find the movement for the time
          cena.push_back(objetos[i][j]);
          break;
        }
      }
    }
  }



  void::list_objeto::merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vector with half size of arr
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

void::list_objeto::mergeSort(vector<objeto> &arr, int left, int right){
  if (left <= right)
    return;

  int mid = left + ((right - left) / 2);
  mergeSort(arr.getY(), left, mid); // if array was 0,1,2,3,4,5,6,7 goes to 0,1,2,3
  mergeSort(arr.getY(), mid + 1, right);   // then goes to 4,5,6,7
  merge(arr.getY(), left, mid, right); //every subset is sorted and merged back together
}



  void list_objeto::gerarCena(const int &time) {
    cena.clear();
    cenaSortTime(time); //make a new scene based on time

    mergeSort(cena, 0, cena.get_size()); //then sorts all Y, basically checking who's is first, then placing overlaping all the next cases, ocupping atrbuing it to a new object spaceOverlap, where its stores x1 and x2, where its sets boundries, that the next objectss cannot occupy

  };
  

