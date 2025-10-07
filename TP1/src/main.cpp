#include <iostream>
#include <iomanip>
#include "Cena.hpp"
int main(){
    char token;
    Cena principal;
    int object, time;
    float x , y, largura;

    while (token == 'O' || token == 'M' || token == 'C') {
        std::cin >> token >> object >> time >> x >> y >> largura;
        switch (token){
            case 'O':
                principal.addObject(x, y, largura);
                break;
            case 'M':
                principal.addMovement(object, time, x, y, largura);
                break;
            case 'C':
                principal.gerarCena(time);
                vector<objeto> &ref = principal.getCena();
                for (int i = 0; i < ref.get_size()  ; i++){       
                    std::cout << 'S' << " " << time << " " << ref[i].getId() << " " << std::fixed << std::setprecision(2) << ref[i].getX() << " " << std::fixed << std::setprecision(2) << ref[i].getLargura() << '\n';
                }
               break;
        }
    return 0; // Indicate successful execution
    }
}