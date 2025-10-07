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
    // Cinstructor and destructor
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
vector<T>::~vector() {
    delete[] this->ptr;
}

template <class T>
int vector<T>::get_size() const {
    return this->size;
}

template <class T>
void vector<T>::insert(int pos, T obj) {
    if (pos < 0 || pos > this->size) {
        throw std::out_of_range("invalid position");
    }
    T* temp = this->ptr;
    this->ptr = new T[this->size + 1];
    for (int i = 0; i < pos; ++i) {
        this->ptr[i] = temp[i];
    }
    this->ptr[pos] = obj;
    for (int i = pos; i < this->size; ++i) {
        this->ptr[i + 1] = temp[i];
    }
    ++this->size;
    delete[] temp;
}

template <class T>
void vector<T>::remove(int pos) {
    if (pos < 0 || pos >= this->size) {
        throw std::out_of_range("invalid position");
    }
    T* temp = this->ptr;
    this->ptr = new T[this->size - 1];
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
void vector<T>::push_back(T obj) {
    this->insert(this->size, obj);
}

template <class T>
void vector<T>::push_front(T obj) {
    this->insert(0, obj);
}

template <class T>
void vector<T>::pop_back() {
    if (this->size > 0) {
        this->remove(this->size - 1);
    }
}

template <class T>
void vector<T>::pop_front() {
    if (this->size > 0) {
        this->remove(0);
    }
}

template <class T>
void vector<T>::clear() {
    delete[] this->ptr;
    this->ptr = nullptr;
    this->size = 0;
}

template <class T>
T& vector<T>::operator[](int index) {
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("invalid index");
    }
    return this->ptr[index];
}

#endif 