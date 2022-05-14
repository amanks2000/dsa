#include<iostream>
#include<queue>
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

BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter Root Data : ";
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter Left child of " << front->data << " : ";
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftChildNode = new BinaryTreeNode<int>(leftChild);
            pendingNodes.push(leftChildNode);
            front->left = leftChildNode;
        }

        cout << "Enter Right child of " << front->data << " : ";
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightChildNode = new BinaryTreeNode<int>(rightChild);
            pendingNodes.push(rightChildNode);
            front->right = rightChildNode;
        }
    }
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
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    return 0;
}