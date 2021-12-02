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
        std::cout << pointer->data << std::endl;
        pointer = pointer->next;
    }
}

int main() {
    int value;
    std::cout << "how many characters?" << std::endl;
    std::cin >> value;
    for (int i=0; i<value; i++){
        char characters;
        std::cout << " Enter the characters" << std::endl;
        std::cin >> characters;
        Node* name = Insert (characters);
        name-> next= head;
        head=name;
    }
    
    Print();
    return 0;
}
