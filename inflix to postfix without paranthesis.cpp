#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperator(char C){
    if (C=='+' || C =='-' || C =='*' || C == '/') return true;
    return false;
}

int operatorPrecedence(char C){
    switch (C){
        case '/':
            return 4;
            break;
        case '*':
            return 3;
            break;
        case '+':
            return 2;
            break;
        case '-':
            return 1;
            break;
        default:
            cout<<"unknown operator"<< endl;
            return -1;
    }
}


string getExpression(string exp){
    stack<char> S;
    string result;
    for (int i=0; i<exp.length(); i++)
    {
        if(!isOperator(exp[i])){
            result = result + exp[i];
        }
        else {
            while (!S.empty() && operatorPrecedence(exp[i])<operatorPrecedence(S.top())) {
                result = result + S.top();
                S.pop();
            }
            S.push(exp[i]);
        }
    }
    while (!S.empty()) {
        result = result + S.top();
        S.pop();
    }
    return result;
}


int main() {
	// your code goes here
	string expression;
	std::cout << "Enter expression" << std::endl;
	getline(cin,expression);
	cout<<"Your expression is " <<expression<< endl;
	
	string result = getExpression(expression);
	cout<< result<< endl;
	
	return 0;
}
