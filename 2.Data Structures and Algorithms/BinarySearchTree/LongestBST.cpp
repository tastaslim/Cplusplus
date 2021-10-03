/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
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
// Brute Force Approach
// bool isBST(BinaryTreeNode<int> *root, int minimum, int maximum)
// {
//     if (root == NULL)
//         return true;
//     if (root->data > maximum || root->data < minimum)
//         return false;
//     bool isLeftOk = isBST(root->left, minimum, root->data - 1);
//     bool isRightOk = isBST(root->right, root->data, maximum);
//     return isLeftOk && isRightOk;
// }

// bool isBST(BinaryTreeNode<int> *root)
// {
//     return isBST(root, INT_MIN, INT_MAX);
// }

// int Height(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     int ans = 1 + max(Height(root->left), Height(root->right));
//     return ans;
// }

// int ans = 0;
// int largestBSTSubtree(BinaryTreeNode<int> *root)
// {
//     if (!root)
//         return 0;
//     bool m = isBST(root);
//     if (m)
//     {
//         int h = Height(root);
//         if (h > ans)
//             ans = h;
//     }
//     largestBSTSubtree(root->left);
//     largestBSTSubtree(root->right);
//     return ans;
// }

// O(n) approach
class Taslim
{
public:
    int height;
    bool isBST;
    int min;
    int max;
};

Taslim helper(BinaryTreeNode<int> *root, int &res)
{
    if (root == NULL)
    {
        Taslim t;
        t.height = 0;
        t.isBST = true;
        t.min = INT_MAX;
        t.max = INT_MIN;
        return t;
    }

    Taslim leftPart = helper(root->left, res);
    Taslim rightPart = helper(root->right, res);

    int mini = leftPart.max;
    int maxi = rightPart.min;
    bool isLeftOk = leftPart.isBST;
    bool isRightOk = rightPart.isBST;
    int leftHeight = leftPart.height;
    int rightHeight = rightPart.height;

    int finalmin = min(root->data, min(leftPart.min, rightPart.min));
    int finalmax = max(root->data, max(leftPart.max, rightPart.max));

    int h = 1 + max(leftHeight, rightHeight);
    bool bst = isLeftOk && isRightOk && (mini < root->data) && (maxi >= root->data);

    if (bst)
    {
        if (h > res)
            res = h;
    }

    Taslim ans;
    ans.min = finalmin;
    ans.max = finalmax;
    ans.isBST = bst;
    ans.height = h;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    int ans = 0;
    Taslim t = helper(root, ans);
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
