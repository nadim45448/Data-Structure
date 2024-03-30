#include<bits/stdc++.h>
using namespace std;
int main()
{
    //map <int, int> m;
    unordered_map<int,int>m;
    m[3]=9;
    m[2]=3;
    m.insert(make_pair(1,4));
    cout<<"key | Value"<<endl; 
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    return 0;
}