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

void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

BinaryTreeNode<int>* helperFunc(int *arr, int si, int ei) {
    if (si > ei)
        return NULL;
    int mid = (si + ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
    root->left = helperFunc(arr, si, mid-1);
    root->right = helperFunc(arr, mid+1, ei);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	BinaryTreeNode<int>* root = helperFunc(input, 0, n-1);
    return root;
}

int main() {
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}