#include<bits/stdc++.h>
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
void printLeaves(treeNode *root) //left & right leaves
{
    if(root==NULL)
    {
        return;
    }
    if(root->leftChild==NULL && root->rightChild==NULL)
    {
        cout<<root->data<<" ";
        return;
    }
    printLeaves(root->leftChild);
     printLeaves(root->rightChild);

}
void printLeftNonLeaves(treeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->leftChild!=NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
    else if(root->rightChild!=NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
}
void printrightNonLeaves(treeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->rightChild!=NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
    else if(root->leftChild!=NULL)
    {
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
}
void boundaryTraversal(treeNode *root)
{
   if(root==NULL)
   {
        return;
   }
    cout<<root->data<<" ";

    //LB Non-leaves
    printLeftNonLeaves(root->leftChild);

    // LB leaves
    printLeaves(root->leftChild);

    //RB leaves
    printLeaves(root->rightChild);
    
    //RB Non-leaves
    printrightNonLeaves(root->rightChild);
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
        if (left > n - 1 || right > n - 1)
        {
            cout << "Invalid index" << endl;
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
    boundaryTraversal(allnode[0]);
}