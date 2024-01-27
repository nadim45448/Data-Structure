#include<bits/stdc++.h>
using namespace std;
class treeNode
{
    public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;
    treeNode(int val)
    {
        data=val;
        leftChild=NULL;
        rightChild=NULL;
    }
};

treeNode* insertionBST(treeNode* root, int value)
{
    treeNode* newNode=new treeNode(value);
    if(root==NULL)
    {
        root=newNode;
        return root;
    }
    if(value<root->data)
    {
        root->leftChild=insertionBST(root->leftChild,value);
    }
    else if(value>root->data)
    {
        root->rightChild=insertionBST(root->rightChild,value);
    }
    return root;
}
void inOrder(treeNode* root,string &chk)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->leftChild,chk);
    chk+=(to_string(root->data)+" ");
    inOrder(root->rightChild,chk);
}
int main()
{
   treeNode *root=NULL;
    int n;
    cout<<"enter total number of input:";
    cin>>n;
    cout<<"Enter value"<<endl;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
       // root=insertionBst(root,value);
       root=insertionBST(root,value);
    }
    string traversal="";
    inOrder(root,traversal);
    cout<<traversal;
}