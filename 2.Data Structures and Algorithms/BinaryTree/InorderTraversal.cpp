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

// Using recursion ---> DFS

// void Inorder(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return;
//     Inorder(root->left);
//     cout << root->data << " ";
//     Inorder(root->right);
// }

// Iterative using 1 stack only

void Inorder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    stack<BinaryTreeNode<int> *> s;
    BinaryTreeNode<int> *temp = root;
    while (temp)
    {
        s.push(temp);
        temp = temp->left;
    }
    while (!s.empty())
    {
        BinaryTreeNode<int> *front = s.top();
        s.pop();
        cout << front->data << " ";
        if (front->right)
        {
            BinaryTreeNode<int> *temp = front->right;
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
        }
    }
}
// Using 1 stack and 1 HashMap
/*
void Inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    unordered_map<BinaryTreeNode<int> *, int> mp;
    stack<BinaryTreeNode<int> *> s;
    s.push(root);
    while (!s.empty())
    {
        BinaryTreeNode<int> *front = s.top();
        if (front == NULL)
        {
            s.pop();
            continue;
        }
        if (mp[front] == 0)
            s.push(front->left);
        else if (mp[front] == 1)
            cout << front->data << " ";
        else if (mp[front] == 2)
            s.push(front->right);
        else
            s.pop();

        mp[front]++;
    }
}
*/
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Inorder(root);
    delete root;
}