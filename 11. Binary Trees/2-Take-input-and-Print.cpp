#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode 
{
    public :
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

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
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void printTree (BinaryTreeNode<int>* root) {
    if (root == NULL) /// Base case for recursion
        return;
    cout << root->data << ": ";

    if (root->left != NULL) {
        cout << "L = " << root->left->data <<" ";
    }
    if (root->right != NULL) {
        cout << "R = " << root->right->data <<" ";
    }

    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    /*BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(30);
    root->left = node1;
    root->right = node2;*/
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    return 0;
}