#ifndef minHeap_HPP
#define minHeap_HPP

#include <iostream>
#include <stdexcept>

template <class T> 
class minHeap{
private:
    T *ptr;
    int size;
    int capacity;

public:
    // constructor and destructor
    minHeap();
    minHeap(const minHeap<T>& other); // copy constructor
    ~minHeap();
    
    // getter
    int get_size() const;
    int get_capacity() const;

int getAncestral(int i){ 
	return (i-1)/2; // se seguir a logica de bitshift n se transformaria em float
} 
int getSucessorEsq(int i){ 
	return 2 * i + 1; 
} 
int getSucessorDir(int i){ 
	return 2 * i + 2; 
}
    // functions
    void push(T obj);
    void pop();
    void clear();

    // operators
    T& operator[](int index);
    minHeap<T>& operator=(const minHeap<T>& other); // assignment operator
};

// implementation

template <class T>
minHeap<T>::minHeap() {
    this->ptr = new T[1];
    this->size = 0;
    this->capacity = 1;
}

template <class T>
minHeap<T>::minHeap(const minHeap<T>& other) {
    size = other.size;
    capacity = other.capacity;
    if (capacity > 0) {
        ptr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            ptr[i] = other.ptr[i];
        }
    } else {
        ptr = NULL;
    }
}

template <class T>
minHeap<T>::~minHeap() {
    delete[] this->ptr;
}

template <class T>
int minHeap<T>::get_size() const {
    return this->size;
}
template <class T>
int minHeap<T>::get_capacity() const {
    return this->capacity;
}

template <typename T>
void minHeap<T>::push(T obj) { 
    if(size == capacity){
        T* temp = this->ptr; //points to the minHeap, making the values stores temporaly
        this->capacity *= 2; // simply double the capacity
        this->ptr = new T[this->capacity];

        for (int i = 0; i < size; ++i) {
            this->ptr[i] = temp[i]; // copies values to the new &
        }
        delete[] temp;
    }
    ptr[size] = obj; // doesnt need an else because it does in both cases
    
    //heapify
    int uptree = getAncestral(size);
    int pos = size;
    while (pos > 0 && obj < ptr[uptree]){
        T temp = ptr[pos];
        ptr[pos] = ptr[uptree];
        ptr[uptree] = temp;
        
        pos = uptree;
        uptree = getAncestral(uptree);
    }
    ++this->size;
}

template <typename T>
void minHeap<T>::pop() {
    if (size == 0){
        throw std::runtime_error("Cannot pop from empty container");
    }    
    ptr[0] = ptr[size-1];
    --this->size;
    if(size == capacity / 2){
        T* temp = this->ptr; //points to the minHeap, making the values stores temporaly
        this->ptr = new T[this->capacity/ 2]; // change the adress whit a newer size doubling it because is a binary heap
        for (int i = 0; i < size; ++i) {
            this->ptr[i] = temp[i]; // copies values to the new &
        }
        this->capacity /= 2;
        delete[] temp;
    }
 
    
    // heapify
    int pos = 0; 
    while (true){
        int lowtreeDir = getSucessorDir(pos);
        int lowtreeEsq = getSucessorEsq(pos);
        
        if (lowtreeDir < size){ //checa se ambos são indices possiveis
            if (ptr[pos] > ptr[lowtreeDir] || ptr[pos] > ptr[lowtreeEsq]){
                if(ptr[lowtreeEsq] >= ptr[lowtreeDir] ){
                    T temp = ptr[pos];
                    ptr[pos] = ptr[lowtreeDir];
                    ptr[lowtreeDir] = temp;
                    
                    pos = lowtreeDir;
                } else{
                    T temp = ptr[pos];
                    ptr[pos] = ptr[lowtreeEsq];
                    ptr[lowtreeEsq] = temp;
                    
                    pos = lowtreeEsq;
                }
            } else {
                break;
            }
        }
        else if(lowtreeEsq < size){
            if(ptr[pos] > ptr[lowtreeEsq] ){
                T temp = ptr[pos];
                ptr[pos] = ptr[lowtreeEsq];
                ptr[lowtreeEsq] = temp;
                
                pos = lowtreeEsq;
                break; // ultimo caso
            } else {
                break;
            }
        }
        else{
            break;
        }
    }
}

template <class T>
void minHeap<T>::clear() {
    delete[] this->ptr;
    this->ptr = new T[1];
    this->size = 0;
    this->capacity = 1;
}

template <class T>
T& minHeap<T>::operator[](int index) { //to be able to acess variables
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("invalid index");
    }
    return this->ptr[index];
}

template <class T>
minHeap<T>& minHeap<T>::operator=(const minHeap<T>& other) { // = operator
    if (this != &other) {
        delete[] ptr;
        size = other.size;
         capacity = other.capacity;
        if (capacity > 0) {
            ptr = new T[capacity];
            for (int i = 0; i < size; ++i) {
                ptr[i] = other.ptr[i];
            }
        } else {
            ptr = NULL;
        }
    }
    return *this;
}

#endif