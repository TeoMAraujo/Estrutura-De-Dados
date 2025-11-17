#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>

template <class T>
class vector {
private:
    T *ptr;
    int size;

public:
    // constructor and destructor
    vector();
    vector(int size);
    vector(const vector<T>& other); // copy constructor
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
    const T& operator[](int index) const; // versão const
    vector<T>& operator=(const vector<T>& other); // assignment operator
};

// implementation

template <class T>
vector<T>::vector() {
    this->ptr = nullptr;
    this->size = 0;
}

template <class T>
vector<T>::vector(int size) {
    this->ptr = new T[size];
    this->size = size;
}

template <class T>
vector<T>::vector(const vector<T>& other) {
    size = other.size;
    if (size > 0) {
        ptr = new T[size];
        for (int i = 0; i < size; ++i) {
            ptr[i] = other.ptr[i];
        }
    } else {
        ptr = nullptr;
    }
}

template <class T>
vector<T>::~vector() {
    delete[] this->ptr;
}

template <class T>
int vector<T>::get_size() const {
    return this->size;
}

template <typename T>
void vector<T>::insert(int pos, T obj) { 
    if (pos < 0 || pos > this->size) {
        throw std::out_of_range("invalid position");
    }
    T* temp = this->ptr; //points to the vector, making the values stores temporaly
    this->ptr = new T[this->size + 1]; // change the adress whit a newer size
    for (int i = 0; i < pos; ++i) {
        this->ptr[i] = temp[i]; // copies values to the new &
    }
    this->ptr[pos] = obj; //insert
    for (int i = pos; i < this->size; ++i) {
        this->ptr[i + 1] = temp[i]; // copie the last elements of temp
    }
    ++this->size;
    delete[] temp;
}

template <typename T>
void vector<T>::remove(int pos) {
    if (pos < 0 || pos >= this->size) {
        throw std::out_of_range("invalid position");
    }
    T* temp = this->ptr;
    this->ptr = new T[this->size - 1]; // same logic as insert, but the oposite
    for (int i = 0; i < pos; ++i) {
        this->ptr[i] = temp[i];
    }
    for (int i = pos + 1; i < this->size; ++i) {
        this->ptr[i - 1] = temp[i];
    }
    --this->size;
    delete[] temp;
}

template <class T>
void vector<T>::push_back(T obj) { // pushes a variable to last index
    this->insert(this->size, obj);
}

template <class T>
void vector<T>::push_front(T obj) { // pushes a variable to the first index
    this->insert(0, obj);
}

template <class T>
void vector<T>::pop_back() { // remove the last index
    if (this->size > 0) {
        this->remove(this->size - 1);
    }
}

template <class T>
void vector<T>::pop_front() { // remove the first index
    if (this->size > 0) {
        this->remove(0);
    }
}

template <class T>
void vector<T>::clear() { //cleans vector
    delete[] this->ptr;
    this->ptr = nullptr;
    this->size = 0;
}

template <class T>
T& vector<T>::operator[](int index) { //to be able to acess variables
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("invalid index");
    }
    return this->ptr[index];
}

template <class T>
const T& vector<T>::operator[](int index) const { //versão const do operador[]
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("invalid index");
    }
    return this->ptr[index];
}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>& other) { // = operator
    if (this != &other) {
        delete[] ptr;
        size = other.size;
        if (size > 0) {
            ptr = new T[size];
            for (int i = 0; i < size; ++i) {
                ptr[i] = other.ptr[i];
            }
        } else {
            ptr = nullptr;
        }
    }
    return *this;
}

#endif