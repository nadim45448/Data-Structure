#include<iostream>
using namespace std;
int main()
{
    //Intersection
    int n,m;
    cout<<"Enter size for array 1:";
    cin>>n;
    cout<<"Enter size for array 2:";
    cin>>m;
    int ar1[n],ar2[m];
    cout<<"Enter elements for array 1:";
    for(int i=0;i<n;i++)
    {
        cin>>ar1[i];
    }
    cout<<endl;
    cout<<"Enter elements for array 2:";
    for(int i=0;i<m;i++)
    {
        cin>>ar2[i];
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ar1[i]==ar2[j])
            {

                cout<<ar1[i]<<" ";
                flag=1;


            }
        }
    }
    if(flag==0)
        cout<<"EMPTY SET"<<endl;


}
