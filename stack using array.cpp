#include <iostream>
#define MAX_SIZE 101
using namespace std;
int top = -1;
int A[MAX_SIZE];

void Push(int x){
    if (top == MAX_SIZE-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    A[++top]= x;
   // cout<<"push"<<A[top]<<endl;
}

void Pop(){
    if (top == -1){
        cout<<"empty stack"<<endl;
        return;
    }
    top--;
    //cout<<"pop"<<A[top]<<endl;
}


int main() {
	// your code goes here
	Push (2);
	Push (7);
	Push (5);
	Pop ();
	Push (3);
	Push (8);
	
	for (int i=top; i>=0;i--){
	    cout<< A[i]<<endl;
	}
	
	return 0;
}
