#include<iostream>
using namespace std;
int main()
{ //problem no 7
    int n;
    cout<<"Array size: ";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        if(ar[i]%3==0)
        {
            ar[i]=-1;
        }
    }
    cout<<"After replacement: ";
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
}
