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

unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>mp;
void Ansector(BinaryTreeNode<int>* root)
{
    if(!root)
      return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    mp[root]=NULL;
    while(!q.empty())
    {
        BinaryTreeNode<int>*front=q.front();
        q.pop();
        if(front->left)
        {
            q.push(front->left);
            mp[front->left]=front;
        }

        if(front->right)
        {
            q.push(front->right);
            mp[front->right]=front;
        }
    }
}

void printNodes(BinaryTreeNode<int>*root, BinaryTreeNode<int>*node, int k)
{
    if(!node)
       return;
    Ansector(root);
    queue<BinaryTreeNode<int>*>q;
    unordered_set<BinaryTreeNode<int>*>s;
    q.push(node);
    s.insert(node);

    while(!q.empty())
    {
        if(k==0)
        {
            while(!q.empty())
            {
                cout<<q.front()->data<<" ";
                q.pop();
            }
        }
        int n=q.size();
        while(n--)
        {
            BinaryTreeNode<int>*front=q.front();
            q.pop();
            if(front->left && s.find(front->left)==s.end())
            {
                q.push(front->left);
                s.insert(front->left);
            }
            if(front->right && s.find(front->right)==s.end())
            {
                q.push(front->right);
                s.insert(front->right);
            }
            if(s.find(mp[front])==s.end() && mp[front])
            {
                q.push(mp[front]);
                s.insert(mp[front]);
            }
        }
        k=k-1;
    }
}

int main()
{
    BinaryTreeNode<int>* root=takeInput();
    printNodes(root,root->left,2);
    return 0;
}