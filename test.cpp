#include "BST.hpp"
#include <cstring>
#include <cctype>
#include <cstdlib>

#define SIZE 15

// check if the arg is a positive integer
int getIntFromArgv(char * argv){
	if(isdigit(argv[0])){
		return std::atoi(argv);
	}
	return -1;
}

int main(int argc, char ** argv){

	// check for number of args
	if(argc < 2){
		std::cout << "Usage: " << argv[0] << " kthsmallest\n";
		return 0;
	}

	// see if k is a valid value
	int kth = getIntFromArgv(argv[1]);
	if(kth == -1 || kth < 1){
		std::cout << "Please input a number above 0.\n";
		return 0;
	}

	// init array as vector
	int basearray[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
	std::vector<int> testarray(basearray, basearray + SIZE);

	BST<int> tree;

	// add nodes to tree
	tree.addNodes(testarray);

	// print out tree data
	tree.print();

	// print out kth lowest item
	std::cout <<"Kth lowest " << tree.kthSmallest(kth) << std::endl;	

    return 0;
}
