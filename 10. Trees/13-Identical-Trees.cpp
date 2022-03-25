#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->children.size() != root2->children.size())
        return false;
    for (int i = 0; i < root1->children.size(); i++) {
        bool ans = areIdentical (root1->children[i],root2->children[i]);
        if (!ans)
            return ans;
    }
    if (root1->data == root2->data)
        return true;
    else
        return false;
}

TreeNode<int> *takeInput()
{
    queue<TreeNode<int> *> pendingNodes;
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            pendingNodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

int main()
{
    TreeNode<int> *root1 = takeInput();
    TreeNode<int> *root2 = takeInput();
    cout << "Tree Identical: " << areIdentical(root1,root2) << endl;
    return 0;
}