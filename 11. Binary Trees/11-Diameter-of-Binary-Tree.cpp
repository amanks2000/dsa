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

int height(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return 0;
    int ans = max(height(root->left), height(root->right));
    return ans+1;
}

// Not a good approach, Time complexity = O(n^2)
int diameter(BinaryTreeNode<int>* root) {
    if (root == NULL)
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}

// Better Approach, we return a pair containing both height and diameter
// Time Complexity = O(n)
pair<int,int> heightDiameter(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        pair<int, int> p;
        p.first = 0; // first -> height
        p.second = 0;// second -> diameter
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;  // lh -> left height
    int ld = leftAns.second; // ld -> left diameter
    int rh = rightAns.first; // rh -> right height
    int rd = rightAns.second;// rd -> right diamter

    int h = 1 + max(lh,rh); // actual height
    int d = max(lh+rh, max(ld,rd)); // actual diameter
    pair<int, int> p;
    p.first = h;
    p.second = d;
    return p;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "Diameter of Binary Tree = " << diameter(root) << endl;
    pair<int, int> p = heightDiameter(root);
    //cout << p.first << endl; // height of tree
    cout << "Diameter of Binary Tree (Better Approach) = " << p.second << endl;
    return 0;
}