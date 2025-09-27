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
template <class T> void vector<t>::clear(){
  if (size == 0){
    return; // nothing to clear
  }
  else{
    size = 0;
    T *temp = ptr; // points to ptr
    ptr = new T[size]; // redimension

    delete[] temp;
  }
}


// merge
void merge(vector<int>& arr, int left, 
                     int mid, int right){
                         
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// operators
template <class T> T& vector<T>::operator[](int index) {
  if (index < 0 || index >= size) {
    throw std::out_of_range("invalid index");
  } 
  return ptr[index];
}

