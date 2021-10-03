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

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = max(height(root->left), height(root->right));
    return ans + 1;
}

void printAtLevelK(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        k = k + 1;
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
}
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    int m = height(root);
    // LevelOrdered Print
    for (int K = 0; K < m; K++)
    {
        printAtLevelK(root, K);
        cout << endl;
    }

    // ReverseLevelOrdered Print
    for (int K = m - 1; K >= 0; K--)
    {
        printAtLevelK(root, K);
        cout << endl;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);
    return 0;
}