
template<class T>
class Node {
    private:
        T data;
        Node * parent, * left_child, * right_child;

    public:

        Node(){
            parent = left_child = right_child = NULL;
        }

        Node(T input_data){
            data = input_data;
            parent = left_child = right_child = NULL;
        }

        Node(T input, Node * parent_node){
            data = input;
            parent = parent_node;
            left_child = right_child = NULL;
        }

        Node(T input, Node * parent_node, Node * left_node, Node * right_node){
            data = input;
            parent = parent_node;
            left_child = right_node;
            right_child = left_node;
        }

        ~Node(){
            if(parent != NULL){
                delete parent;
            }
            if(left_child != NULL){
                delete left_child;
            }
            if(right_child != NULL){
                delete right_child;
            }
        }

        T getData(){
            return data;
        }

        void setData(T input_data){
            data = input_data;
        }

        void setLeftNode(Node * input){
            left_child = input;
        }

        void setRightNode(Node * input){
            right_child = input;
        }

        void setParentNode(Node * input){
            parent = input;
        }

        Node * getParentNode(){
            return parent;
        }

        Node * getRightNode(){
            return right_child;
        }

        Node * getLeftNode(){
            return left_child;
        }
};
