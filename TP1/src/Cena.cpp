#include "Cena.hpp"
#include "Objeto.hpp"
#include "vector.hpp"

#define BEHIND_CENTER  (cena[j].getX())                         
#define BEHIND_FINALX (cena[j].getX() + cena[j].getLargura()) 
#define FRONT_CENTER   (cena[i].getX())                         
#define FRONT_FINALX  (cena[i].getX() + cena[i].getLargura())   
// vou até sair do inglês aqui, olha, eu poderia colocar isso dentro de uma função referencia, 
// normalmente o mínimo manejamento de memória faz diferença, já que, inicialmente afim de melhorar 
 // maybe até seria uma prática melhor, mas uma área que pretendo trabalhar é embarcados, coisas que 
 // a legibilidade eu substitui os statemems por floats, porém isso ocuparia 64bits, porém bolei uma
                                                             // solução pré compilador que poderia melhorar a legibiilidade nesse caso, isso é mais um teste msm, 
                                                              // nem precisaria
                                                              


Cena::Cena() {
}

vector<objeto>& Cena::getCena() {
    return cena;
}

  void Cena::addObject(const double &x, const double &y,
                              const double &largura) {
    objeto temp(objetos.get_size(), 0, x, y, largura); // ID matches array index (0-based)
// O VPL N TEM NENHUM CASO MAS CASO OUVESSE UM OBJETO ADICIONADO, DPS IA DA O CACETE, mas ia ta la
    vector<objeto> newObject;
    newObject.push_back(temp);    // Creates the first movement
    objetos.push_back(newObject); // adds an object to the list

  }
  void Cena::addMovement(const int &object, const int &tempo,
                                const double &x, const double &y) {

    double largura = objetos[object][objetos[object].get_size() - 1].getLargura();
    
    objeto temp(object, tempo, x, y, largura);
    objetos[object].push_back(temp);
  }

void Cena::cenaSortTime(const int &time) {
    cena.clear();
    for (int i = 0; i < objetos.get_size(); i++) {
        // Find the most recent movement at or before the given time
        int selectedIndex = 0; // Default to original object creation (index 0)
        for (int j = 0; j < objetos[i].get_size(); j++) {
            if (objetos[i][j].getTempo() <= time) {
                selectedIndex = j; // Keep updating to find the most recent valid movement
            }
        }
        cena.push_back(objetos[i][selectedIndex]);
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
        if (L[i].getY() <= R[j].getY()) { // Lower Y values first (back-to-front priority)
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
        for(int j = i+1; j < cena.get_size(); j++){
            // Calculate actual boundaries using center coordinates
            double behind_center = cena[j].getX();
            double behind_half_width = cena[j].getLargura() / 2.0;
            double behind_start = behind_center - behind_half_width;
            double behind_end = behind_center + behind_half_width;
            
            double front_center = cena[i].getX();
            double front_half_width = cena[i].getLargura() / 2.0;
            double front_start = front_center - front_half_width;
            double front_end = front_center + front_half_width;
            
            // Check if there's any overlap
            if (behind_end <= front_start || behind_start >= front_end) {
                continue; // No overlap
            }
            
            // There is overlap - handle different cases
            if (behind_start < front_start) {
                // Behind object starts before front object
                if (behind_end <= front_end) {
                    // Behind object ends before or at front object end
                    // Truncate behind object to end where front starts
                    double new_width = front_start - behind_start;
                    double new_center = behind_start + new_width / 2.0;
                    cena[j].setX(new_center);
                    cena[j].setLargura(new_width);
                } else {
                    // Behind object extends past front object
                    // Split behind object into two parts
                    double left_width = front_start - behind_start;
                    double left_center = behind_start + left_width / 2.0;
                    double right_width = behind_end - front_end;
                    double right_center = front_end + right_width / 2.0;
                    
                    objeto temp(cena[j].getId(), cena[j].getTempo(), right_center, cena[j].getY(), right_width);
                    cena.insert(j+1, temp);
                    
                    // Update original behind object (left part)
                    cena[j].setX(left_center);
                    cena[j].setLargura(left_width);
                }
            } else {
                // Behind object starts at or after front object start
                if (behind_end <= front_end) {
                    // Behind object is completely inside front object - remove it
                    cena.remove(j);
                    j--; // Adjust index after removal
                } else {
                    // Behind object extends past front object
                    // Move behind object to start where front ends
                    double new_width = behind_end - front_end;
                    double new_center = front_end + new_width / 2.0;
                    cena[j].setX(new_center);
                    cena[j].setLargura(new_width);
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
    
    // Convert from center+width to start+end coordinates for output
    for (int i = 0; i < cena.get_size(); i++){
        double center = cena[i].getX();
        double width = cena[i].getLargura();
        double start_x = center - width / 2.0;
        double end_x = center + width / 2.0;
        
        cena[i].setX(start_x); // Set start coordinate
        cena[i].setLargura(end_x); // Set end coordinate in largura field for output
    }   
  };




  