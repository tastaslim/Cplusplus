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
unordered_map<int,bool>mp;
void answer(BinaryTreeNode<int>*root, int k,vector<int>&v)
{
    if(!root)
      return;
    v.push_back(root->data);
    answer(root->left,k,v);
    if(root->left==NULL && root->right==NULL)
    {
        int a=v.size()-1;
        if(a>=k && mp.find(v.at(a-k))==mp.end())
           cout<<v.at(a-k)<<" ";
        mp[v.at(a-k)]=true;
    }
    answer(root->right,k,v);
    v.pop_back();
}

int main()
{
    BinaryTreeNode<int>*root=takeInput();
    int k;
    cin>>k;
    vector<int>v;
    answer(root,k,v);
    return 0;
}