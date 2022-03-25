#include<iostream>
#include<vector>
using namespace std;

template <typename T>

class TreeNode 
{
    public :

    T data; // Root of tree can contain any type of data, that is why template is used
    vector<TreeNode*> children; // A root of a tree can have multiple children nodes, therefore
    // vector helps in keeping the address of the children nodes.

    TreeNode (T data) {
        this->data = data;
    }
};

int main()
{
    // Creating nodes of the tree
    TreeNode<int> *root = new TreeNode<int>(1);  // Main root node
    TreeNode<int> *node1 = new TreeNode<int>(2); // Child Node 1
    TreeNode<int> *node2 = new TreeNode<int>(3); // Childe Node 2

    // Connecting child nodes to Root node
    root->children.push_back(node1);
    root->children.push_back(node2);

    return 0;
}