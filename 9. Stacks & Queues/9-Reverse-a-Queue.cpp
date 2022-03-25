#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &input) {
	stack<int> s;
    while (!input.empty()) {
        int element = input.front();
        s.push(element);
        input.pop();
    }
    while(!s.empty()) {
        int element = s.top();
        input.push(element);
        s.pop();
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}