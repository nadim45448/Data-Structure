#include<iostream>
using namespace std;
void print(int arr[],int n)
{
     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int size;
    cout<<"Enter array size:";
    cin>>size;
    int arr[size];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Before sort: ";
    print(arr,size);

    //step1 find maximum elements
    int max=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    //step2 initialization of 'count' array;
    int count[max+1]={0};

    //step3  frequency calculation of each element
    for(int i=0;i<size;i++)
    {
        count[arr[i]]++;
    }

    //step4 cumulative sum
    for(int i=1;i<=max;i++)
    {
        count[i]+=count[i-1];
    }

    //step5 final array ---> backward traversal of basic array
    int finalAr[size];
    for(int i=size-1;i>=0;i--)
    {
       count[arr[i]]--;
          int k=count[arr[i]];
          finalAr[k]=arr[i];
    }
    cout<<endl<<"after sort: ";
    print(finalAr,size);



}
