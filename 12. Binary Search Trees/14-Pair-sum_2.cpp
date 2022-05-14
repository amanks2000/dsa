#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild); 
            currentNode->right = rightNode; 
            q.push(rightNode);
        }
    }
    return root;
}

void getVector(BinaryTreeNode<int>* root, vector<int> *arr) {
    if (root == NULL) {
        return;
    }
    arr->push_back(root->data);
    getVector(root->left, arr);
    getVector(root->right, arr);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> *arr = new vector<int>();
    getVector(root, arr);
    sort(arr->begin(), arr->end());
    // for (int  i = 0; i < arr->size(); i++) {
    //     cout << arr->at(i) << " ";
    // }

    int i = 0, j = arr->size()-1;
    while (i < j) 
    {
        if (arr->at(i) + arr->at(j) == sum) {
            cout << arr->at(i) << " " << arr->at(j) << endl;
            i++;
            j--;
        }
        else if (arr->at(i) + arr->at(j) < sum) {
            i++;
        }
        else {
            j--;
        }

    }
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    return 0;
}