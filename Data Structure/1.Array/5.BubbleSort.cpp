#include<iostream>
using namespace std;
PrintArray(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }


}
int main()
{
    int n;
    cout<<"Array size:";
    cin>>n;
    int arr[n];
    cout<<"enter array elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Bubble sort:";
    PrintArray(arr,n);
    cout<<endl;

    //implementation
    for(int i=1;i<n;i++)
    {
        cout<<"Iteration "<<i<<endl;
        for(int j=0;j<n-1;j++)
        {
             cout<<" step "<<j+1<<": ";
             PrintArray(arr,n);
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            cout<<"->";
            PrintArray(arr,n);
            cout<<endl;

        }
            cout<<endl;

    }
    //cout<<endl<<"After bubble sort:";
    PrintArray(arr,n);
    cout<<endl;
}
