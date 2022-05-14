#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

// Inorder : 4 2 5 1 8 6 9 3 7
// Preorder: 1 2 4 5 3 6 8 9 7
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    BinaryTreeNode<int>* root = NULL;
    if (preLength != 0)
        root = new BinaryTreeNode<int>(preorder[0]);
    if (root == NULL)
        return root;
    int iroot = 0;
    while (inorder[iroot] != root->data) {
        iroot++;
    }
    // To build the Tree using recursion we need to pass the correct arguments of
    // preorder and inorder for left side of root as well as right side of root.
    root->left = buildTree(preorder+1, iroot, inorder, iroot);
    root->right = buildTree(preorder+1+iroot,(preLength-1-iroot),inorder+1+iroot,(inLength-1-iroot));
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
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

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}