#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
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
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftData);
            front->left = leftNode;
        }
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightData);
            front->right = rightNode;
        }
    }
    return root;
}

class checkBST 
{
    public:
    int maxNode;
    int minNode;
    bool status;
};

checkBST isBSTHelper(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        checkBST res;
        res.maxNode = INT_MIN;
        res.minNode = INT_MAX;
        res.status = true;
        return res;
    }
    checkBST leftAns = isBSTHelper(root->left);
    checkBST rightAns = isBSTHelper(root->right);
    checkBST result;
    result.minNode = min(root->data, min(leftAns.minNode, rightAns.minNode));
    result.maxNode = max(root->data, max(leftAns.maxNode, rightAns.maxNode));
    result.status = (root->data > leftAns.maxNode && root->data <= rightAns.minNode) && leftAns.status && rightAns.status;
    return result;
}

bool isBST(BinaryTreeNode<int>* root) {
    checkBST output = isBSTHelper(root);
    return output.status;
}

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (max(leftHeight, rightHeight)+1);
}
 
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return 0;
    }
    bool rootBST = isBST(root);
    if(rootBST) {
        return height(root);
    }
    return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root) << endl;
    return 0;
}