#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode 
{
    public :
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        delete left;    
        delete right;
    }
};

template <typename T>
class Node 
{
    public :
    T data;
    Node<T>* next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

void printLinkedList(Node<int>* head) {
    Node<int>* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp =  temp->next;
    }
    cout << endl;
}

BinaryTreeNode<int> *takeInput()
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

// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> ans;    
    if (root == NULL) {
        ans.push_back(NULL);
        return ans;
    }
    queue<BinaryTreeNode<int>*> q;
    queue<BinaryTreeNode<int>*> q2;
    q.push(root);
    q.push(NULL);
    q2.push(root);
    q2.push(NULL);
    while (q.size() > 1 || q.front() != NULL) {
        while (q.front() != NULL) {
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            if (front->left != NULL) {
                q.push(front->left);
                q2.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
                q2.push(front->right);
            }
        }
        q.pop();
        q.push(NULL);
        q2.push(NULL);
    }
    while (q2.size() > 1 || q2.front() != NULL) {
        BinaryTreeNode<int>* front = q2.front();
        Node<int>* head = new Node<int>(front->data);
        Node<int>* temp = head;
        ans.push_back(head);
        q2.pop();
        while (q2.front() != NULL) {
            BinaryTreeNode<int>* f = q2.front();
            Node<int>* newNode = new Node<int>(f->data);
            temp->next = newNode;
            temp = newNode;
            q2.pop();
        }
        q2.pop();
    }
    
    return ans;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    vector<Node<int>*> arr = constructLinkedListForEachLevel(root);

    for (int i = 0; i < arr.size(); i++) {
        printLinkedList(arr[i]);
    }
    return 0;
}