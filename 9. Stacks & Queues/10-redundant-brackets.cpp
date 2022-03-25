#include <iostream>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
        {
            s.push(expression[i]);
        }
        else if ((expression[i] == '+') || (expression[i] == '-') || (expression[i] == '*') || (expression[i] == '/'))
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')' && i > 0)
        {
            if (s.top() == '(')
            {
                s.pop();
                return true;
            }
            while ((!s.empty()) && s.top() != '(')
            {
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}