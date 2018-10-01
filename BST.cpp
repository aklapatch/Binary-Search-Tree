
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

void printSpace(int num_spaces){
	for(int i =0; i < num_spaces; ++i){
		std::cout << " ";
	}
}

template <typename T> 
struct coords {
	T data;
	int depth;
	int stray;

	coords(T in_dat, int in_dep, int in_str){
		data = in_dat;
		depth = in_dep;
		stray = in_str;
	}

	coords(){}
};

template <typename T>
int leastIndex(std::vector<coords<T>>& input, int start){
	int ret = start;
	for(int i = start + 1 ; i < input.size(); ++i){
		if(input[i].stray < input[ret].stray){
			ret = i;
		}
	}
	return ret;
}

//uses bucket sort to sort the structs
template <typename T>
void coordsSort(std::vector<coords<T>>& input){
	// using selection sort
	for (int i=0; i < input.size(); ++i){
		int least = leastIndex(input,i);
		std::swap(input[i], input[least]);
	}

	for (int i=0; i < input.size(); ++i){
		//std::cout << input[i].stray << " ";
		//std::cout << "\n";
	}
     
    
} 


template <class T>
std::vector<coords<T>> getVector(node<T> * input, std::vector<coords<T>> input_vector, int depth, int stray){
	
	// store points for node 
	coords<T> tmp(input->data, depth, stray);

	// store data
	input_vector.push_back(tmp);

	// possibly travel to left node
	if(input->left_child != NULL){
		input_vector = getVector(input->left_child, input_vector, depth + 1, stray - 1); 
	}

	// possibly travel to right node
	if(input->right_child != NULL){
		input_vector = getVector(input->right_child, input_vector, depth + 1, stray + 1); 
	}
	
	return input_vector;
}



// current plan, recursive, change depth and stray value when going down or left or right 
// vector gets passed to recursive function that returns proper vector if necessary
// prints tree
template<typename T> 
void BST<T>::print(){
	// get all of the stats of the data pairs.
	std::vector<coords<T>> array;
			
	array = getVector(&root, array, 0 , 0);
	
	// separate the different depths.
	int depth = 0;
	std::vector<coords<T>> tmp_vec;
	int number= 0;
	while(array.size() > number ){
		
		for(int i =0; i < array.size(); ++i){
			if(array[i].depth == depth){
				tmp_vec.push_back(array[i]);
				++number;
			}
		}
		++depth;
		
		coordsSort(tmp_vec);

		//plan. divide up the spaces depending on the number
		// of items in the tree. then figure out the spacing 
		//by dividing the size of the vector by the size of the tree.
		
		int spacing = (number == 1)? 0 : size() + size()%2 - 3*depth;
		int indent = size() - 1 - 4*depth;
		std::cout << "Nodes at depth " << depth << ":\n";
		for(int i = 0; i < tmp_vec.size(); ++i){
			
			std::cout << tmp_vec[i].data << "  ";
			//printSpace(spacing);
		}
		std::cout << std::endl;

		tmp_vec.resize(0);
	}
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

		++traversals;

		if(traversals < k){
			tmp = tmp->right_child;			
		}
	}

	return tmp->data;
}