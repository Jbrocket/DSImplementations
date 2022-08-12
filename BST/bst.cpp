#include "bst.h"

template <typename T>
bst<T>::bst() {
    this->root = NULL;
}

template <typename T>
bst<T>::~bst(){
    std::queue<node_type> queue;
}