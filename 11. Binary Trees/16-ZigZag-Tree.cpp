#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class BinaryTreeNode 
{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    queue<BinaryTreeNode<int>*> q;
    int rootData;
    cin >> rootData;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftData);
            q.push(leftNode);
            front->left = leftNode;
        }
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightData);
            q.push(rightNode);
            front->right = rightNode;
        }
    }
    return root;
}

void zigZagOrder(BinaryTreeNode<int> *root) {
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    int level = 1;
    q.push(root);
    q.push(NULL);
    cout << root->data << " " << endl;
    while (q.size() > 1 || q.front() != NULL) {
        stack<BinaryTreeNode<int>*> s;
        level++;
        while (q.front() != NULL) {
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            if (front->left != NULL) {
                q.push(front->left);
                if (level % 2 != 0)
                    cout << front->left->data << " ";
                else
                    s.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
                if (level % 2 != 0)
                    cout << front->right->data << " ";
                else
                    s.push(front->right);
            }
        }
        q.pop();
        q.push(NULL);
        while (!s.empty()) {
            cout << s.top()->data << " ";
            s.pop();
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
    return 0;
}