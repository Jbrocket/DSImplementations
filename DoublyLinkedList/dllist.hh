#ifndef DLLIST_H
#define DLLIST_H

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
        sllist();
        virtual ~sllist();

        int insertRight(const_reference_type data);
        int insertLeft(const_reference_type data);
        void printList();
        int size();
        void removeNodeByValue(const_reference_type data);
        void removeNodeByIndex(int pos);
        void insertAt(int pos, const_reference_type data);
};

#endif