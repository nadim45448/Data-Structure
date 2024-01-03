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
        data=val;
        leftChild=NULL;
        rightChild=NULL;
    }

};
int main()
{
    int n;
    cout<<"enter number f node:";
    cin>>n;
    treeNode *allnode[n];
    for(int i=0;i<n;i++)
    {
        allnode[i]->data=-1;
    }

    for(int i=0;i<n;i++)
    {
        int val,left,right;
        cin>>val>>left>>right;
        allnode[i]->data=val;
        if(left!=-1)
        {
            allnode[i]->leftChild=allnode[left];
        }
        if(right!=-1)
        {
            allnode[i]->rightChild=allnode[right];
        }
    }
    
    return 0;
}