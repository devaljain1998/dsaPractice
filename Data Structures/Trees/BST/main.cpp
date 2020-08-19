#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class BinarySearchTreerootNode{
    public:
    int value;
    BinarySearchTreerootNode *left=NULL, *right=NULL;

    BinarySearchTreerootNode() : value(0) {}
    BinarySearchTreerootNode(int value) : value(value) {}
};

class BinarySearchTree{
    BinarySearchTreerootNode* root = NULL;
    public:
    //Constructors:
        BinarySearchTree() { this->root = new BinarySearchTreerootNode(); }
        BinarySearchTree(int value) { this->root = new BinarySearchTreerootNode(value); }
        //BinarySearchTree(vector <int> &a) {}
        //BinarySearchTree(int value, BinarySearchTree a) {}
        //BinarySearchTree(int value, BinarySearchTree a, BinarySearchTree b) {}

    //Util Methods:
        void displayInOrder(){
            //Left, Root, Right
            BinarySearchTreerootNode node = *(this->root);
            stack <BinarySearchTreerootNode> BSTNodeStack(node);
            while(BSTNodeStack.empty() == false){
                BinarySearchTreerootNode currentNode = BSTNodeStack.top();
                BSTNodeStack.pop();

                while(currentNode){
                    if(currentNode.left->left == NULL){
                        cout << currentNode.left->value << " " << currentNode.value << " ";

                        if(currentNode.right != NULL){
                            cout << currentNode.right->value;
                            if(currentNode.right->right != NULL){
                                BSTNodeStack.push(*(currentNode.right->right));
                            }
                        }
                        
                    }
                }
            }
        }

        void displayPreOrder();
        void displayPostOrder();

    //CRUD Utils:

        bool insert(int value){
            BinarySearchTreerootNode *rootNode = this->root, newNode(value);

            while(rootNode){
                while(value <= rootNode->value) { 
                    if(rootNode->left)
                        rootNode = rootNode->left; 
                    else
                    {
                        rootNode->left = &newNode;
                        return true;
                    }
                }
                while(value > rootNode->value) { 
                    if(rootNode->right)
                        rootNode = rootNode->right; 
                    else
                    {
                        rootNode->right = &newNode;
                        return true;
                    }
                }
            }
            return false;
        }

    //Search:
        //Can also be modified to return position of the node
        bool search(int value){
            BinarySearchTreerootNode node = *(this->root);
            bool found = false;

            while(node){
                if(value == node.value) { return true; }
                else if(value <= node.value) { node = node.left; }
                else { node = node.right; }
            }

            return false;
        }
};

int main(){
    cout << "Working" << endl;

    return 0;
}