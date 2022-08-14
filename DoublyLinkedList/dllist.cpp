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

