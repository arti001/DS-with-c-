#include <iostream>
using namespace std;

//defining node
struct Node {
    int data;
    Node* next;
};
Node* head= NULL;

Node* Insertdata(int data){
     Node* list = new Node();
     list->data= data;
     list->next = NULL;
     return list;
}

Node* Insert(){
    if (head== NULL) head = Insertdata(5);
        Node* pointer = head;
        pointer->next= Insertdata(2);
        pointer= pointer->next;
        pointer->next= Insertdata(6);
        pointer= pointer->next;
        pointer->next= Insertdata(7);
        pointer= pointer->next;
}


void Printforward(Node* pointer){
    if (pointer==NULL) return;
    cout<< pointer->data;  
    Printforward(pointer->next);
}

void Printbackward(Node* pointer){
    if (pointer==NULL) return;
    Printbackward(pointer->next);
    cout<< pointer->data;  
}

int main() {
	// your code goes here
	Insert();
	cout<<"printing forward list"<<endl;
	Printforward(head);
	cout<<""<<endl;
	cout<<"printing backward list"<<endl;
	Printbackward(head);
	return 0;
}
