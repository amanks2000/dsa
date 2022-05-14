#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftChildNode = new BinaryTreeNode<int>(leftChild);
            pendingNodes.push(leftChildNode);
            front->left = leftChildNode;
        }

        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightChildNode = new BinaryTreeNode<int>(rightChild);
            pendingNodes.push(rightChildNode);
            front->right = rightChildNode;
        }
    }
    return root;
}

pair<int,int> getMinAndMax(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        pair<int, int> p;
        p.first = 9999999; // first -> minimum
        p.second = 0;// second -> maximum
        return p;
    }
    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);
    int lmin = leftAns.first;
    int lmax = leftAns.second;
    int rmin = rightAns.first;
    int rmax = rightAns.second;
    int minimum = min(root->data,min(lmin,rmin));
    int maximum = max(root->data,max(lmax,rmax));
    pair<int, int> p;
    p.first = minimum;
    p.second = maximum;
    return p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    pair<int, int> p = getMinAndMax(root);
    cout << "Min = " << p.first << endl;
    cout << "Max = " << p.second << endl;
    return 0;
}