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
        int flag =0;
        cout<<"Iteration "<<i<<endl;
        for(int j=0;j<n-i;j++) //step 1->j<size-i-1
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
            PrintArray(arr,n);
            cout<<endl;

        }
        if(flag==0)
            break;
            cout<<endl;

    }
    cout<<endl<<"After bubble sort:";
    PrintArray(arr,n);
    cout<<endl;
}

