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

int getHeight(TreeNode<int>* root) {
    int h = 1;
    if (root->children.size() == 0)
        return h;
    int arr[root->children.size()];
    for (int i = 0; i < root->children.size(); i++) {
        arr[i] = getHeight(root->children[i]);
    }
    int maxH = arr[0];
    for (int i = 1; i < root->children.size(); i++) {
        if(arr[i] > maxH)
            maxH = arr[i];
    }
    return maxH+1;
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
    cout << "Height of Tree = " << getHeight(root) << endl;
    return 0;
}