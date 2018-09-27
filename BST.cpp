
//default construtor
template<typename T>
BST::BST(){
    root();
} 

// inits root's data
template<typename T>
BST::BST(T data_in){
    root(data_in);
}  

// destructor
template<typename T>
BST::~BST(){

}

// adds new node in right spot
template<typename T>
void BST::addNode(T data_in){} 

// deletes node with data matching key
template<typename T>
void BST::deleteNode(T key){}

// returns node * with data mathing key
template<typename T> // TODO 1st
node<T> * BST::search(T key){} 

// prints tree
template<typename T> 
void BST::print(){}

// add nodes for all elements in vector
template<typename T>
void BST::addNodes(std::vector<T> input){}
