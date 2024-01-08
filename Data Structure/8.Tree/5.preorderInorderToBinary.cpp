#include <bits/stdc++.h>
using namespace std;
class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};
void preOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    chk += to_string(root->data);
    preOrder(root->leftChild, chk);
    preOrder(root->rightChild, chk);
}
int searchInorder(int inorder[], int current, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (current == inorder[i])
        {
            return i;
        }
    }
    return -1;
}
treeNode *buildTreePreIn(int preorder[], int inorder[], int start, int end)
{
    static int ind = 0;
    int current = preorder[ind];
    ind++;
    treeNode *newNode = new treeNode(current);
    if(start==end)
    {
        return newNode;
    }
    int pos = searchInorder(inorder, current, start, end);
    newNode->leftChild = buildTreePreIn(preorder, inorder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preorder, inorder, pos + 1, end);

    return newNode;
}
int main()
{
    int n;
    cin >> n;
    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    treeNode *rootNode = buildTreePreIn(preorder, inorder, 0, n - 1);
    string pre_order="";
    preOrder(rootNode,pre_order);
    cout<<endl<<pre_order<<endl;
}
/*
input:
9
Pre order :0 1 3 4 2 5 7 8 6
In order :3 1 4 0 7 5 8 2 6
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

*/
