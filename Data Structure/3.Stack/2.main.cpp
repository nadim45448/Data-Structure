#include <bits/stdc++.h>
#include "2.stackUsingDoublyLinkedList.h"
using namespace std;
int main()
{
    Stack st;
   
    //cout<<"value "<<st.pop()<<" popped"<<endl;

    st.push(10);
  
    st.push(20);
    st.push(30);
    cout<<st.topElement()<<endl;

    st.pop();
     st.pop();
     cout<<st.topElement()<<endl;
     



    return 0;
    
}