#include<iostream>
#include<queue>
#include<vector>
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

void printLevelWise(TreeNode<int>* root) 
{
    queue<TreeNode<int>*> pendindNodes;
    pendindNodes.push(root);
    while(!pendindNodes.empty())
    {
        TreeNode<int>* front = pendindNodes.front();
        pendindNodes.pop();
        cout << front->data <<":";

        for (int i = 0; i < front->children.size(); i++) 
        {
            pendindNodes.push(front->children[i]);
            cout << front->children[i]->data;
            if (i != front->children.size()-1)
                cout << ",";
        }
        cout << endl;
    }
}

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

int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    return 0;
}