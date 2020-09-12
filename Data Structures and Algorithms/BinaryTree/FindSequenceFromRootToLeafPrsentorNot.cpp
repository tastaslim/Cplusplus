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

bool checkPatternSequence(BinaryTreeNode<int>* root, int *arr, int size, int index)
{
    if(root==NULL)
       return;
    if(arr[index]!=root->data || index==size)
    {
        return false;
    }
    if(root->left==NULL && root->right==NULL)
    {
        if(arr[size-1]==root->data)
           return true;
    }
    return checkPatternSequence(root->left,arr,size,index+1)||checkPatternSequence(root->right,arr,size,index+1);
}
int main()
{
    BinaryTreeNode<int>*root=takeInput();
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    bool m=checkPatternSequence(root,arr,n,0);
    if(m)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    return 0;
}