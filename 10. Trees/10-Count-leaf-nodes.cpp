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

int getLeafNodeCount(TreeNode<int>* root) {
    int count = 0;
    if (root->children.size() == 0)
        count++;
    for (int i = 0; i < root->children.size(); i++) {
        count += getLeafNodeCount(root->children[i]);
    }
    return count;
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
    cout << "Number pf leaf nodes of Tree = " << getLeafNodeCount(root) << endl;
    return 0;
}