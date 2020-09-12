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

void Ansector(BinaryTreeNode<int>* root, int k)
{
    if(!root)
      return;
    queue<BinaryTreeNode<int>*> q;
    map<int,int>mp;
    q.push(root);
    mp[root->data]=-1;
    while(!q.empty())
    {
        BinaryTreeNode<int>*front=q.front();
        q.pop();
        if(front->left)
        {
            q.push(front->left);
            mp[front->left->data]=front->data;
        }

        if(front->right)
        {
            q.push(front->right);
            mp[front->right->data]=front->data;
        }
    }

    int ans=mp[k];
    while(ans!=-1)
    {
        cout<<ans<<" ";
        ans=mp[ans];
    }
}
int main()
{
    BinaryTreeNode<int>*root=takeInput();
    int num;
    cin>>num;
    Ansector(root,num);
    return 0;
}