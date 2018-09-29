
//default construtor
template<typename T>
BST<T>::BST(){} 

// inits root's data
template<typename T>
BST<T>::BST(T data_in){
    root.data = data_in;
}  

// destructor
template<typename T>
BST<T>::~BST(){
	if(root.left_child != NULL){
		delete root.left_child;
	}
	if(root.right_child != NULL){
		delete root.right_child;
	}
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
template<typename T> // TODO 1st
node<T> * BST<T>::search(T key){
	node<T> * tmp = &root;
	while(tmp != NULL){
		if(key ==tmp->data){
			return tmp;
			
		} else if(key > tmp->data ){
			if(tmp->right_child == NULL){
				return tmp;
			}
			tmp = tmp->right_child;
			
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
template <typename T>
void fancyPrint(node<T> * input_node, int node_number){
	
}

void printSpace(int num_spaces){
	for(int i =0; i < num_spaces; ++i){
		std::cout << " ";
	}
}

// prints using a stray value for each node
template<typename T> 
void strayPrint(node<T> * current, int depth, int stray){
	int scale = 3;
}

// prints tree
template<typename T> 
void BST<T>::print(){
	// prints left and right node first, then goes down another level
	// and prints the information necessary
	// preorder traversal, prints the roots of the node
	strayPrint(&root, 0, size()/2);
}

template <typename T>
void BST<T>::recursiveAddNodes(std::vector<T> input_data, 
							int start,
							int end){								
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

template <typename T>
T BST<T>::kthSmallest(int k){
	// go to least node, then second least, until you have traversed k times.
	node<T> * tmp = &root;
	// go to least node
	while(tmp->left_child != NULL){
		tmp = tmp->left_child;
	}
	
	// traverse the correct number of times
	int i = 0;
	while(++i < 1){
		if(tmp->right_child == NULL){
			tmp = tmp->parent;
		} else {
			tmp = tmp->right_child;
		}
	}
	
	return tmp->data;
}


