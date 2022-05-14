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

void printAtDepthK(BinaryTreeNode<int>* root, int k) {
    if (root == NULL)
        return;
    if (k == 0) 
        cout << root->data << endl;
    k = k-1;
    if (k >= 0) {
        printAtDepthK(root->left, k);
        printAtDepthK(root->right, k);
    }
}

int printNodes(BinaryTreeNode<int> *root, int node, int k) {
    if (root == NULL)
        return -1;
    if (root->data == node) {
        printAtDepthK(root, k);
        return 0;
    }
    int ld = printNodes(root->left, node, k);
    int rd = printNodes(root->right, node, k);
    int d = -1;
    if (ld != -1) {
        d = ld + 1;
        if (d == k)
            cout << root->data << endl;
        else if (d < k) {
            printAtDepthK(root->right, k-d-1);
        }
    }
    if (rd != -1) {
        d = rd + 1;
        if (d == k)
            cout << root->data << endl;
        else if (d < k) {
            printAtDepthK(root->left, k-d-1);
        }
    }
    return d;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int depth = printNodes(root, node, k);    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}