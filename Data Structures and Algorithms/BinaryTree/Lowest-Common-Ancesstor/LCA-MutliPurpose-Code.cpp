//With the help of this method, you can find any node path from root, check whether a given node is ansesstor of
// our path node or not
// Print all ancestors of a given node including node itself
// You can find path to all leaves from root by doing minute modification.
// you can find kth anscestor as well

#include "../CommonTemplate.h"
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
bool m = false;
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, vector<int> &v, vector<int> &v2, int k)
{
    if (root == NULL)
        return;
    v.push_back(root->data);
    rootToLeafPathsSumToK(root->left, v, v2, k);
    if (root->data == k) // For all leaves check: if(root->left==NULL && root->right==NULL)
    {
        for (int i = 0; i < v.size(); i++)
        {
            //if (v.size() - 2 == i) for lowest common ansector of given node
            //cout << v.at(i) << " "; // Prints all ansector of given node
            // if (v.at(i) == ans) for checking whether a node is ansector of given node or not
            //     m = true;
            v2.push_back(v.at(i));
        }
    }
    rootToLeafPathsSumToK(root->right, v, v2, k);
    v.pop_back();
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, int k2, int count)
{
    vector<int> v, v1, v2;
    rootToLeafPathsSumToK(root, v, v1, k);
    rootToLeafPathsSumToK(root, v, v2, k2);
    int ans = -1;
    for (int i = 0; i < v1.size() && i < v2.size(); i++)
    {
        if (v2.at(i) == v1.at(i))
        {
            count--;
            if (count == 0)
                ans = v2.at(i);
        }
    }
    cout << ans << endl;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int k, k1;
    cin >> k >> k1;
    int count;
    cout << "Enter which ansesctor to find:";
    cin >> count;
    rootToLeafPathsSumToK(root, k, k1, count);
    return 0;
}
