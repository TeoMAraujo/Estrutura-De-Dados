#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream> // for debugging

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
    void insert(int pos, T obj);
    void remove(int pos); 
    void push_back(T obj);
    void push_front(T obj);
    void pop_back();
    void pop_front();
    void clear();

    // operators
    T& operator[](int index);
};

#endif
