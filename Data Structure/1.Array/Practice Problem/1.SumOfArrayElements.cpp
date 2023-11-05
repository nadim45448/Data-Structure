#include<bits/stdc++.h>
using namespace std;
void ReverseArray(int *ar,int n)
{
    int i=0, j=n-1; //question 3

        while(i<j)
        {
            int temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
            i++;
            j--;
        }

}
int main()
{
    int n;
    cout<<"Array size:";
    cin>>n;
    int ar[n];
    int sum=0;
    int even_index_sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        sum+=ar[i]; //question 1
        if(i%2==0)
        {
            even_index_sum+=ar[i]; //question 2
        }
    }
    cout<<"sum="<<sum<<endl;
    cout<<"Even Indexed Sum="<<even_index_sum<<endl;

    ReverseArray(ar,n); //question 3
    cout<<"after reverse: ";
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }

    //question 4;
    int maxx=-999,minn=999;
    int max_index,min_index;
    for(int i=0;i<n;i++)
    {
        if(maxx<ar[i])
        {
            maxx=ar[i];
            max_index=i;
        }
        if(minn>ar[i])
        {
            minn=ar[i];
            min_index=i;

        }
    }
    cout<<endl<<"Maximum: "<<maxx<<" Index: "<<max_index<<endl;
    cout<<"Minimum: "<<minn<<" Index: "<<min_index<<endl<<endl;

    //question 5
    int value;
    cout<<"Which value do you want to search?";
    cin>>value;
    int flag=0;
    for(int i=0;i<n;i++)
    { Flag:
        if(value==ar[i])
        {
            cout<<"FOUND at index position "<<i<<endl;
            flag=1;
        }
    }

    if(flag==0)
    {
        cout<<"NOT FOUND"<<endl;
    }

}
