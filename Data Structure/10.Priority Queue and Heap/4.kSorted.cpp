#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PAIR;
int main()
{
    int k;
    cin>>k;
    vector<vector<int>> allvalues(k);
  //input
    for(int i=0;i<k;i++)
    {
        int size;
        cin>>size;
        allvalues[i]=vector<int>(size);
        for(int k=0;k<size;k++)
        {
            cin>>allvalues[i][k];
        }
    }

    // index tracker
    vector<int>indexTracker(k,0);
    priority_queue<PAIR,vector<PAIR>, greater<PAIR>>pq;

    // initialisation of pq
    for(int i=0;i<k;i++)
    {
        pq.push(make_pair(allvalues[i][0],i));
    }
    vector<int>ans;
    // main logic of heap
    while (!pq.empty())
    {
        PAIR x=pq.top();
        pq.pop();
        ans.push_back(x.first);
        if (indexTracker[x.second]+1<allvalues[x.second].size()) // increment position validity check
        {
            pq.push(make_pair(allvalues[x.second][indexTracker[x.second]+1],x.second));
            //we are creating a pair:(increment position value, increment position array identity)
            // then push in pq
        }
        indexTracker[x.second]+=1;

    }
    cout<<endl;
    // print ans
    for(auto element: ans)
    {
        cout<<element<<" ";
    }
    cout<<endl<<endl;

}
/*
3 -> k array
3 ->size of array 1
1 4 7 ->elements of array 1
2-> size of array 2
2 5 ->elements of array 2
3 ->size of array 3
2 6 7 -> elements of array 3


3
3
1 4 7
2
3 5
3
2 6 7
*/
