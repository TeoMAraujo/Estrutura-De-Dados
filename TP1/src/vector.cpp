#include "vector.hpp"
#include <iostream>

// constructors and destructor
template <class T> vector<T>::vector() {
    this->ptr = nullptr;
    size = 0;
}

template <class T> vector<T>::vector(int size) {
    ptr = new T[size];
    this->size = size;
}

template <class T> vector<T>::~vector() {
    delete[] ptr;
}

// getter
template <class T> int vector<T>::get_size() const {
    return size;
}

// functions
template <class T> void vector<T>::insert(int pos, T obj) {
    if (pos < 0 || pos > size) {
        throw std::out_of_range("invalid position");
    }
    T* temp = ptr;
    ptr = new T[size + 1];
    for (int i = 0; i < pos; ++i) {
        ptr[i] = temp[i];
    }
    ptr[pos] = obj;
    for (int i = pos; i < size; ++i) {
        ptr[i + 1] = temp[i];
    }
    ++size;
    delete[] temp;
}

template <class T> void vector<T>::remove(int pos) {
    if (pos < 0 || pos >= size) {
        throw std::out_of_range("invalid position");
    }
    T* temp = ptr;
    ptr = new T[size - 1];
    for (int i = 0; i < pos; ++i) {
        ptr[i] = temp[i];
    }
    for (int i = pos + 1; i < size; ++i) {
        ptr[i - 1] = temp[i];
    }
    --size;
    delete[] temp;
}

template <class T> void vector<T>::push_back(T obj) {
    insert(size, obj);
}

template <class T> void vector<T>::push_front(T obj) {
    insert(0, obj);
}


template <class T> void vector<T>::pop_back() {
    remove(size);
}


template <class T> void vector<T>::pop_front() {
    remove(0);
}

template <class T> void vector<T>::clear(){
    size = 0;
    delete[] ptr;
    ptr = nullptr; // redimension
}


// operators
template <class T> T& vector<T>::operator[](int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("invalid index");
  } 
  return ptr[index];
}

