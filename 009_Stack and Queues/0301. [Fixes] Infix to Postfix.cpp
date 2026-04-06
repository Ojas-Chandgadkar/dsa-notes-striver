// You are given a valid Infix Expression 'exp',
// Convert it to Postfix expression


#include <bits/stdc++.h>
using namespace std;


int precedence(char ch) {
	switch (ch) {
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return -1;
	}
}

string infixToPostfix(string exp) {
	string postfix = "";
	stack<char> st;
	int size = exp.size();

	for (int i = 0; i < size; ++i) {
		char ch = exp[i];

		if (ch == '(') {
			st.push(ch);
		} 
		else if (ch == ')') {
			while (!st.empty() && st.top() != '(') {
				postfix += st.top();
				st.pop();
			}
			st.pop();
		} 
		else if (isdigit(ch) || isalpha(ch)) {
			postfix += ch;
		} 
		else {
			if (st.empty() || precedence(ch) > precedence(st.top())) {
				st.push(ch);
			} 
			else {
				while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                    postfix += st.top();
                    st.pop();
				}
			    st.push(ch);
			}
		}
	}

	while (!st.empty()) {
		postfix += st.top();
		st.pop();
	}

  	return postfix;
}






// Traverse the Infix expression, if the character is : 
//     1. (        : Push into stack
//     2. Operand  : Print it
//     3. )        : Keep popping and printing until ) is found
//     4. Operator : Here are two cases,
//                      a. If(stack is empty) Push
//                      b. Else, Compare with top operator
//                              If(Top of stack is Bracket) Push
//                              Else If(higher prescedance than top) Push
//                              Else, keep popping and printing until higher presecdence is encountred at top 
// When the expression is over, Pop amd print stack

// Note that operator prescedance is: 
// RaisedTo^ > MultiplyDivision > AddditionSubstraction
//  For same level, the one that comes first in the infix string has higher Presedance, that is one that is already lying in the stack's top



// BUT HOW DOES COMIPLES EVALUATE THIS POSTFIX EXPRESSION :
//      Make a Stack.
//      Traverse the postfix expression, 
//          1. Operand  : Push to stack
//          2. Operator : Evaluate in infix as, 
//                              Operand2 = st.pop();
//                              Operand1 = st.pop();
//                              Evaluate <Operand1><Operator><Operand2>
//                              Push this expression into the stack
//      When the traversing is fininished, the one value stored in stack is the answer, return st.pop();