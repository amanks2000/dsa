#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
    public:
    T data;
    vector<TreeNode*> children;

    TreeNode(T data) {
        this->data = data;
    }
};

void printAtLevelK(TreeNode<int>* root, int k) {
    if (root == NULL)
        return;
    if (k == 0) {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k-1);
    }
}

TreeNode<int>* takeInput() 
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty()) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* childNode = new TreeNode<int>(childData);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

int main()
{
    TreeNode<int> *root = takeInput();
    cout << "Enter the depth of nodes you want to Print: ";
    int depth;
    cin >> depth;
    cout << "Nodes at depth " << depth << " = " ;
    printAtLevelK(root,depth);
    cout << endl;
    return 0;
}