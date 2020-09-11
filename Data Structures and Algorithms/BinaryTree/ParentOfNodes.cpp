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

void PrintParent(BinaryTreeNode<int>* root, int x)
{
  if(!root || x==root->data)
    return;
  unordered_map<int,BinaryTreeNode<int> *>mp;
  queue<BinaryTreeNode<int> *>q;
  q.push(root);
  while(!q.empty())
  {
    BinaryTreeNode<int> *front=q.front();
    q.pop();
    if(front->left)
    {
      q.push(front->left);
      mp[front->left->data]=front;
    }
    if(front->right)
    {
      q.push(front->right);
      mp[front->right->data]=front;
    }
  }
  cout<<mp[x]->data<<endl;
}

int main()
{
  BinaryTreeNode<int> *root=takeInput();
  int x;
  cin>>x;
  PrintParent(root,x);
  return 0;
}
