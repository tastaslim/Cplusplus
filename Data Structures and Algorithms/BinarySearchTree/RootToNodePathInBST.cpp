#include "CommonTemplate.h"

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data:";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    queue<BinaryTreeNode<int> *> waiting;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    waiting.push(root);
    while (!waiting.empty())
    {
        BinaryTreeNode<int> *front = waiting.front();
        waiting.pop();
        int leftChildData;
        cout << "Enter left child data of node " << front->data << ":";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            waiting.push(leftChild);
        }
        int rightChildData;
        cout << "Enter right child data of node " << front->data << ":";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            waiting.push(rightChild);
        }
    }
    return root;
}

vector<int> *findPath(BinaryTreeNode<int> *root, int data)
{
    vector<int> *v = new vector<int>();
    if (root == NULL)
        return NULL;
    if (root->data == data)
    {
        v->push_back(root->data);
        return v;
    }
    if (root->data > data)
    {
        vector<int> *leftPart = findPath(root->left, data);
        if (leftPart != NULL)
        {
            leftPart->push_back(root->data);
            return leftPart;
        }
    }

    if (root->data < data)
    {
        vector<int> *rightPart = findPath(root->right, data);
        if (rightPart != NULL)
        {
            rightPart->push_back(root->data);
            return rightPart;
        }
    }
    return NULL;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int data;
    cin >> data;
    vector<int> *ans = findPath(root, data);
    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << " ";
    }
    return 0;
}