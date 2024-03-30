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

void verticalOrder(treeNode *root, int d, map<int,vector<int>>&m)
{
    if(root==NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    verticalOrder(root->leftChild,d-1,m);
    verticalOrder(root->rightChild,d+1,m);
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
   
    map<int,vector<int>>m;
    verticalOrder(allnode[0],0,m);
    for(auto i:m)
    {
        cout<<i.first<<": ";
        for(int j=0;j<(i.second).size();j++)
        {
            cout<<(i.second)[j]<<" ";
        }
        cout<<endl;
    }
}
/*
9 
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
*/