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

void printPreOrder(TreeNode<int>* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++) {
        printPreOrder(root->children[i]);
    }
}

void printPostOrder(TreeNode<int>* root) {
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++) {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
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
    //printPreOrder(root);
    printPostOrder(root);
    return 0;
}