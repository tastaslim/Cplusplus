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

// Using recursion. We can also do it using Queue(Iteratively) which is very easy.
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

int findLevelOfNode(BinaryTreeNode<int> *root, int node, int level)
{
    if (!root)
    {
        return -1;
    }
    if (root->data == node)
        return level;
    int l = 0;
    l = findLevelOfNode(root->left, node, level + 1);
    if (l != -1)
        return l;
    return findLevelOfNode(root->right, node, level + 1);
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    // printAtLevelK(root, k);
    int ans = findLevelOfNode(root, k, 0);
    cout << ans << endl;
    return 0;
}