#include<bits/stdc++.h>
#include"3.queueUsingLinkedList.h"
using namespace std;
int main()
{
    Queue q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        q.push(val);

    }

   /* while (!q.empty())
    {
        cout<<q.pop()<<" ";
    }*/
    cout<<endl;

    if(!q.empty())
    {
        cout<<q.getFrontElement()<<endl;
    }
     if(!q.empty())
    {
        cout<<q.back()<<endl;
    }
    
}