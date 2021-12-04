#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head= NULL;
node* tail= NULL;

void Enqueue(int x){
    node* temp = new node;
    temp->data= x;
    temp->next = NULL;
    if (head==NULL && tail==NULL){
        head=tail=temp;
    }
    else 
    {
        tail->next= temp;
        tail = temp;
    }
}

void Dequeue(){
    node* temp = head;
    if (head==NULL) 
    {
        cout<<"Queue is empty"<<endl;
        return;
        
    }
    else if (head==tail)
    {
        head=tail=NULL;
        
    }
    else
    {
    head = head->next;
    free(temp);
    }
}

void Print(){
    node* ptr = head;
    while (ptr != NULL){
        std::cout << ptr->data << std::endl;
        ptr=ptr->next;
    }
}
int main() {
	// your code goes here
	Enqueue(2);
	Enqueue(3);
	Enqueue(5);
	Enqueue(8);
	Dequeue();
	Enqueue(5);
	Print();
	return 0;
}
