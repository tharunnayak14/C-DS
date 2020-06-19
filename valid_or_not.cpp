#include <iostream>
#include <stack>
using namespace std;

// Function to check if given expression is balanced or not
bool balParenthesis(string exp)
{
	// base case: length of the expression must be even
	if (exp.length() & 1)
		return false;

	// take an empty stack of characters
	stack<char> stack;

	// traverse the input expression
	for (char ch: exp)
	{
		// if current char in the expression is an opening brace,
		// push it to the stack
		if (ch == '(' || ch == '{' || ch == '[') {
			stack.push(ch);
		}

		// if current char in the expression is a closing brace
		if (ch == ')' || ch == '}' || ch == ']')
		{
			// return false if mismatch is found (i.e. if stack is empty,
			// the number of opening braces is less than number of closing
			// brace, so expression cannot be balanced)
			if (stack.empty()) {
				return false;
			}

			// pop character from the stack
			char top = stack.top();
			stack.pop();

			// if the popped character if not an opening brace or does
			// not pair with current character of the expression
			if ((top == '(' && ch != ')') ||
				(top == '{' && ch != '}') ||
				(top == '[' && ch != ']'))
			{
				return false;
			}
		}
	}

	// expression is balanced only if stack is empty at this point
	return stack.empty();
}

int main()
{
	string exp = "{()}[{2+3}]";

	if (balParenthesis(exp))
		cout << "The expression is balanced";
	else
		cout << "The expression is not balanced";

	return 0;
}