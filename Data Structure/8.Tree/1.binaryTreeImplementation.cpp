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
    // step 1
    if (root == NULL) // tree is null or empty
    {
        return;
    }
    if (root->leftChild == NULL && root->rightChild == NULL) // step 3. this will happen after recursive call
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
    // step2
    // cout<<"Root:"<<root->data<<endl;
    /*spaceprint(level);
    cout<<"Left:";
    printTree(root->leftChild,level+1);

    spaceprint(level);
    cout<<"Right:";
    printTree(root->rightChild,level+1); */
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
    for (int i = 0; i< level; i++)
    {
        cout << "   ";
    }
}
int main()
{
    int n;
    cout << "enter number of node:";
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
            cout<<"Invalid index"<<endl;
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

    printTree(allnode[0], 0);

    return 0;
}
/*
9 (total number of node)
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root:1
left:
    root:1
    left:3
    right:4
Right:
    root:2
    left:
        root:5
        left:7
        right:8
    right:6


*/