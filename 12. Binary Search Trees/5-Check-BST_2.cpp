#include <iostream>
#include <queue>
#include <climits>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Triplet Class ->
class isBSTReturn 
{
public :
    bool isBST;
    int minimum;
    int maximum;
};

// Time complexity = O(n)
isBSTReturn helperBST (BinaryTreeNode<int>* root) {
    if (root == NULL) {
        isBSTReturn ans;
        ans.isBST = true;
        ans.maximum = INT_MIN;
        ans.minimum = INT_MAX;
        return ans;
    }
    isBSTReturn leftAns = helperBST(root->left);
    isBSTReturn rightAns = helperBST(root->right);
    isBSTReturn ans;
    ans.minimum = min(root->data, min(leftAns.minimum, rightAns.minimum));
    ans.maximum = max(root->data, max(leftAns.maximum, rightAns.maximum));
    ans.isBST = (root->data > leftAns.maximum) && (root->data <= rightAns.minimum) && (leftAns.isBST) && (rightAns.isBST);
    return ans;
}

bool isBST(BinaryTreeNode<int> *root) {
    isBSTReturn output = helperBST(root); 
    return output.isBST;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}