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
        root->rightChild=insertionBST(root->rightChild, value);
    }
    return root;
}
void inOrder(treeNode* root, string &chk)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->leftChild,chk);
    chk+=(to_string(root->data)+" ");
    inOrder(root->rightChild,chk);

}
treeNode* searchBST(treeNode* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        cout<<root->data;
        return root;
    }
    else if(key<root->data)
    {
        cout<<root->data<<"->";
        searchBST(root->leftChild,key);
    }
    else
    {
        cout<<root->data<<"->";
        root=searchBST(root->rightChild,key);
    }
}
int main()
{
    treeNode* root=NULL;
    int n;
    cout<<"Enter total number of node:";
    cin>>n;
    cout<<"enter value"<<endl;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        root=insertionBST(root,value);

    }
    string traversal="";
    inOrder(root,traversal);
    cout<<traversal<<endl;
    int key;
    cout<<"Enter value:";
    cin>>key;
    if(searchBST(root,key)==NULL)
    {
        cout<<endl<<"value does not exist in the BST"<<endl;
    }
    else
    {
         cout<<endl<<"value  exist in the BST"<<endl;
    }
    

}
/* 
10
22 11 15 45 70 9 34 94 5 47 
*/