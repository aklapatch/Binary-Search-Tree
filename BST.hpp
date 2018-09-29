#ifndef BST_HPP
#define BST_HPP

#include <vector>
#include <iostream>

// node structure for tree
template<typename T>
struct node {

    // key data and other node pointers
    T data;
    node * parent, * left_child, * right_child;

    // default constructor, inits all pointers as NULL
    node(){
        parent = left_child = right_child = NULL;
    }

    // inits pointers as NULL and assigns data member to input arg
    node(T data_in){
        data = data_in;
        parent = left_child = right_child = NULL;
    }

    // assigns args to internal data members
    node(T data_in, node * parent_in){
        data = data_in;
        parent = parent_in;
        left_child = NULL;
        right_child = NULL;
    }

    // sets pointers to input arguments
    node(node * parent_in, node * left_child_in, node * right_child_in){
        parent = parent_in;
        left_child = left_child_in;
        right_child = right_child_in;
    }

    // delete allocated memory
    ~node(){
        if(left_child != NULL){
            delete left_child;
        }
        if(right_child != NULL){
            delete right_child;
        }
    }
};

template<typename T>
class BST {

    private:
        node<T> root;

    public:
        BST(); // default 

        BST(T data_in);  // inits root's data

        ~BST(); // destructor

        void addNode(T data_in); // adds new node in right spot

        void deleteNode(T key); // deletes node with data matching key

        node<T> * search(T key); // returns node * with data mathing key

        void print(); // prints tree

        void addNodes(std::vector<T> input); // add nodes for elements in vector
		
		// internal function to add nodes recursively
		void recursiveAddNodes(	std::vector<T> input_data, 
							int start,
							int end);
		int size();
		
		T kthSmallest(int k);
};

#include "BST.cpp"

#endif // BST_HPP
