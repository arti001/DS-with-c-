#include <iostream>
using namespace std;

struct Node{
    char data;
    Node* next;
};

Node* head = NULL;

Node* Insert (char characters){
  Node* list= new Node();
  list ->data = characters;
  list ->next = NULL;
  return list;
}

void Print(){
    Node* pointer = head;
    while( pointer!= NULL){
        cout << pointer->data << endl;
        pointer = pointer->next;
    }
}

void Delete(int n){
    int count=1;
    Node* pointer=head;
    if (n==1){
        head = pointer->next;
        free (pointer);
        return;
    }
   while (count < n-1 && pointer !=NULL){
       count++;
      cout<<pointer->data <<endl;
       pointer= pointer->next;
   }
   if (pointer==NULL || pointer->next == NULL){
       return;
   }
  
   // cout<<"outside lopp" <<endl;
   Node* temp = pointer->next;
  //cout<<"outside loop 2" <<endl;
   pointer->next = temp ->next;
   delete (temp);
}

int main() {
    int value;
    cout << "how many characters?" << endl;
    cin >> value;
    for (int i=0; i<value; i++){
        char characters;
        cout << " Enter the characters" << endl;
        cin >> characters;
        Node* name = Insert (characters);
        if (head == NULL){
            head= name;
        }
        else{
            Node* pointer = head;
            while( pointer->next!= NULL){
                pointer = pointer->next;
            }
            pointer->next= name;
        }
    }
    Print();
    int n;
    cout << "which position to delete from?"<<endl;
    cin>>n;
    Delete(n);
    Print();
    return 0;
}
