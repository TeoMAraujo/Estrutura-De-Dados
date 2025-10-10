
#include <iostream>
#include <iomanip>
#include "Cena.hpp"

int main() {
    Cena principal;
    char token;
    int object, time;
    double x, y, largura;

    while (std::cin >> token) {
        switch (token) {
            case 'O':
                // O objectId x y largura
                std::cin >> object >> x >> y >> largura;
                principal.addObject(x, y, largura);
                break;
            case 'M':
                // M movementId objectId x y
                int movementId;
                std::cin >> movementId >> object >> x >> y;
                principal.addMovement(object, movementId, x, y); 
                break;
            case 'C':
                // C time
                std::cin >> time;
                principal.gerarCena(time);
                vector<objeto>& ref = principal.getCena();
                for (int i = 0; i < ref.get_size(); i++) {
                    std::cout << 'S' << " " << time << " " << ref[i].getId() << " "
                              << std::fixed << std::setprecision(2) << ref[i].getX() << " "
                              << std::fixed << std::setprecision(2) << ref[i].getLargura() << '\n';
                }
                break;
        }
    }

    return 0; 
}