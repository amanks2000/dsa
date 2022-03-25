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

class custom {
    public :
    TreeNode<int>* max;
    TreeNode<int>* smax;

    custom (TreeNode<int>* max, TreeNode<int>* smax) {
        this->max = max;
        this->smax = smax;
    }
};

TreeNode<int>* getLargestNode(TreeNode<int>* root) {
    TreeNode<int>* max = root;
    for (int i = 0; i < root->children.size(); i++) {
        TreeNode<int>* ans = getLargestNode(root->children[i]);
        if (ans->data > max->data)
            max = ans;
    }
    return max;
}

custom getSmax(TreeNode<int>* root) {
    custom ans(root,NULL);
    for (int i = 0; i < root->children.size(); i++) {
        custom temp = getSmax(root->children[i]);
        TreeNode<int>* x;
        if(temp.max->data > ans.max->data) {
            x = ans.max;
            ans.max = temp.max;
            if (temp.smax == NULL) {
                ans.smax = x;
            }
            else {
                if (temp.smax->data > x->data) {
                    ans.smax = temp.smax;
                }
                else {
                    ans.smax = x;
                }
            }
        }
        else {
            if(ans.max->data!=temp.max->data && (ans.smax==NULL || temp.max->data > ans.smax->data)){
                ans.smax=temp.max;
            }
        }
    } 
    return ans;   
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if (root == NULL)
        return root;        
    custom ans = getSmax(root);
    return ans.smax;
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
    TreeNode<int> *ans = getSecondLargestNode(root);
    cout << "Second Largest Node = " << ans->data << endl;
    return 0;
}