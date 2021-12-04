#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = NULL;

void Push(int x){
  	Node* temp = new Node();
	temp->data = x;
	temp->next = top;
	top = temp;
}

void Print(){
    Node* ptr = top;
    while(ptr!= NULL){
        std::cout << ptr->data << std::endl;
        ptr=ptr->next;
    }
}

int main() {
	// your code goes here
    Push(4);
    Push(7);
    Push(8);
    Push(2);
    
    Print();
	return 0;
}
