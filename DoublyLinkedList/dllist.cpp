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
    std::cout << "Deconstructor Called" << std::endl;
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
std::string dllist<T>::printList(){
    node_pointer cur = this->head;
    std::string ret = "";

    if(!cur){
        return "[]";
    }

    ret.append("[" + std::to_string(cur->data));
    cur = cur->next;
    while(cur != NULL){
        ret.append(", " + std::to_string(cur->data));
        cur = cur->next;
    }
    ret.append("]");

    return ret;
}

template <typename T>
std::string dllist<T>::printReverse(){
    node_pointer cur = this->tail;
    std::string ret = "";

    if(!cur){
        return "[]";
    }

    ret.append("[" + std::to_string(cur->data));
    cur = cur->prev;
    while(cur != NULL){
        ret.append(", " + std::to_string(cur->data));
        cur = cur->prev;
    }
    ret.append("]");

    return ret;
}

template <typename T>
int dllist<T>::size(){
    return this->length;
}

template <typename T>
void dllist<T>::reverseList(){
    if(!this->head)
        return;

    node_pointer prev = NULL;
    node_pointer cur = this->head;
    node_pointer next = this->head->next;

    this->tail = this->head;

    while(cur){
        cur->next = prev;
        cur->prev = next;
        prev = cur;
        cur = next;
        if(next)
            next = next->next;
    }
    this->head = prev;
    
    return;
}

template <typename T>
void dllist<T>::insertAt(int pos, const_reference_type data){
    if(pos < 0 || pos > this->length){
        std::cout << "Choose a valid index" << std::endl;
        return;
    }

    node_type *ptr = new node_type();
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    this->length++;

    if(pos == 0){
        ptr->next = this->head;
        this->head = ptr;
        if(ptr->next)
            ptr->next->prev = ptr;
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
        temp->next->prev = temp;
        this->tail = ptr;
        return;
    }

    ptr->next = temp->next;
    temp->next->prev = ptr;
    temp->next = ptr;
    ptr->prev = temp;
    return;
}

template <typename T>
void dllist<T>::removeNodeByValue(const_reference_type value){
    if(!this->head){
        return;
    }
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
            this->head->prev = NULL;
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
        dlt->next->prev = temp;
        delete dlt;
    }

    return;
}

template <typename T>
void dllist<T>::removeNodeByIndex(int pos){
    if(pos < 0 || pos > this->length - 1){
        std::cout << "Enter a valid index" << std::endl;
        return;
    }
    if(!this->head){
        return;
    }

    int curPos = 0;
    node_type *temp = this->head;
    while(curPos < pos - 1){
        curPos++;
        temp = temp->next;
    }

    this->length--;
    if(!temp->next){
        this->head = NULL;
        this->tail = NULL;
        delete temp;
    }
    else if(pos == 0){
        this->head = temp->next;
        this->head->prev = NULL;
        delete temp;
    }
    else if(!temp->next->next){
        node_type *dlt = temp->next;
        this->tail = temp;
        temp->next = NULL;
        delete dlt;
    }
    else{
        node_type *dlt = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        delete dlt;
    }

    return;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const dllist<T>& list){


    os << list.head->data;

    return os;
}