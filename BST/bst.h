#ifndef BST_H
#define BST_H

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
        void preOrder();
        void inOrder();
        void postOrder();
        void levelOrder();
        int height();
        void removeNodeByValue(const_reference_type data);
};

#endif