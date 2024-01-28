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
treeNode *insertionBST(treeNode *root, int val)
{
    treeNode *newNode = new treeNode(val);
    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    if (val < root->data)
    {
        root->leftChild = insertionBST(root->leftChild, val);
    }
    else if (val > root->data)
    {
        root->rightChild = insertionBST(root->rightChild, val);
    }
    return root;
}
void inOrder(treeNode *root, string &chk)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->leftChild, chk);
    chk += (to_string(root->data) += " ");
    inOrder(root->rightChild, chk);
}
treeNode* findMin(treeNode* root)
{
    while (root->leftChild!=NULL)
    {
        root=root->leftChild;
        
    }
    return root;
    
}
treeNode *deletion(treeNode *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else if (val < root->data)
    {
        root->leftChild = deletion(root->leftChild, val);
    }
    else if (val > root->data)
    {
        root->rightChild = deletion(root->rightChild, val);
    }
    else // find the value, now delete
    {
        // case 1: Leaf node->no child
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2: One child
        else if(root->leftChild==NULL)
        {
            treeNode* temp=root;
            root=root->rightChild;
            delete temp;
        }
        else if(root->rightChild==NULL)
        {
            treeNode* temp=root;
            root=root->leftChild;
            delete temp;
        }
        //case 3: Two child
        else
        {
            // find the minumum element from right sub tree or find the largest element from left subtree
            //find min from right subtree
            treeNode* temp=findMin(root->rightChild);
            root->data=temp->data;
            root->rightChild=deletion(root->rightChild,temp->data);



        }
    }
    return root;

    
    
}
int main()
{
    treeNode *root = NULL;
    int n;
    cout << "Enter total number of node:";
    cin >> n;
    cout << "Enter value:" << endl;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insertionBST(root, val);
    }
    string traversal = "";
    inOrder(root, traversal);
    cout << traversal<<endl;

    int deleteVal;
    cout<<"Enter the value you want to delete:";
    cin>>deleteVal;
    root=deletion(root,deleteVal);

    string afterDelete = "";
    inOrder(root, afterDelete);
    cout << afterDelete<<endl;
}
/*
10
22 11 15 45 70 9 34 94 5 47
9
11 5 9 43 34 1 2 7 21
*/