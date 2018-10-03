
//default construtor
template<typename T>
BST<T>::BST(){} 

// inits root's data
template<typename T>
BST<T>::BST(T data_in){
    root.data = data_in;
}  

// adds new node in right spot
template<typename T>
void BST<T>::addNode(T data_in){
	node<T> * tmp = search(data_in);
	
	if(data_in > tmp->data){
		tmp->right_child = new node<T>(data_in);
		tmp->right_child->parent = tmp;
	}
	else if(data_in < tmp->data){
		tmp->left_child = new node<T>(data_in);
		tmp->left_child->parent = tmp;
	}
} 

// deletes node with data matching key
template<typename T>
void BST<T>::deleteNode(T key){
	if(root.right_child !=NULL){
		delete root.right_child;
	}
	if(root.left_child !=NULL){
		delete root.left_child;
	}
}

// returns node * with data mathing key
template<typename T>
node<T> * BST<T>::search(T key){
	node<T> * tmp = &root;
	while(tmp != NULL){
		// if match is found
		if(key ==tmp->data){
			return tmp;
			
		// no match, but data is higher that node's data
		} else if(key > tmp->data ){
			if(tmp->right_child == NULL){
				return tmp;
			}
			tmp = tmp->right_child;
		
		// no match. data is lower than node's data
		} else if(key < tmp->data) {
			if(tmp->left_child == NULL){
				return tmp;
			}
			tmp = tmp->left_child;
		}
	}
	std::cerr << "No match found, returning NULL\n";
	return tmp;
}

// print node and child data recursively
template <class T>
void BST<T>::recursivePrint(node<T> * current){
	if(current == &root){
		std::cout << "Root Data: " << current->data << "  ";
	
	} else {
		std::cout << "Node Data: " << current->data << "  ";
	}

	if(current->left_child != NULL){
		std::cout << "Left Child Data: " << current->left_child->data << "  ";
	}
	if(current->right_child != NULL){
		std::cout << "Right Child Data: " << current->right_child->data << "  ";
	}
	std::cout << "\n";

	if(current->left_child != NULL){
		recursivePrint(current->left_child);
	}
	if(current->right_child != NULL){
		recursivePrint(current->right_child);
	}
}

// plan: preorder recursive function that prints of each node and its children
template<typename T> 
void BST<T>::print(){
	recursivePrint(&root);
}

// add data from the array in the range specified
template <typename T>
void BST<T>::recursiveAddNodes(std::vector<T> input_data, int start, int end){								
	if(start == end){
		addNode(input_data[start]);
		
	} else if (start == end - 1){
		addNode(input_data[start]);
		addNode(input_data[end]);
		
	} else {
		
		int median = (end-start)/2 + start;
		
		addNode(input_data[median]);
		recursiveAddNodes(input_data, start, median - 1);
		recursiveAddNodes(input_data, median + 1, end);
	}
}


// add nodes for all elements in vector
template<typename T>
void BST<T>::addNodes(std::vector<T> input){
	// get median first time, make that a node/put in root
	// then pass new vector to addNodes and keep going recursively
	int median = input.size()/2;
	root.data = input[median];
	recursiveAddNodes(input, 0, median - 1);
	recursiveAddNodes(input, median+1, input.size() - 1);	 
}

// finds the number of children on a node
template<typename T>
int children(node<T> * parent){
	
	int count = 0;
	if(parent->left_child != NULL){
		count += 1 + children(parent->left_child);
	} 
	if(parent->right_child != NULL){
		count += 1 + children(parent->right_child);
	}
	return count;	
}

// return number of nodes on tree
template<typename T>
int BST<T>::size(){
	int count = 1 + children(&root);
	return count;
}

//finds the kth Smallest number on the tree
template <typename T>
T BST<T>::kthSmallest(int k){
	
	if(k > size()){
		std::cerr << "K is greater than tree size. Returning root data.\n";
		return root.data;
	}

	std::stack<node<T> *> node_stack;
	node<T> * tmp = &root;
	int traversals = 0;

	while (traversals < k &&( tmp != NULL || node_stack.empty() == false)){

		while(tmp != NULL){
			node_stack.push(tmp);
			tmp = tmp->left_child;
		}

		tmp = node_stack.top();
		node_stack.pop();

		++traversals;   // keep track of the nodes that have been cycled through

		if(traversals < k){
			tmp = tmp->right_child;			
		}
	}

	return tmp->data;
}
