#include <iostream>
#include <iomanip>
#include "Cena.hpp"
int main(){
    char token;
    Cena principal;
    int object, time;
    float x , y;
    float largura;

    while (token == 'O' || token == 'M' || token == 'C') {
        std::cin >> token >> object >> time >> x >> y >> largura;
        switch (token){
            case 'O':
                principal.addObject(x, y, largura);
            case 'M':
                principal.addMovement(objeto, time, x, y, largura);
            case 'C':
                principal.gerarCena(time);
                vector<objetos> *ptr = principal.getCena();
                for (int i = 0; i < *ptr.getSize()  ; i++){
                    std::cout << 'S' << time << ptr[i].getId() << setprecisionptr[i].getX() << setprecision ptr[i].getLargura() << '\n'; //largura in this case is already the x-final position 
                }
        
        }
    }

}