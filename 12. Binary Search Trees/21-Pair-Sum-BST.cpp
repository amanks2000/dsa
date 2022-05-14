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

/*bool findKey(BinaryTreeNode<int>* root, int s) {
    if (root == NULL)
        return false;
    bool leftAns = false, rightAns = false;
    if (s == root->data) {
        root->data = -1;
        return true;
    }
    else if (s < root->data) 
        leftAns = findKey(root->left, s);
    else
        rightAns = findKey(root->right, s);
    return (leftAns || rightAns);
}

void helper(BinaryTreeNode<int> *root, BinaryTreeNode<int>* node, int s) {
    if (node == NULL)
        return;
    int first = node->data;
    int second = s - node->data;
    if (second > 0) {
        if (second < node->data && findKey(root, second))
            cout << second << " " << first << endl;
        if (second > node->data && findKey(root, second))
            cout << first << " " << second << endl;
    }
    helper(root, node->left, s);
    helper(root, node->right, s);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    helper(root,root,s);
}*/

// Traversing in inoder way gives us the sorted array in a BST:
void getVector(BinaryTreeNode<int>* root, vector<int> *arr) {
    if (root == NULL) {
        return;
    }
    getVector(root->left, arr);
    arr->push_back(root->data);
    getVector(root->right, arr);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    vector<int> *arr = new vector<int>();
    getVector(root, arr);
    int i = 0;
    int j = arr->size()-1;
    while (i < j) {
        if (arr->at(i) + arr->at(j) == s) {
            cout << arr->at(i) << " " << arr->at(j) << endl;
            i++;
            j--;
        }
        else if (arr->at(i) + arr->at(j) > s) {
            j--;
        }
        else {
            i++;
        }
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}