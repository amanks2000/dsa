/************************************************************************** 
Binary Tree is a special type of tree where each node can have a maximum of 
2 child nodes. 
***************************************************************************/
#include <iostream>
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

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(30);
    root->left = node1;
    root->right = node2;
    return 0;
}