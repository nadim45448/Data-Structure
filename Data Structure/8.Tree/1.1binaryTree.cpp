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
void printTree(treeNode *root, int level);
void spaceprint(int level);
void printTree(treeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
        return;
    }
    else
    {
        cout << endl;
        spaceprint(level);
        cout << "Root:" << root->data << endl;
    }
    if (root->leftChild != NULL)
    {
        spaceprint(level);
        cout << "Left:";
        printTree(root->leftChild, level + 1);
    }
    if (root->rightChild != NULL)
    {
        spaceprint(level);
        cout << "Right:";
        printTree(root->rightChild, level + 1);
    }
}
void spaceprint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "   ";
    }
}
int main()
{
    int n;
    cin >> n;
    treeNode *allnode[n];
    for (int i = 0; i < n; i++)
    {
        allnode[i] = new treeNode(-1);
    }
    for (int i = 0; i < n; i++)
    {
        int val, left, right;
        cin >> val >> left >> right;
        allnode[i]->data = val;
        if(left>n-1 || right>n-1)
        {
            cout<<"Invalild"<<endl;
            break;
        }
        if (left != -1)
        {
            allnode[i]->leftChild = allnode[left];
        }
        if (right != -1)
        {
            allnode[i]->rightChild = allnode[right];
        }
    }
    printTree(allnode[0],0);
    

    
    return 0;
}