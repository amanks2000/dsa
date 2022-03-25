#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public:

    T data;
    vector<TreeNode*> children;

    TreeNode(T data) {
        this->data = data;
    }
};

// We use queues to take input LEVEL wise
TreeNode<int>* takeInputLevelWise() 
{
    int rootData;
    cout << "Enter Root Data: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter the number of children of " << front->data << ": ";
        cin >> numChild;

        for (int i = 0; i < numChild; i++) {
            int childData;
            cout << "Enter the data of child " << (i+1) <<" of " << front->data <<": ";
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);

            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

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
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    return 0;
}