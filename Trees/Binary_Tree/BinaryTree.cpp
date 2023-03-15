#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

Node *takeInputLevelWise()
{
    // we will use queue to enter data
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return nullptr;
    }
    Node *root = new Node(rootData);
    queue<Node *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        Node *frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child data of: " << frontNode->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            Node *child = new Node(leftChildData);
            frontNode->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child data of: " << frontNode->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            Node *child = new Node(rightChildData);
            frontNode->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

Node *takeInput()
{
    cout << "Enter data: ";
    int data;
    cin >> data;
    if (data == -1)
        return nullptr;
    Node *root = new Node(data);
    Node *leftChild = takeInput();
    Node *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
Node *newNode(int data)
{
    Node *newNode = new Node(data);
    return (newNode);
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int numNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ans = 0;
    ans = numNodes(root->left) + numNodes(root->right);
    return (1 + ans); // return 1 + numNodes(root->left) + numNodes(root->right);
}
int sumNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    int sum = 0;
    //
    return sum;
}
bool isNodePresent(Node *root, int x)
{
    // Write your code here
    if (root == nullptr)
        return false;
    queue<Node *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        Node *front = pendingNodes.front();
        pendingNodes.pop();
        if (front->data == x)
        {
            return true;
        }
        if (front->left != nullptr)
        {
            if (front->left->data == x)
                return true;
            pendingNodes.push(front->left);
        }
        if (front->right != nullptr)
        {
            if (front->right->data == x)
                return true;
            pendingNodes.push(front->right);
        }
    }
    return false;
}

void printLevelWise(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        Node *frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout << frontNode->data << ":";
        if (frontNode->left != nullptr)
        {
            cout << frontNode->left->data << ",";
            pendingNodes.push(frontNode->left);
        }
        else if (frontNode->left == nullptr)
        {
            cout << "L:"
                 << "-1"
                 << ",";
        }
        if (frontNode->right != nullptr)
        {
            cout << frontNode->right->data;
            pendingNodes.push(frontNode->right);
        }
        else if (frontNode->right == nullptr)
        {
            cout << "R:"
                 << "-1";
        }
        cout << "\n";
    }
}
void printTree(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    if (root->left != nullptr)
    {
        cout << "L: " << root->left->data;
    }
    if (root->right != nullptr)
    {
        cout << "R: " << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
int main(int argc, char const *argv[])
{
    // Node *root = new Node(1);
    // Node *node1 = new Node(2);
    // Node *node2 = new Node(3);
    // Node *root = takeInput();
    Node *root = takeInputLevelWise();
    printTree(root);
    int ans = numNodes(root);
    cout << "Num of nodes: " << ans;
    delete root;
    return 0;
}