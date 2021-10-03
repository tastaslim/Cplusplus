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
void printLevelATNewLine(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> waiting;
    waiting.push(root);
    int count = 1;
    while (!waiting.empty())
    {
        int n = waiting.size();
        while (n--)
        {
            BinaryTreeNode<int> *front = waiting.front();
            waiting.pop();
            if (count >= k1 && count <= k2)
            {
                cout << front->data << " ";
            }
            else if (count > k2)
                break;
            if (front->left)
                waiting.push(front->left);
            if (front->right)
                waiting.push(front->right);
        }
        if (count >= k1 && count <= k2)
            cout << endl;
        count++;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int l1, l2;
    cin >> l1 >> l2;
    printLevelATNewLine(root, l1, l2);
    delete root;
}