#include<bits/stdc++.h>
using namespace std;
void PrintArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before sorting: ";
    PrintArray(arr,n);

    // Implementation
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
         if(min!=i)
         {
             swap(arr[i],arr[min]);
             PrintArray(arr,n);
             cout<<endl;
         }
    }
     cout<<"After sorting: ";
    PrintArray(arr,n);

}
