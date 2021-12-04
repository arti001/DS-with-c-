#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

stack<char> s;

int main() {
	// your code goes here
	char str[100];
	std::cout << "enter string" << std::endl;
	scanf ("%s", str);
	int length= strlen(str);
	for (int i=0; i<length; i++){
	    s.push(str[i]);
	}
	for (int i=0;i<length;i++){
	    cout<<str[i]<<endl;
	    str[i]=s.top();
	    s.pop();
	}
	cout <<"array is "<<str<<endl;
	//printf(" %s", str);
	return 0;
}
