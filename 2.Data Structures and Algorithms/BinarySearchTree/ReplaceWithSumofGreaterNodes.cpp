/*
Replace with Sum of greater nodes
Send Feedback
Given a binary tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
You don't need to return or print, just change the data of each node.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Output format : Elements are printed in level order wise, every level in new line

Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1 :
18 
36 10 
38 31 
25
*/

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
}