#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;
Node* head3 = NULL;

Node* Insertdata(int data){
    Node* list = new Node;
    list->data = data;
    list->next = NULL;
    return list;
}

void CreateList1(){
    if(head1==NULL) {
        head1 = Insertdata (2);
    }
    head1->next = Insertdata (5);
    head1->next->next = Insertdata (7);
}

void CreateList2(){
    if(head2==NULL) {
        head2 = Insertdata (3);
    }
    head2->next = Insertdata (5);
}

void CreateList3(int sum){
    //cout<<"in for loop"<<endl;
 for(int i=sum; i>0;i=i/10){
    int rem = i % 10;
    if(head3==NULL) head3= Insertdata(rem);
    else 
    {
        Node* temp = Insertdata(rem);
        temp->next= head3;
        head3 = temp;
    }
   // cout<<"exit for loop"<<endl;
 }
}

int FirstNum(){
    int n= 0;
    Node* pointer= head1;
    while (pointer != NULL){
        n= pointer->data + n*10;
        pointer=pointer->next;
    }
    return n;
}

int SecondNum(){
    int n= 0;
    Node* pointer= head2;
    while (pointer != NULL){
        n= pointer->data + n*10;
        pointer=pointer->next;
    }
    return n;
}

void printList(Node* pointer){
    while (pointer!= NULL){
      //  cout<<"in while loop"<<endl;
        cout<<pointer->data<<endl;
        pointer=pointer->next;
    }
}

int main() {
	// your code goes here
	CreateList1();
	CreateList2();
	int a = FirstNum ();
	std::cout << a << std::endl;
	int b = SecondNum();
	std::cout << b << std::endl;
	int sum = a+b;
	std::cout << sum << std::endl;
	CreateList3(sum);
	cout<<"list for reqd sum is "<< endl;
	printList(head3);
	return 0;
}
