#include <iostream>
#include <stack>
using namespace std;

int *stockSpan(int *price, int size)
{
    stack<int> st;
    int *ans = new int[size];
    st.push(0);
    ans[0] = 1;
    for (int i = 1; i < size; i++)
    {
        int index = st.top();
        if (price[i] <= price[index])
        {
            ans[i] = 1;
            st.push(i);
        }
        else
        {
            ans[i] = 1;
            while ((!st.empty()) && (price[i] > price[index])) 
            {
                ans[i] += ans[st.top()];
                st.pop();
                if (!st.empty())
                    index = st.top();
            }
            st.push(i);
        }
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}