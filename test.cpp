#include "BST.hpp"
#include <cstring>
#define SIZE 15

int main(){
	std::vector<int> testarray(SIZE);
	int basearray[] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
	
	memcpy(testarray.data(),basearray , SIZE*sizeof(int));
	
	for(int i =0; i< testarray.size(); ++i){
		std::cout << testarray[i] << "\n";
	}
	
	BST<int> tree;
	
	tree.addNodes(testarray);
	tree.print();
	std::cout << "Tree size = " << tree.size() << "\n";
	
	std::cout <<" k lowest " << tree.kthSmallest(1) << "\n";
	

    return 0;
}
