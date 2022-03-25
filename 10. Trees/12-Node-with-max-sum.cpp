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

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++) 
    {
        sum += root->children[i]->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *childmax = maxSumNode(root->children[i]);
        int smallsum = childmax->data;
        for (int i = 0; i < childmax->children.size(); i++) 
        {
            smallsum += childmax->children[i]->data;
        }
        if (sum <= smallsum) 
        {
            ans = childmax;
            sum = smallsum;
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
    TreeNode<int> *ans = maxSumNode(root);
    cout << "Node with max sum of children = " << ans->data << endl;
    return 0;
}