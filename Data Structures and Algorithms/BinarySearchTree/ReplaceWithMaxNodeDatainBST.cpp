#include "CommonTemplate.h"
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode->data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode->data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// Using Global Variable k

/*int k = 0;
int replaceWithLargerNodesSumHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return k;
    k = replaceWithLargerNodesSumHelper(root->right);
    k = k + root->data;
    root->data = k;
    replaceWithLargerNodesSumHelper(root->left);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    int sum = replaceWithLargerNodesSumHelper(root);
}

*/

// using Pass by Reference k
int replaceWithLargerNodesSumHelper(BinaryTreeNode<int> *root, int &k)
{
    if (root == NULL)
        return k;
    k = replaceWithLargerNodesSumHelper(root->right, k);
    k = k + root->data;
    root->data = k;
    replaceWithLargerNodesSumHelper(root->left, k);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    int sum = 0;
    sum = replaceWithLargerNodesSumHelper(root, sum);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    return 0;
}