#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string postorderTraversal(string expression) {
    stack<string> stk;
    for (char c : expression) {
        if (isOperator(c)) {
            string operand2 = stk.top();
            stk.pop();
            string operand1 = stk.top();
            stk.pop();
            string temp = operand1 + operand2 + c;
            stk.push(temp);
        } else {
            stk.push(string(1, c));
        }
    }
    return stk.top();
}

int main() {
    string postfixExpression = "abc*de/-f+";
    string postorderExpression = postorderTraversal(postfixExpression);
    
    cout << "Postorder Expression: " << postorderExpression << endl;
    
    return 0;
}
