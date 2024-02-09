#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PAIR;

int main()
{
    priority_queue<int,vector<int>>pq;
    pq.push(1);
    pq.push(5);
    pq.push(2);

    while (!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    cout<<endl;
//Minimum priority queue
    priority_queue<int,vector<int>,greater<int>>p;
    p.push(1);
    p.push(5);
    p.push(2);

    while (!p.empty())
    {
        cout<<p.top()<<endl;
        p.pop();
    }
    cout<<endl<<endl;
    //Pair
    priority_queue<PAIR,vector<PAIR>,greater<PAIR>>n;
    n.push(make_pair(1,9));
    n.push(make_pair(6,2));
    n.push(make_pair(4,1));
    while (!n.empty())
    {
        cout<<n.top().first<<"|"<<n.top().second<<endl;
        n.pop();
    }
    


    
}