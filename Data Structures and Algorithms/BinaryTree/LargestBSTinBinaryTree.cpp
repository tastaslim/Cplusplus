#include "CommonTemplate.h"
class Taslim
{
public:
    int height;
    bool isBST;
    int min;
    int max;
};

int count1 = 0;
int getfullCount(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int res = 0;
    if (root->left && root->right)
        res++;

    res += (getfullCount(root->left) +
            getfullCount(root->right));
    return res;
}
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
    bool bst = isLeftOk && isRightOk && (mini < root->data) && (maxi >= root->data); // We are considering that Right side can be equal to Root->data in BST(If duplicacy)

    if (bst)
    {
        count1++;
        int f = getfullCount(root);
        if (f > res)
            res = f;
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
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int ans = largestBSTSubtree(root);
    cout << ans << endl;
    //count<<count1<<endl; ----> It gives total number of Bst SubTree present in Binary Tree
    return 0;
}