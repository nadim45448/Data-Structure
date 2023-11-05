#include<bits/stdc++.h>
using namespace std;
void printArray(int *arr,int row,int col)
{
    for(int r=0;r<row;r++)
    {
        for(int c=0;c<col;c++)
        {
            //cout<<*(arr[r][c])<<"  ";
            //cout<<arr[r][c]<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    //int row,col;
    int n;
    cout<<"Enter row size & column size: ";
   // cin>>row>>col;
   cin>>n;
    int arr[n][n];
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {
            cin>>arr[r][c];
        }
    }
    //printArray(*arr,row,col);
    cout<<endl<<"Array elements:"<<endl;
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {

            cout<<arr[r][c]<<"  ";
        }
        cout<<endl;
    }
    //major diagonal
    cout<<"Major diagonal:";
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {
            if(r==c)
            {
                cout<<arr[r][c]<<" ";
            }


        }

    }
     cout<<endl;
     cout<<"Minor diagonal:";
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<n;c++)
        {
            if(r+c==(n-1))
            {
                cout<<arr[r][c]<<" ";
            }


        }

    }
     cout<<endl;



}
