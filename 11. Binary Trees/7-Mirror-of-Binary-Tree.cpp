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

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftChildNode = new BinaryTreeNode<int>(leftChild);
            pendingNodes.push(leftChildNode);
            front->left = leftChildNode;
        }

        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightChildNode = new BinaryTreeNode<int>(rightChild);
            pendingNodes.push(rightChildNode);
            front->right = rightChildNode;
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        else
            cout << "L:-1,";
        if (front->right != NULL)
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
            cout << "R:-1";
        cout << endl;
    }
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return;
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    mirrorBinaryTree(root);
    printLevelWise(root);
    return 0;
}