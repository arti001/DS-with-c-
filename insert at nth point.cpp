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
    int position;
    cout << "At what position to insert" << endl;
    cin >> position;
    if (head == NULL)
    {
        cout<< "point doesnot exist"<< endl;
    }
    else {
    int count= 1;
    Node* pointer = head;
    while (pointer->next != NULL)
    {
        count++;
        if (count== position)
        {
        char character;
        cout << " Enter the characters" << endl;
        //cout << count << endl;
        cin >> character;
       // cout << character << endl;
        Node* name = Insert (character);
            name->next = pointer-> next;
            pointer->next= name;
           // cout<<name->data<< endl;
        }
        pointer = pointer->next;
    }
    }
    Print();
    return 0;
}
