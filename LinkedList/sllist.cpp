#include <iostream>
#include <string>
#include "sllist.h"

template <typename T>
sllist<T>::sllist(){
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

template <typename T>
sllist<T>::~sllist(){
    // std::cout << "\n" << "destructor called" << std::endl;
    if (this->head){
        node_type *ptr = this->head;
        node_type *temp = ptr;
        while (temp){
            temp = temp->next;
            delete ptr;
            ptr = temp;
        }
    }
}

template <typename T>
int sllist<T>::insertRight(const_reference_type data){
    this->length += 1;
    node_type *ptr = new node_type();

    ptr->data = data;
    ptr->next = NULL;

    if (!this->head)
        this->head = ptr;
    else
        this->tail->next = ptr;
    this->tail = ptr;

    return 0;
}

template <typename T>
int sllist<T>::insertLeft(const_reference_type data){
    this->length += 1;
    node_type *ptr = new node_type();
    
    ptr->data = data;

    if (!this->head)
        ptr->next = NULL;
    else
        ptr->next = this->head;
    
    this->head = ptr;

    return 0;
}

template <typename T>
void sllist<T>::printList(){
    if (!this->head){
        std::cout << "No nodes in list" << std::endl;
        return;
    }

    node_type *ptr = this->head;
    std::cout << "\nCurrent List: ";
    do{
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    } while( ptr != NULL);
    std::cout << "\n" << "\n";
    return;
}

template <typename T>
int sllist<T>::size(){
    return length;
}

template <typename T>
void sllist<T>::insertAt(int pos, const_reference_type data){
    if(pos < 0 || pos > this->length){
        std::cout << "Choose a valid index" << std::endl;
        return;
    }

    node_type *ptr = new node_type();
    ptr->data = data;
    ptr->next = NULL;
    this->length++;

    if(pos == 0){
        ptr->next = this->head;
        this->head = ptr;
        return;
    }

    int curPos = 0;
    node_type *temp = this->head;
    while(curPos < pos - 1){
        curPos++;
        temp = temp->next;
    }

    if(!temp->next){
        temp->next = ptr;
        this->tail = ptr;
        return;
    }

    ptr->next = temp->next;
    temp->next = ptr;
    return;
}

template <typename T>
void sllist<T>::removeNodeByValue(const_reference_type value){
    node_type *temp = this->head;

    while(temp->data != value && temp->next != NULL && temp->next->data != value){
        temp = temp->next;
    }

    if(temp->data == value){
        this->length--;
        if(!temp->next){
            this->head = NULL;
            this->tail = NULL;
        }
        else
            this->head = temp->next;
        delete temp;
        return;
    }
    if(temp->next == NULL){
        std::cout << "Value does not exist" << std::endl;
        return;
    }

    this->length--;
    if(temp->next->next == NULL){
        delete temp->next;
        temp->next = NULL;
        this->tail = temp;
    }
    else{
        node_type *dlt = temp->next;
        temp->next = dlt->next;
        delete dlt;
    }

    return;
}

template <typename T>
void sllist<T>::removeNodeByIndex(int pos){

    return;
}