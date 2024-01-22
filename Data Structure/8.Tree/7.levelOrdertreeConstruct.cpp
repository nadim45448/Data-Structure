// level order tree construction
// this is another representation of 1, 1.1, 2
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
void print(Node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val<<" ";
    print(root->right);
}
int main()
{

    int a;
    cin >> a;
    Node *root = new Node(a);

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *presentRoot = q.front();
        q.pop();
        int leftval, rightVal;
        cin >> leftval >> rightVal;
        Node *n1 = NULL;
        Node *n2 = NULL;
        if (leftval != -1)
        {
            n1 = new Node(leftval);
        }
        if (rightVal != -1)
        {
            n2 = new Node(rightVal);
        }
        presentRoot->left = n1;
        presentRoot->right = n2;
        if (n1 != NULL)
        {
            q.push(n1);
        }
        if (n2 != NULL)
        {
            q.push(n2);
        }
    }

    print(root);
}