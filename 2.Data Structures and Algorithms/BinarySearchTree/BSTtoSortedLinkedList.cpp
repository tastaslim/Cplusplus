// Following is the Binary Tree node structure
#include "CommonTemplate.h"
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node<int> *ansh = NULL;
Node<int> *anst = NULL;
Node<int> *constructBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    constructBST(root->left);
    Node<int> *root1 = new Node<int>(root->data);
    if (!ansh)
    {
        ansh = root1;
        anst = root1;
    }
    else
    {
        anst->next = root1;
        anst = anst->next;
    }
    constructBST(root->right);
    return ansh;
}
int main()
{
    BinaryTreeNode<int> *root =
}