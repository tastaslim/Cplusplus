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

/*
void PreorderTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
*/

// Using BFS LevelWise

// void PreorderTraversal(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return;

//     stack<BinaryTreeNode<int> *> s1;
//     stack<BinaryTreeNode<int> *> s2;
//     cout << root->data << " ";
//     s1.push(root);
//     while (!s1.empty())
//     {
//         BinaryTreeNode<int> *topper = s1.top();
//         s1.pop();
//         if (topper->left)
//         {
//             s1.push(topper->left);
//             cout << topper->left->data << " ";
//         }
//         if (topper->right)
//         {
//             s2.push(topper->right);
//         }
//     }

//     while (!s2.empty())
//     {
//         BinaryTreeNode<int> *topper = s2.top();
//         s2.pop();
//         cout << topper->data << " ";
//         if (topper->right)
//         {
//             s2.push(topper->right);
//         }
//         if (topper->left)
//         {
//             s2.push(topper->left);
//         }
//     }
// }
/*
void PreorderTraversal(BinaryTreeNode<int> *root)
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
            cout << front->data << " ";
        else if (mp[front] == 1)
            s.push(front->left);
        else if (mp[front] == 2)
            s.push(front->right);
        else
            s.pop();

        mp[front]++;
    }
}
*/

void PreorderTraversal(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    stack<BinaryTreeNode<int> *> s;
    s.push(root);
    while (!s.empty())
    {
        BinaryTreeNode<int> *front = s.top();
        s.pop();
        cout << front->data << " ";
        if (front->right)
            s.push(front->right);
        if (front->left)
            s.push(front->left);
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    PreorderTraversal(root);
    delete root;
}