#include<bits/stdc++.h>
using namespace std;
int main()
{
    // make identity matrix
    int n;
    cout<<"Enter row,column size:";
    cin>>n;
    int arr[n][n];
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {
            if(r==c)
            {
                arr[r][c]=1;
            }
            else
            arr[r][c]=0;

        }
    }

    //show elements
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {

            cout<<arr[r][c]<<"  ";
        }
        cout<<endl;
    }
}
