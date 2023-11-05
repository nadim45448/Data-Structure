#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"Enter the array size: ";
    cin>>size;
    int arr[size];

    cout<<"Enter array elements"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int value,flag=0;
    cout<<"Enter the value you want to search:";
    cin>>value;

      for(int i=0;i<size;i++)
    {
      if(arr[i]==value)
      {
          flag=1;
          cout<<i<<"th index, "<<i+1<<"th position"<<endl;
      }
    }
    if(flag==0)
    {
        cout<<value<<" not found"<<endl;
    }
}
