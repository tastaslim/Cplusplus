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
void printVerticalOrder(BinaryTreeNode<int> *root, map<int, vector<int>> &mp)
{
    if (!root)
        return;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<BinaryTreeNode<int> *, int> k = q.front();
        BinaryTreeNode<int> *front = k.first;
        int temp = k.second;
        q.pop();
        mp[temp].push_back(front->data);
        if (front->left)
        {
            q.push(make_pair(front->left, k.second - 1));
        }

        if (front->right)
        {
            q.push(make_pair(front->right, k.second + 1));
        }
    }
}

void printVerticalOrder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    map<int, vector<int>> mp;
    printVerticalOrder(root, mp);
    for (auto &itr : mp)
    {
        for (int i = 0; i < itr.second.size(); i++)
        {
            cout << itr.second.at(i) << " ";
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printVerticalOrder(root);
    cout << endl;
    return 0;
}