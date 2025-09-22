#include <iostream>
#include <stack>
#include "vector.hpp"

class objeto {
    private:
    float x, y;
    float largura;
    vector<movimento> movement;  //every time there's an alteration of time, the movement directly impacts

    public:
    objeto(float x,float y,float largura){this->x = x; this-> y = y; this->largura = largura; movement()}
    
    float getX(){return this->>x};
    float getY(){return this->>y}; //theres' aint any setters, to make the usuary unable to switch as is may intend
    float getLargura(){return this->>largura};
    
    void addMovement(int tempo, float x, float y, float largura){
        movimento temp;
        temp.tempo = tempo;
        temp.x = x;
        temp.y = y;
        temp.largura = largura;
        this->movement.push_back(temp);
    };
};

struct movimento {
    int tempo;
    float x,y;
    float largura;
};

class list_objeto{
    private:    
    vector<objeto> O; // the number of the object is defined by its index
    
    public:
    // Constructor
    // 3 sructs: 1 que não tem inicialização outro q depende de uma inicialização porém sem movimento e outra com td  
    Objeto()

    //setter e getters
   
    // funções  
    
};

