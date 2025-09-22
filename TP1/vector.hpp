#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <class T> class vector {
private:
    T *ptr;
    int size;
public:
    // Constructor and Destructor
    vector();
    vector(int size);
    ~vector();
    
    // getter
    int get_size() const;

    // functions
    void push_back(T obj);
    void pop_back();

    // operators
    T& operator[](int index);
};

#endif 
