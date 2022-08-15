#include "dllist.hh"

template <typename T>
dllist<T>::dllist(){
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template <typename T>
dllist<T>::~dllist(){
    if(this->head){
        node_pointer tmp;
        node_pointer cur = this->head;
        while(cur){
            tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
}

template <typename T>
void dllist<T>::insertRight(const_reference_type data){
    this->length += 1;
    node_pointer node = new node_type();
    node->data = data;
    node->next = NULL;

    if(!this->head){
        this->head = node;
        this->head->prev = NULL;
    }
    else{
        node->prev = this->tail;
        this->tail->next = node;
    }
    this->tail = node;

    return;
}

template <typename T>
void dllist<T>::insertLeft(const_reference_type data){
    this->length += 1;
    node_pointer node = new node_type();
    node->data = data;
    node->prev = NULL;

    if(!this->head){
        node->next = NULL;
        this->tail = node;
    }
    else{
        node->next = this->head;
        this->head->prev = node;
    }
    this->head = node;

    return;
}

template <typename T>
void dllist<T>::printList(){
    node_pointer cur = this->head;

    if(!cur){
        std::cout << "No nodes to print" << std::endl;
        return;
    }

    while(cur != NULL){
        std::cout << " " << cur->data;
        cur = cur->next;
    }

    return;
}

template <typename T>
void dllist<T>::printReverse(){
    node_pointer cur = this->tail;

    if(!cur){
        std::cout << "No nodes to print" << std::endl;
        return;
    }

    while(cur != NULL){
        std::cout << " " << cur->data;
        cur = cur->prev;
    }

    return;
}

template <typename T>
int dllist<T>::size(){
    return this->length;
}