#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expression)
{
    stack<char> st;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
            st.push(expression[i]);
        else if (expression[i] == ')')
        {
            if (st.empty()==false && st.top() == '(')
                st.pop();
            else
                return false;
        }
        else if (expression[i] == ']' )
        {
            if (st.empty()==false && st.top() == '[')
                st.pop();
            else
                return false;
        }
        else if (expression[i] == '}')
        {
            if (st.empty()==false && st.top() == '{')
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}