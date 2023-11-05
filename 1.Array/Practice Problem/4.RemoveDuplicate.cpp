#include<iostream>
using namespace std;

   /* for(int i=0;i<n;i++) // 3 3 3
    {
        for(int j=i+1;j<=n;j++)
        {
            if(ar[i]==ar[j])
            {
                if(j==n-1)//i=0,j=2
                {
                    n--;  //i=0 j=2// n=2
                }

                else

                {
                    ar[j]=ar[j+1];
                    // i=0,j=1

                }
            }
            else if(ar[i]==ar[n-1])
            {
                n--;
            }
        }
    } */
void Duplicate(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] == ar[j])
            {
                // Swap the duplicate element with the last element in the array.
                ar[j] = ar[n - 1];
                n--;
                j--;
            }
        }
    }

    cout<<"After remove duplicate element: ";
    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int ar[n];
    cout<<"array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Before remove duplicate element: ";
        for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    Duplicate(ar,n);
    /*cout<<"After remove duplicate element: ";
           for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }*/

}
