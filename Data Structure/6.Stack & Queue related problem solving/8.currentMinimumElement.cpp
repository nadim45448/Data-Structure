#include<bits/stdc++.h>
#include"myStack.h"
using namespace std;
/*
test case:
5
1 2 3 4 5
7
1 6 43 1 2 0 5
10
6 5 5 5 4 7 1 2 1 2

*/

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Stack<int>st;
    Stack<int>minStack;
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=min)
        {
            minStack.push(arr[i]);
            min=arr[i];
        }
        st.push(arr[i]);
    }
    while(!st.empty())
    {
        if(st.topElement()!=minStack.topElement())
        {
        //    st.pop();
        //     cout<<minStack.topElement()<<endl;
            cout<<"Popping "<<st.pop()<<": current min in the stack is "<<minStack.topElement()<<endl;
        }
        else
        {
            // cout<<minStack.topElement()<<endl;
            // minStack.pop();
            // st.pop();
            cout<<"Popping "<<st.pop()<<": current min in the stack is "<<minStack.topElement()<<endl;
            minStack.pop();
        }
    }

    
}