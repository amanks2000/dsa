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

bool helperSum(BinaryTreeNode<int>* root, int sum) {
    if (root == NULL)
        return false;
    if (root->data == sum) {
        root->data = INT_MIN;
        return true;
    }
    return (helperSum(root->left, sum) ||  helperSum(root->right, sum));
}

void printSum(BinaryTreeNode<int> *node, int sum, BinaryTreeNode<int> *root) {
    if (node == NULL)
        return;
    if (sum < 0)
        return;
    int x = node->data;
    int y = sum - x;
    bool ans = helperSum(root, y);
    if (ans && (x != y))
        cout << min(x,y) << " " << max(x,y) << endl;
    if (node->left != NULL) 
        printSum(node->left, sum, root);
    if (node->right != NULL)
        printSum(node->right, sum, root);
}


// Time Complexity is O(n^2)
void pairSum(BinaryTreeNode<int> *root, int sum) {
    printSum(root, sum, root);
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    return 0;
}