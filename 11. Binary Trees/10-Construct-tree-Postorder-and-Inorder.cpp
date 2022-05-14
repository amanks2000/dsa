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
// Postorder: 4 5 2 8 9 6 7 3 1
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    BinaryTreeNode<int> *root = NULL;
    if (postLength > 0)
        root = new BinaryTreeNode<int>(postorder[postLength-1]);
    if (root == NULL)
        return root;
    int iroot = 0;
    while (inorder[iroot] != root->data) {
        iroot++;
    }
    root->left = buildTree(postorder, iroot, inorder, iroot);
    root->right = buildTree(postorder+iroot, (postLength-1-iroot), inorder+iroot+1, (inLength-1-iroot));
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