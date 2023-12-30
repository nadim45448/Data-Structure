#include<bits/stdc++.h>
#include<vector>
using namespace std;

void printVector(vector<int>v)
{
    for(int i=0; i<v.size(); i++)
    {

        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>v;
    //    v[0]=20; //error, this is not valid declaration/initialization in vector
    //    v[1]=30;
    //    cout<<v.size()<<endl;
//    cout<<v.capacity();
    //cout<<v.max_size();

    //cout<<v.empty()<<endl;

    v.push_back(1);// valid
    v.push_back(7);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);
    v.push_back(8);
    v.push_back(2);
    //v[0]=10;// valid becz v[0] is now present

    //cout<<v.empty();

    // =================resize====================
//    v.resize(5); // after resize, size will be decrease but value will not delete from memory
//    printVector(v);
//    v.shrink_to_fit();// to delete/clear from memory

    //=============== iterator============================
    // iterator is a pointer
   // vector<int>::iterator it; // declaration
    //it=v.end()-1; // begin(), end(), rbegin(), rend()
    //cout<<*it<<endl;
    //vector<int>::reverse_iterator itt;
//    itt=v.rbegin();
//    cout<<*itt<<endl;

//    for(auto it=v.begin();it!=v.end();it++) // if use auto, we do not need to declare the iterator type
//    {
//        cout<<*it<<" ";
//    }
    //======Element Access=============
//    for(int i=0; i<v.size()+2; i++)
//    {
//
//        cout<<v.at(i)<<" ";
//    }
//    cout<<endl;
//    cout<<v[0]<<endl;
//    cout<<v.front()<<endl;
//    cout<<v.back()<<endl;
//    cout<<v.size()<,endl;
//    cout<<v[v.size()-1]<<endl;
//v.pop_back();
//printVector(v);
//v.clear();
//printVector(v);
//v.insert(v.begin()+1,100);
//printVector(v);
//v.insert(v.begin()+1,3,100);
//printVector(v);
//v.erase(v.begin()+1,v.begin()+4);
//printVector(v);
//sort(v.begin(),v.end());
//printVector(v);
//reverse(v.begin(),v.end());
//printVector(v);


//=========taking input============
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    //cin>>v[i]; //vector<int>v(n)
    int a;
    cin>>a;
    v.push_back(a);
}
printVector(v);








}
