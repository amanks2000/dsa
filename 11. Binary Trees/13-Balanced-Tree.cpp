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

int height(BinaryTreeNode<int> *root) {
    if (root == NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	if (root == NULL)
        return true;
    if (height(root->left) != height(root->right))
        return false;
    bool ans1 = isBalanced(root->left);
    bool ans2 = isBalanced(root->right);
    if (!ans1)
        return ans1;
    if (!ans2)
        return ans2;
    return true;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    cout << "Tree is Balanced : " << isBalanced(root) << endl;
    return 0;
}