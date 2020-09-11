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

#include <bits/stdc++.h>

// Works for unique elements in tree only

/*
unordered_map<int,int> mp;
void nodesSumToS(BinaryTreeNode<int> *root,int sum)
{
    if(!root)
        return;
    nodesSumToS(root->left,sum);
    mp[root->data]++;
    if(mp[sum-root->data])
    {
        int l=mp[root->data]*mp[sum-root->data];
        while(l--)
        {
            cout<<min(sum-root->data,root->data)<<" "<<max(sum-root->data,root->data)<<endl;
        }
        mp[sum-root->data]=0,mp[root->data]=0;
    }
    nodesSumToS(root->right,sum);
}
*/

// Works for duplicates as well

int k = 0;
void nodesSumToSHelper(BinaryTreeNode<int> *root, int *arr)
{
    if (!root)
        return;
    nodesSumToSHelper(root->left, arr);
    arr[k] = root->data;
    k = k + 1;
    nodesSumToSHelper(root->right, arr);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum)
{
    int arr[1000000];
    nodesSumToSHelper(root, arr);
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        int temp = sum - arr[i];
        if (mp.find(temp) != mp.end())
        {
            int count = mp[temp];
            while (count--)
            {
                cout << min(sum - arr[i], arr[i]) << " " << max(sum - arr[i], arr[i]) << endl;
            }
        }
        mp[arr[i]]++;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    return 0;
}