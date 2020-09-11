#include "CommonTemplate.h"
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data:";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int ans[100000];
int k = 0;
void helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        ans[k] = front->data;
        k = k + 1;
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root, bool m)
{
    if (!root)
        return;
    int sum = 0;
    if (m)
    {
        helper(root);
        m = false;
    }
    for (int i = 0; i < k; i++)
    {
        if (ans[i] >= root->data)
            sum = sum + ans[i];
    }
    root->data = sum;
    replaceWithLargerNodesSum(root->left, m);
    replaceWithLargerNodesSum(root->right, m);
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    replaceWithLargerNodesSum(root, true);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    return 0;
}