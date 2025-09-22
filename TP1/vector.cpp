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
template <class T> void vector<T>::push_back(T obj) { // this impĺementation relly on processor, rather than memory because it duplicates and than extinguish the old array
  if (size == 0){
    ptr = new T; 
    *ptr = obj; // nothing to pop
    ++size;
  } else{
    ++ size;
    T *temp = ptr; // points to ptr
    ptr = new T[size]; // redimension

    for (int i = 0; i < size - 1; i++) {
        ptr[i] = temp[i]; // copy all elements into new array
    }
    ptr[size - 1] = obj;

    delete[] temp;
  }
}

template <class T> void vector<T>::pop_back() {
  if (size == 0){
    return; // nothing to pop
  }
  else{
    -- size;
    T *temp = ptr; // points to ptr
    ptr = new T[size]; // redimension

    for (int i = 0; i < size; i++) {
      ptr[i] = temp[i]; // copy all elements into new array, except the last
    }
    
    delete[] temp;
  }
}

// operators
template <class T> T& vector<T>::operator[](int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("invalid index");
  } 
  return ptr[index];
}

