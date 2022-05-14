#include <iostream>
#include <queue>

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

using namespace std;

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

/*
// Function to find sum of all nodes 
int helper(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return 0;
    int leftSum = helper(root->left);
    int rightSum = helper(root->right);
    return (root->data + leftSum + rightSum);    
}

BinaryTreeNode<int>* newTree(BinaryTreeNode<int>* root){
    if (root == NULL)
        return NULL;
    BinaryTreeNode<int>* newRoot = new BinaryTreeNode<int>(root->data);
    newRoot->left = newTree(root->left);
    newRoot->right = newTree(root->right);
    return newRoot;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    BinaryTreeNode<int>* newRoot = newTree(root);
    if (root == NULL)
        return;
    int sum = newRoot->data;
    sum += helper(newRoot->right);
    root->data = sum;
    replaceWithLargerNodesSum(root->left);
    replaceWithLargerNodesSum(root->right);
}*/

int replace(BinaryTreeNode<int>* root, int sum) {
    if (root == NULL)
        return sum;
    sum = replace(root->right, sum);
    sum += root->data;
    root->data = sum;
    sum = replace(root->left, sum);
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int sum = replace(root,0);
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    printLevelATNewLine(root);
    delete root;
}