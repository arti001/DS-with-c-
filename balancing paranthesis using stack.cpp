#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool ArePair(char opening, char closing){
    if(opening =='(' && closing == ')') return true;
    else if(opening =='{' && closing == '}') return true;
    else if(opening =='[' && closing == ']') return true;
    return false;
}

bool AreParanthesis(string exp){
    stack<char> S;
    for (int i=0; i< exp.length(); i++)
    {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            S.push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if (S.empty() || !ArePair(S.top(),exp[i])) return false;
            else
                S.pop();
        }
    }
    if (S.empty()) return true;
    else false;
}

int main() {
	// your code goes here
	string expression;
	std::cout << "Enter your expression.." << std::endl;
	cin>> expression;
	if (AreParanthesis(expression))
	    cout<< "Expression is balanced"<<endl;
	else 
	    cout<<"Expression is NOT balanced"<<endl;
	return 0;
}
