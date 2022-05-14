#include<bits/stdc++.h>
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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild); 
            currentNode->right = rightNode; 
            q.push(rightNode);
        }
    }
    return root;
}

bool findNode(BinaryTreeNode<int>* root, int num) {
    if (root == NULL)
        return false;
    if (root->data == num)
        return true;
    return (findNode(root->left, num) || findNode(root->right, num));
}

// LCA -> Lowest Common Ancestor
// LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    if (root == NULL)
        return -1;
    bool la = findNode(root->left, a);
    bool lb = findNode(root->left, b);
    bool ra = findNode(root->right, a);
    bool rb = findNode(root->right, b);

    bool leftFound = la && lb;
    if (leftFound)
        return getLCA(root->left, a, b);

    bool rightFound = ra && rb;
    if (rightFound)
        return getLCA(root->right, a, b);

    if (a == root->data && (lb || rb)) 
        return root->data;
    if (b == root->data && (la || rb))
        return root->data;

    bool ans = (la && rb)  || (lb && ra);
    if (ans)
        return root->data;

    if ((a == root->data && !(lb || rb)) || (b == root->data && !(la || ra)))
        return root->data;
    return -1;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a,b;
    cin >> a >> b;
    cout << getLCA(root, a, b) << endl;
    return 0;
}