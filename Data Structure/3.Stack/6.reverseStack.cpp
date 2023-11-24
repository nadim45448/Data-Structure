#include<bits/stdc++.h>
#include"4.myStack.h"
using namespace std;
void insertAtBottom(Stack<int>&chk,int checkElement)
{
    if(chk.empty())
    {
        chk.push(checkElement);
        return;
    }
    int t=chk.topElement();
    chk.pop();
    insertAtBottom(chk,checkElement);
    chk.push(t);

}
void reverseStack(Stack<int>&chk)
{
    if(chk.empty())
    {
        return;
    }
    int peak=chk.topElement();
    chk.pop();
    reverseStack(chk);
    insertAtBottom(chk,peak);
    
}
int main()
{
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
     reverseStack(st);


    while(!st.empty())
    {
       cout<<st.pop()<<endl;
      
        // cout<<st.topElement()<<endl;
        // st.pop();
    }
}
