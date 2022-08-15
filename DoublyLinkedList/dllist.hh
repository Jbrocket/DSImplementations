#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>

template <typename T>
struct node{
    T data;
    node *next;
    node *prev;
};

template <typename T>
class dllist {
    typedef T value_type;
    typedef T &reference_type;
    typedef T const& const_reference_type;
    typedef T* pointer_type;
    typedef T const* const_pointer_type;
    typedef node<T> node_type;
    typedef node_type* node_pointer;

    private:
        node_pointer tail;
        node_pointer head;
        int length;
    public:
        dllist();
        virtual ~dllist();

        void insertRight(const_reference_type data);
        void insertLeft(const_reference_type data);
        void printList();
        void printReverse();
        int size();
        void reverseList();
        void removeNodeByValue(const_reference_type data);
        void removeNodeByIndex(int pos);
        void insertAt(int pos, const_reference_type data);
};

#endif