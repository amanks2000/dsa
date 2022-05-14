#include <iostream>
#include <queue>
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

// Below solution is incorrect for checking a Binary Tree for BST :
/*bool isBST(BinaryTreeNode<int> *root) {
    if (root == NULL)
        return true;
    bool smallAns = (isBST(root->left) && isBST(root->right));
    if (smallAns) {
        if (root->left != NULL && root->left->data >= root->data ) 
            return false;
        if (root->right != NULL && root->right->data < root->data ) 
            return false;
        else
            return true;
    }
    return false;
}*/

int minimumNode(BinaryTreeNode<int> *root) {
    if (root == NULL)
        return 999999;
    return min(root->data, min(minimumNode(root->left), minimumNode(root->right)));
}

int maximumNode(BinaryTreeNode<int> *root) {
    if (root == NULL)
        return -1;
    return max(root->data, max(maximumNode(root->left), maximumNode(root->right)));
}

// Correct approach is that, root should be bigger than the largest node on left side
// and root should be smaller than smallest node on right side.
// But, the Time complexity = O(n^2) , which is not optimal
bool isBST(BinaryTreeNode<int> *root) {
    if (root == NULL)
        return true;
    bool ans = (root->data > maximumNode(root->left)) && (root->data <= minimumNode(root->right));
    return ans && isBST(root->left) && isBST(root->right);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}