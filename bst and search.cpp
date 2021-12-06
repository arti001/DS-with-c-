#include <iostream>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* generateNode(int data){
    BstNode* node = new BstNode();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BstNode* Insert(BstNode* root, int val){
    if (root== NULL) {
        root = generateNode(val);
    }
    else if (val <= root->data){
        root->left = Insert(root->left, val);
    }
    else{
        root->right = Insert(root->right, val);
    }
    return root;
}

bool Search(BstNode* root, int data){
    if (root==NULL) {
        return false;
        
    } else {
        cout <<"Root data- "<< root->data << "Value to search- " << data <<endl;
        if (root-> data == data) {
            cout << root->data<< "entering equals"<< endl; 
            return true;
            
        }
        else if (root->data < data) {
            cout << root->data<< "enterig root->data < data"<< endl; 
            return Search (root->right,data);
            
        }
        else {
            cout << root->data<< "enterig root->data > data"<< endl; 
            return Search (root->left,data);
        }
            
    }
   
}
int main() {
// your code goes here
BstNode* root = NULL;
root = Insert (root, 67);
root = Insert (root, 6);
root = Insert (root,17);
root = Insert (root, 58);
root = Insert (root, 70);
root = Insert (root, 65);

int num;
std::cout << "enter number to search" << std::endl;
cin>> num;
if (Search(root, num)== true) cout<<num << " - Found"<<endl;
else cout << num << " - Not Found"<< endl;

return 0;
}