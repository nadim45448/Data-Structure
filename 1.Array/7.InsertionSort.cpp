#include<iostream>
using namespace std;
void PrintArray(int ar[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
}

int main()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int ar[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Before insertion sort: ";
    PrintArray(ar,n);
    cout<<endl<<endl;

    //Insertion Sort
    for(int i=1;i<n;i++)
    {

        int key=ar[i];
        cout<<"i= "<<i<<" key= "<<key<<endl;
        int j=i-1;
        while(j>=0 && ar[j]>key)
        {
            ar[j+1]=ar[j];
            PrintArray(ar,n);
            cout<<endl;
            j--;
        }
        ar[j+1]=key;
        PrintArray(ar,n);
        cout<<endl;
    }
    cout<<"After insertion sort: ";
    PrintArray(ar,n);
    cout<<endl;


}
