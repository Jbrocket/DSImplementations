#include "bst.h"
#include <iostream>

template <typename T>
bst<T>::bst() {
    this->root = NULL;
}

template <typename T>
bst<T>::~bst(){
    postOrderDelete(this->root);
}

template <typename T>
void bst<T>::insertNode(const_reference_type data){
    node_type *currNode = this->root;

    node_type *insert = new node_type();
    insert->data = data;

    if(!currNode){
        this->root = insert;
        return;
    }

    while(true){
        if(currNode->data > insert->data){
            if(!currNode->left){
                currNode->left = insert;
                return;
            }
            currNode = currNode->left;
        }
        else if(currNode->data < insert->data){
            if(!currNode->right){
                currNode->right = insert;
                return;
            }
            currNode = currNode->right;
        }
        else{
            std::cout << "Data value alread exists" << std::endl;
            return;
        }
    }

    return;
}

template <typename T>
void bst<T>::postOrderDelete(node_pointer node){
    if(!node){
        return;
    }
    postOrderDelete(node->left);
    postOrderDelete(node->right);
    delete node;
    return;
}

template <typename T>
void bst<T>::postOrder(node_pointer node){
    if(!node){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << " " << node->data;
    return;
}

template <typename T>
void bst<T>::preOrder(node_pointer node){
    if(!node){
        return;
    }

    std::cout << " " << node->data;
    preOrder(node->left);
    preOrder(node->right);
    return;
}

template <typename T>
void bst<T>::inOrder(node_pointer node){
    if(!node){
        return;
    }

    inOrder(node->left);
    std::cout << " " << node->data;
    inOrder(node->right);
    return;
}

template <typename T>
void bst<T>::preOrder(){
    preOrder(this->root);
    return;
}

template <typename T>
void bst<T>::inOrder(){
    inOrder(this->root);
    return;
}

template <typename T>
void bst<T>::postOrder(){
    postOrder(this->root);
    return;
}