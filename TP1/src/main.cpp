
#include <iostream>
#include <iomanip>
#include "Cena.hpp"

int main() {
    char token;
    Cena principal;
    int object, time;
    double x, y, largura;

    // This loop structure correctly reads a token and continues
    // as long as there is input to read.
    while (std::cin >> token) {
        switch (token) {
            case 'O':
                // For 'O', format is: O objectId x y largura
                std::cin >> object >> x >> y >> largura;
                principal.addObject(x, y, largura); // Object ID is sequential, not from input
                break;
            case 'M':
                // For 'M', format is: M movementId objectId x y
                int movementId;
                std::cin >> movementId >> object >> x >> y;
                principal.addMovement(object, movementId, x, y); // Use movementId as time
                break;
            case 'C':
                // For 'C', we only need the time
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

    // return 0 is now correctly placed outside the loop.
    return 0; 
}