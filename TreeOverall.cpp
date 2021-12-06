#include <iostream>
#include<queue>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};
std::queue<BstNode*> Q ;

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
        //cout <<"Root data- "<< root->data << "Value to search- " << data <<endl;
        if (root-> data == data) {
            //cout << root->data<< "entering equals"<< endl; 
            return true;
            
        }
        else if (root->data < data) {
           // cout << root->data<< "enterig root->data < data"<< endl; 
            return Search (root->right,data);
            
        }
        else {
            //cout << root->data<< "enterig root->data > data"<< endl; 
            return Search (root->left,data);
        }
            
    }
   
}

bool Replace (BstNode* root, int data){
    if (root==NULL) {
        return false;
        
    } else {
        if (root-> data == data) {
            root->data = 123;
            return true;
            
        }
        else if (root->data < data) {
           // cout << root->data<< "enterig root->data < data"<< endl; 
            return Replace (root->right,data);
            
        }
        else {
            //cout << root->data<< "enterig root->data > data"<< endl; 
            return Replace (root->left,data);
        }
            
    }
   
}

void printTree(BstNode* root){
    if (root!=NULL){
        cout << root->data<< "  ";
        printTree(root->left);
        printTree(root->right);
    }
    return;
}

int minNum(BstNode* head){
    if (head == NULL) {
        cout << "tree is empty"<< endl;
        return -1;
    }
    while (head->left!= NULL){
        head= head->left;
    }
    return head->data;
}

int minNumRecur(BstNode* head){
    if (head==NULL) {
        cout<< "Tree is empty"<< endl;
    }
    while (head->left != NULL){
        return minNumRecur(head->left);
    }
    return head->data;
}

int getHeight(BstNode* root){
    if (root == NULL){
        return -1;
    }
    int rightTree = getHeight(root->right);
    int leftTree =  getHeight(root->left);
    return (max(rightTree,leftTree)+1);
}

void printAtGivenLevel(BstNode* root, int level){
    if(root==NULL) return;
    if (level==1) 
        cout<<root->data<< "  ";
    else if (level > 1 ) {
        printAtGivenLevel (root->left, level-1);
        printAtGivenLevel (root->right, level-1);
    }
    
}

void printTreeinLevel(BstNode* root){
    int height = getHeight(root);
    for (int i=1; i<=(height+1);i++){
       // cout << "i= " << i << "and height is "<< height << endl;
        printAtGivenLevel(root,i);
        cout<<endl;
    }
}

void printInorder(BstNode* data){
    if (data == NULL) return;
    else {
        printInorder (data->left);
        cout<< data-> data<< "   ";
        printInorder (data->right);
        }
}

void printPreOrder(BstNode* root){
    if (root == NULL) return;
    else {
        cout << root->data << "  ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(BstNode* root){
    if (root == NULL) return;
    else {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << "  ";
        
    }
}

void printLevelWise(BstNode* head){
    if (head == NULL) return;
    Q.push(head);
    while(!Q.empty()){
    if (Q.front()->left)    Q.push(Q.front()->left);
    if (Q.front()->right)    Q.push(Q.front()->right);
    cout<< Q.front()->data <<" ";
    Q.pop();
    }
}

void printLeafNode(BstNode* root){
    if(root==NULL) return;
    else if (root->left==NULL && root->right==NULL){
        cout<< root->data<<"    ";
    }
    printLeafNode(root->left);
    printLeafNode(root->right);
}

void printSingleChild(BstNode* Node){
    if(Node == NULL) return;
    else if ((Node->left==NULL && Node->right !=NULL)|| (Node->right== NULL && Node->left!=NULL)){
        cout<<Node->data<< "   ";
    }
    printSingleChild(Node->right);
    printSingleChild(Node->left);
}

bool IsBinaryTree(BstNode* root){
    if (root){
        if (root->left && root->right)
            return (root->left->data <= root->data && root->right->data > root->data) && 
            IsBinaryTree(root->left) && 
            IsBinaryTree(root->right);
        else if (root->left)
            return (root->left->data <= root->data) && IsBinaryTree(root->left);
        else if (root->right)
            return(root->right->data > root->data) && IsBinaryTree(root-> right);
        else 
            return true;
    }
    return true;
}

int main() {
// insert tree
BstNode* root = NULL;
root = Insert (root, 67); root = Insert (root, 6); root = Insert (root,17);
root = Insert (root, 58); root = Insert (root, 70); root = Insert (root, 65);

//Search in tree
int num;
std::cout << "enter number to search" << std::endl;
cin>> num;
if (Search(root, num)== true) cout<<num << " - Found"<<endl;
else cout << num << " - Not Found"<< endl;
cout<< "-------------------------------------------"<<endl;

//print tree
cout<< "Printing Tree"<< endl;
printTree (root);
cout<< "-------------------------------------------"<<endl;

// printing min in tree
int min = minNum(root);
cout<< "Minimum number is "<< min << endl;
cout<< "-------------------------------------------"<<endl;
int minRecr = minNumRecur(root);
cout<< "Minimum number through Recursion is "<< minRecr << endl;
cout<< "-------------------------------------------"<<endl;

// finding height of tree
int height = getHeight(root);
cout<<"Height of tree is "<< height << endl;

cout<< "-------------------------------------------"<<endl;
cout<< "Printing tree inorder "<< endl;
printInorder(root);

cout<< "-------------------------------------------"<<endl;
printLevelWise(root);

cout<< "-------------------------------------------"<<endl;
cout<< "Printing tree level wise "<< endl;
printTreeinLevel(root);

cout<< "-------------------------------------------"<<endl;
int levelToPrint;
cout<<"Enter the level to print"<< endl;
cin>> levelToPrint;
printAtGivenLevel(root,levelToPrint);
cout<<endl;
cout<< "------------printing leaf Node --------------------"<<endl;

printLeafNode(root);
cout<<endl;
cout<< "-----------------printing Single Child Node----------------------------------"<<endl;

printSingleChild(root);
cout<<endl;

Replace(root,17);

cout<< "-----------------checking if tree is binary----------------------------------"<<endl;
if (IsBinaryTree(root)) cout<< "Tree is Binary"<< endl;
else cout<< "Tree is not Binary"<<endl;

return 0;
}