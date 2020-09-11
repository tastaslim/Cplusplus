// Since in PreOrder we traverse Generic tree in this manner:
// Left Right Root

#include "CommonTemplate.h"

TreeNode<int> *takeInput()
{
    int value;
    cout << "Enter node data:";
    cin >> value;
    queue<TreeNode<int> *> waiting;
    TreeNode<int> *root = new TreeNode<int>(value);
    waiting.push(root);
    while (!waiting.empty())
    {
        TreeNode<int> *front = waiting.front();
        waiting.pop();
        int num;
        cout << "Enter number of childrens of node " << front->data << ":";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int ch;
            cout << "Enter child " << i + 1 << " data of node " << front->data << ":";
            cin >> ch;
            TreeNode<int> *child = new TreeNode<int>(ch);
            front->children.push_back(child);
            waiting.push(child);
        }
    }
    return root;
}
// DFS ---> Recursive
/*
void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}
*/

// BFS ---> Iterative approach
void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    stack<TreeNode<int> *> s1;
    s1.push(root);
    stack<TreeNode<int> *> s2;
    while (!s1.empty())
    {
        TreeNode<int> *topper = s1.top();
        s2.push(topper);
        s1.pop();
        for (int i = 0; i < topper->children.size(); i++)
        {
            s1.push(topper->children[i]);
        }
    }

    while (!s2.empty())
    {
        TreeNode<int> *ans = s2.top();
        cout << ans->data << " ";
        s2.pop();
    }
}
int main()
{
    TreeNode<int> *root = takeInput();
    postOrder(root);
    return 0;
}