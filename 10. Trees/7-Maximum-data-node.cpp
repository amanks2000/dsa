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

// Recursively finding Max node of the given Tree
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int> *maxNode = root;
    for (int i = 0; i < root->children.size(); i++) {
        TreeNode<int> *ans = maxDataNode(root->children[i]);
        if (ans->data > maxNode->data)
            maxNode = ans;
    }
    return maxNode;
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
    cout << "Max Node = " << maxDataNode(root)->data << endl;
    return 0;
}