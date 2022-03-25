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

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    TreeNode<int> *ans = NULL;
    if (root->data > x)
        ans = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *smallAns = getNextLargerElement(root->children[i], x);
        if (smallAns == NULL)
            continue;
        else {
            if (ans == NULL)
                ans = smallAns;
            else if (smallAns->data > x && smallAns->data < ans->data)
                ans = smallAns;
        }
    }
    return ans;
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
    TreeNode<int> *root = takeInput();
    cout << "Enter element: ";
    int x;
    cin >> x;
    TreeNode<int> *ans = getNextLargerElement(root, x);
    cout << "Node with next Larger element = " << ans->data << endl;
    return 0;
}