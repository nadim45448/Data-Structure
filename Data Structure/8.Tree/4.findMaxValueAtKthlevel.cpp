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
int levelOrder(treeNode *root, int k)
{
    if(root==NULL)
    {
        return-1;
    }
    int level=0,max=-9999;
    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        treeNode *chkNode=q.front();
        q.pop();
       if(chkNode!=NULL)
       {
        if(level==k)
        {
            if(max<chkNode->data)
            {
                max=chkNode->data;
            }
        }
            cout<<chkNode->data<<" ";
            if(chkNode->leftChild!=NULL)
            {
                q.push(chkNode->leftChild);
            }
             if(chkNode->rightChild!=NULL)
            {
                q.push(chkNode->rightChild);
            }
       }
       else
       {
            if(!q.empty())
            {
                q.push(NULL);
                level++;
            }
       }
    }
    return max;
    
}
int main ()
{
    int n;
    cin>>n;
    treeNode *allnode[n];
    for(int i=0;i<n;i++)
    {
        allnode[i]=new treeNode(-1);
    }
    for(int i=0;i<n;i++)
    {
        int val,left,right;
        cin>>val>>left>>right;
        allnode[i]->data=val;
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
    int maxvalueAtK=levelOrder(allnode[0],3);
    cout<<endl<<maxvalueAtK<<endl;
}