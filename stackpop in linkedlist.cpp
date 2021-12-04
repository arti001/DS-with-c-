#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top= NULL;

//creating linkedlist
void Push(int x){
    Node* temp= new Node();
    temp->data = x;
    temp->next= top;
    top=temp;
}

void Print(){
    Node* ptr= top;
    cout<<"Linkedlist is:"<<endl;
    while (ptr!=NULL){
        cout<<ptr->data<<"  ";
        ptr=ptr->next;
    }
}

void Pop(){
    Node* temp;
    if (top==NULL){
        return;
    }
    temp= top;
    top=temp->next;
    free(temp);
}


int main() {
	// your code goes here
	Push(3);
	Push(6);
	Pop();
	Push(4);
	Push(9);
	Push(7);
	Pop();
	Print();
	return 0;
}
