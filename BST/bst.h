#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>

template <typename T>
struct node{
    T data;
    node *left;
    node *right;
};

template <typename T>
class bst{
    typedef T value_type;
    typedef T &reference_type;
    typedef T const& const_reference_type;
    typedef T* pointer_type;
    typedef T const* const_pointer_type;
    typedef node<T> node_type;
    typedef node_type* node_pointer;

    private:
        node_pointer root;
    public:
        bst();
        virtual ~bst();

        void insertNode(const_reference_type data);

        // Standard tree traversals
        void preOrder(node_pointer node);
        void inOrder(node_pointer node);
        void postOrder(node_pointer node);

        // Overloaded to call the function above with this->root
        void preOrder();
        void inOrder();
        void postOrder();

        // Used to deconstruct
        void postOrderDelete(node_pointer node);

        // BFS related searches
        void levelOrder();
        int height();
        void removeNodeByValue(const_reference_type data);
};

#endif