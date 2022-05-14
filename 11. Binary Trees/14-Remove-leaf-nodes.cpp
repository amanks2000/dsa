#include <iostream>
#include <queue>
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

void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1 || q.front() != NULL) {
        while (q.front() != NULL) {
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
        cout << endl;
        q.pop();
        q.push(NULL);
    }
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if (root == NULL)
        return root;
    if (root->left == NULL && root->right==NULL)
        root = NULL;
    if (root != NULL) {
        root->left = removeLeafNodes(root->left);
        root->right = removeLeafNodes(root->right);
    }
    return root;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    root = removeLeafNodes(root);
    printLevelWise(root);
    return 0;
}