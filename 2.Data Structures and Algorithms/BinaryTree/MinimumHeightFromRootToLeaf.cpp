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

int Minheight(BinaryTreeNode<int>* root)
{
   if(!root)
      return 0;
   queue<BinaryTreeNode<int> *>q;
   q.push(root);
   int h=0;
   while(!q.empty())
   {
     int n=q.size();
     while(n!=0)
     {
        BinaryTreeNode<int> *front=q.front();
        if(!front->left && !front->right)
           return h;
        q.pop();
        if(front->left)
          q.push(front->left);
        if(front->right)
          q.push(front->right);
        n=n-1;
     }
     h=h+1;
   }
   return h;
}

int main()
{
   BinaryTreeNode<int> *root=takeInput();
   int ans=Minheight(root);
   cout<<ans<<endl;
   return 0;
}
