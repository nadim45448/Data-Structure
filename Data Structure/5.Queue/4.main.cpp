#include<bits/stdc++.h>
#include"4.genericQueue.h"
using namespace std;
typedef pair<int,int>mytype;

int main()
{
    Queue<mytype> q;// Queue<int> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
          // int val;
         // cin>>val;
         // q.push(val);
         int c1,c2;
         cin>>c1>>c2;
        q.push(make_pair(c1,c2));

    }

    while (!q.empty())
    {
        //cout<<q.pop()<<" ";
        mytype chk;
        chk=q.pop();
        cout<<chk.first<<"|"<<chk.second<<endl;

    }
    cout<<endl;

    if(!q.empty())
    {
       // cout<<q.getFrontElement()<<endl;
       mytype chk;
        chk=q.getFrontElement();
        cout<<chk.first<<"|"<<chk.second<<endl;
    }
     if(!q.empty())
    {
        //cout<<q.back()<<endl;
        mytype chk;
        chk=q.back();
        cout<<chk.first<<"|"<<chk.second<<endl;
    }
    
}