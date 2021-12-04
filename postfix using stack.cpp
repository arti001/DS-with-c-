#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getResult(int num1, int num2, char operation)
{
  switch (operation) {
      
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default:
        // operator is doesn't match any case constant (+, -, *, /)
        cout << "Error! The operator is not correct";
        return -1;
    }
}
bool isOperator(char C)
{
    if (C == '+' || C == '-' || C =='*' || C =='/') return true;
    return false;
}

int solveExpression(string exp)
{
    stack<int> S;
    for (int i=0; i<exp.length();i++){
        
        if (isOperator(exp[i])){
            int num2= S.top(); S.pop();
            int num1= S.top(); S.pop();
            int result = getResult(num1,num2,exp[i]);
            S.push(result);
        }
        else 
        {
            S.push((int)exp[i]-48);
    }}
    return S.top();
}

int main() {
	// your code goes here
	string expression;
	cout<<"Enter your expression"<<endl;
	getline(cin,expression);
	int result= solveExpression(expression);
	cout<< "Result of expression is " << result;
	return 0;
}
