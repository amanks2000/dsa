#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode 
{
    public :
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;
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

// In a Balanced BST, insertion/deletion/search Time complexity = O(h) , h = log n
// A Balanced tree is a tree in which the |height of left sub-tree - height of right sub-tree|
// is at most 1.

class BST 
{
    BinaryTreeNode<int>* root;

    public :
    BST () {
        root = NULL;
    }

    ~BST() {
        delete root;
    }

    BinaryTreeNode<int>* insertNode(int data, BinaryTreeNode<int>* node) {
        if (node == NULL) {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data <= node->data) {
            node->left = insertNode(data, node->left);
        }
        else {
            node->right = insertNode(data, node->right);
        }
        return node;
    }

    void insertData(int data) {
        root = insertNode(data, root);
    }

    BinaryTreeNode<int>* deleteNode(int data, BinaryTreeNode<int>* node) {
        if (node == NULL)
            return NULL;
        if (node->data == data) {
            if (node->left == NULL && node->right == NULL){
                return NULL;
            }
            else if (node->left != NULL && node->right == NULL) {
                return node->left;
            }
            else if (node-> right != NULL && node->left == NULL) {
                return node->right;
            }
            else {
                BinaryTreeNode<int>* minNode = node->right;
				while (minNode->left != NULL) {
					minNode = minNode->left;
				}
				int rightMin = minNode->data;
				node->data = rightMin;
				node->right = deleteNode(rightMin, node->right);
				return node;
            }
        }
        else if (data < node->data) {
            node->left = deleteNode(data, root->left);
        } 
        else {
            node->right = deleteNode(data, root->right);
        }
        return node;
    }

    void deleteData(int data) {
        root = deleteNode(data, root);
    }

    void printNode(BinaryTreeNode<int>* node) {
        if (node == NULL)
            return;
        cout << node->data << ":" ;
        if (node->left != NULL)
            cout << "L:" << node->left->data << ",";
        if (node->right != NULL)
            cout << "R:" << node->right->data;
        cout << endl;
        printNode(node->left);
        printNode(node->right);
    }

    void print() {
        printNode(root);
    }

    private :
    bool hasData(int data, BinaryTreeNode<int>* node) {
        if (node == NULL)
            return false;
        if (node->data == data) {
            return true;
        }
        else if (data < node->data) {
            return hasData(data, node->left);
        }
        else {
            return hasData(data, node->right);
        }
    }

    public :
    bool hasData(int data) {
        return hasData(data, root);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insertData(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->hasData(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}