#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode*> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

//Function to take input Tree from user
TreeNode<int>* takeInput() 
{
    int rootData;
    cout << "Enter Data: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << ": " ;
    cin >> n;

    for (int i=0; i<n; i++) {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}


// Function to print Tree nodes level wise
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << ": "; // Printing root node
    for (int i = 0; i < root->children.size(); i++) // To print child nodes of all parent nodes
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]); // Recursively printing child nodes of Tree
    }
}

int main()
{
    TreeNode<int>* root = takeInput();
    printTree(root);
    return 0;
}