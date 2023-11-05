#include<iostream>
using namespace std;
int BinarySearch(int arr[],int value,int low,int high)
{
   /* while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==value) //centre
        {
            return mid;
        }
        else if(value<arr[mid])
        {
            high=mid-1; //value before mid(left side)
        }
        else
        {
            low=mid+1; // value after mid(right side)
        }


    } */
    //2. Recursive way.........
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==value)  //centre
        {
            return mid;

        }
        else if(value<arr[mid])
        {
            BinarySearch(arr,value,low,mid-1);//left
        }
        else
        {
            BinarySearch(arr,value,mid+1,high); //right
        }
    }
    else
    return -1;

}
int main()
{
    int sizee;
    cout<<"Array size:";
    cin>>sizee;
    int arr[sizee];
    int low=0,high=sizee-1;
    for(int i=0;i<sizee;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array elements:";
     for(int i=0;i<sizee;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int value;
    cout<<"Enter value:";
    cin>>value;
    int index=BinarySearch(arr,value,low,high);
    if(index!=-1)
    {
        cout<<"Index:"<<index<<" position:"<<index+1<<endl;
    }
    else
    {
        cout<<value<<" not found"<<endl;

    }
}
