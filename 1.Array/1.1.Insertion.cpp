#include<bits/stdc++.h>
using namespace std;
void ShowArray(int arr[],int n)
{
    cout<<"Array elements: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Insertion(int arr[],int n)
{
    int pos,value;
    cout<<"enter position:";
    cin>>pos;
    if(pos<0 || pos>n)
    {
        cout<<"Invalid Index!"<<endl;
    }
    cout<<"Enter value:";
    cin>>value;
    //array: 2 4 5 6 3    2 4 5 6 3 ?

    arr[n-1]=arr[pos];
    arr[pos]=value;
    cout<<"After Insertion:";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
int main()
{
    int arr[15];
    int sizee;
    cout<<"Enter array size:";
        cin>>sizee;
        cout<<"Enter array elements:"<<endl;
        for(int i=0;i<sizee;i++)
        {
            cin>>arr[i];
        }
         ShowArray(arr,sizee);
        Insertion(arr,sizee+1);
}
