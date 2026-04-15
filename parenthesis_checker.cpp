#include <iostream>
#include <stack>
using namespace std;
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
bool isWellParenthesized(const string& expr) {
    stack<char> s;
 for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatching(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }
  return s.empty(); 
}
int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
 if (isWellParenthesized(expression)) {
        cout << "Expression is well parenthesized." << endl;
    } else {
        cout << "Expression is NOT well parenthesized." << endl;
    }
  return 0;
}
