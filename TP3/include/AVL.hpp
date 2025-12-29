#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <stdexcept>

template <class T>
class AVL {
private:
    struct Node {
        T value;
        int height;
        Node* leftChild;
        Node* rightChild;
        
        Node(const T& val) {
            this->value = val;
            this->height = 1;
            this->leftChild = nullptr;
            this->rightChild = nullptr;
        }
    };
    
    Node* root;
    int size;
    
    // Utility functions
    int max(int a, int b) const;
    int getHeight(Node* node) const;
    int balanceFactor(Node* node) const;
    void updateHeight(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* balance(Node* node);
    Node* findMin(Node* node) const;
    
    // Recursive functions
    Node* insertNode(Node* node, const T& value);
    Node* removeNode(Node* node, const T& value);
    Node* searchNode(Node* node, const T& value) const;
    void destroyTree(Node* node);
    void copyTree(Node* node);

public:
    // Constructor and destructor
    AVL();
    AVL(const AVL<T>& other); // copy constructor
    ~AVL();
    
    // Getters
    int get_size() const;
    int get_height() const;
    
    // Main functions
    void insert(const T& value);
    void remove(const T& value);
    bool search(const T& value) const;
    T* searchPtr(const T& value);  // Retorna ponteiro para o valor
    const T* searchPtr(const T& value) const;  // Versão const
    void clear();
    
    // Operators
    AVL<T>& operator=(const AVL<T>& other); // assignment operator
};

// Implementation

// Constructor
template <class T>
AVL<T>::AVL() {
    this->root = nullptr;
    this->size = 0;
}

// Copy constructor
template <class T>
AVL<T>::AVL(const AVL<T>& other) {
    this->root = nullptr;
    this->size = 0;
    if (other.root != nullptr) {
        copyTree(other.root);
    }
}

// destructor
template <class T>
AVL<T>::~AVL() {
    clear();
}

// Max function
template <class T>
int AVL<T>::max(int a, int b) const {
    return (a > b) ? a : b;
}

// node height
template <class T>
int AVL<T>::getHeight(Node* node) const {
    return (node == nullptr) ? 0 : node->height;
}

// Get balance factor
template <class T>
int AVL<T>::balanceFactor(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->leftChild) - getHeight(node->rightChild);
}

// Update height of a node
template <class T>
void AVL<T>::updateHeight(Node* node) {
    if (node != nullptr) {
        node->height = 1 + max(getHeight(node->leftChild), getHeight(node->rightChild));
    }
}

// Right rotation
template <class T>
typename AVL<T>::Node* AVL<T>::rotateRight(Node* y) {
    Node* x = y->leftChild;
    Node* T2 = x->rightChild;
    
    x->rightChild = y;
    y->leftChild = T2;
    
    updateHeight(y);
    updateHeight(x);
    
    return x;
}

// Left rotation
template <class T>
typename AVL<T>::Node* AVL<T>::rotateLeft(Node* x) {
    Node* y = x->rightChild;
    Node* T2 = y->leftChild;
    
    y->leftChild = x;
    x->rightChild = T2;
    
    updateHeight(x);
    updateHeight(y);
    
    return y;
}

// Balance the node
template <class T>
typename AVL<T>::Node* AVL<T>::balance(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    
    updateHeight(node);
    int bf = balanceFactor(node);
    
    // Left-Left case
    if (bf > 1 && balanceFactor(node->leftChild) >= 0) {
        return rotateRight(node);
    }
    
    // Left-Right case
    if (bf > 1 && balanceFactor(node->leftChild) < 0) {
        node->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);
    }
    
    // Right-Right case
    if (bf < -1 && balanceFactor(node->rightChild) <= 0) {
        return rotateLeft(node);
    }
    
    // Right-Left case
    if (bf < -1 && balanceFactor(node->rightChild) > 0) {
        node->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    }
    
    return node;
}

// Insert
template <class T>
typename AVL<T>::Node* AVL<T>::insertNode(Node* node, const T& value) {
    if (node == nullptr) {
        size++;
        return new Node(value);
    }
    
    if (value < node->value) {
        node->leftChild = insertNode(node->leftChild, value);
    } else if (value > node->value) {
        node->rightChild = insertNode(node->rightChild, value);
    } else {
        return node; // Duplicate values not allowed
    }
    
    return balance(node);
}

// Find minimum node
template <class T>
typename AVL<T>::Node* AVL<T>::findMin(Node* node) const {
    while (node->leftChild != nullptr) {
        node = node->leftChild;
    }
    return node;
}

// Remove
template <class T>
typename AVL<T>::Node* AVL<T>::removeNode(Node* node, const T& value) {
    if (node == nullptr) {
        return nullptr;
    }
    
    if (value < node->value) {
        node->leftChild = removeNode(node->leftChild, value);
    } else if (value > node->value) {
        node->rightChild = removeNode(node->rightChild, value);
    } else {
        // Node to be deleted found
        if (node->leftChild == nullptr || node->rightChild == nullptr) {
            Node* temp = node->leftChild ? node->leftChild : node->rightChild;
            
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            
            delete temp;
            size--;
        } else {
            Node* temp = findMin(node->rightChild);
            node->value = temp->value;
            node->rightChild = removeNode(node->rightChild, temp->value);
        }
    }
    
    if (node == nullptr) {
        return nullptr;
    }
    
    return balance(node);
}

// Search
template <class T>
bool AVL<T>::search(const T& value) const {
    Node* current = root;
    while (current != nullptr) {
        if (value == current->value) {
            return true;
        } else if (value < current->value) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
    }
    return false;
}

// Search node recursivo
template <class T>
typename AVL<T>::Node* AVL<T>::searchNode(Node* node, const T& value) const {
    if (node == nullptr) {
        return nullptr;
    }
    
    if (value == node->value) {
        return node;
    } else if (value < node->value) {
        return searchNode(node->leftChild, value);
    } else {
        return searchNode(node->rightChild, value);
    }
}

// SearchPtr público (não-const)
template <class T>
T* AVL<T>::searchPtr(const T& value) {
    Node* node = searchNode(root, value);
    return (node != nullptr) ? &(node->value) : nullptr;
}

// SearchPtr público (const)
template <class T>
const T* AVL<T>::searchPtr(const T& value) const {
    Node* node = searchNode(root, value);
    return (node != nullptr) ? &(node->value) : nullptr;
}

// Destroy tree
template <class T>
void AVL<T>::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->leftChild);
        destroyTree(node->rightChild);
        delete node;
    }
}

// Copy tree
template <class T>
void AVL<T>::copyTree(Node* node) {
    if (node != nullptr) {
        insert(node->value);
        copyTree(node->leftChild);
        copyTree(node->rightChild);
    }
}

// Public methods

template <class T>
int AVL<T>::get_size() const {
    return size;
}

template <class T>
int AVL<T>::get_height() const {
    return getHeight(root);
}

template <class T>
void AVL<T>::insert(const T& value) {
    root = insertNode(root, value);
}

template <class T>
void AVL<T>::remove(const T& value) {
    root = removeNode(root, value);
}

template <class T>
void AVL<T>::clear() {
    destroyTree(root);
    root = nullptr;
    size = 0;
}

template <class T>
AVL<T>& AVL<T>::operator=(const AVL<T>& other) {
    if (this != &other) {
        clear();
        if (other.root != nullptr) {
            copyTree(other.root);
        }
    }
    return *this;
}

#endif