/**************************************************************************
Types of Traversals in Binary Trees -
    Preorder : Node->Left->Right (Parent node first Child nodes later)
    Postorder: Left->Right->Node (Child nodes first Parent node later)
    Inorder  : Left->Node->Right
***************************************************************************/
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

// 4 2 5 1 8 6 9 3 7 
void inorder (BinaryTreeNode<int>* root) {
    if (root == NULL)
        return ;
    inorder (root->left);
    cout << root->data << " ";
    inorder (root->right);
}

// 1 2 4 5 3 6 8 9 7
void preOrder(BinaryTreeNode<int> *root) {
	if (root == NULL)
        return;
    cout << root -> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 4 5 2 8 9 6 7 3 1
void postOrder(BinaryTreeNode<int> *root) {
	if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root -> data << " ";
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    cout << "Inorder Traversal : " << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal : " << endl;
    preOrder(root);
    cout << endl;
    cout << "Postorder Traversal : " << endl;
    postOrder(root);
    cout << endl;
    return 0;
}