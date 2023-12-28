#include<bits/stdc++.h>
#include"myStack.h"
using namespace std;
bool checkParenthesis(string chk)
{
    int size=chk.size();
    Stack<char>st;
    bool isBalanced=true;
if(chk[0]==')'||chk[0]=='}'||chk[0]==']')
{
    return false;
}

    for(int i=0;i<size;i++)
    {
        if(chk[i]=='('||chk[i]=='{'||chk[i]=='[')
        {
            st.push(chk[i]);
        }
        else if(chk[i]==')')
        {
            if(st.topElement()=='(')
            {
                st.pop();
            }
            else
            {
                isBalanced=false;
                break;
            }
        }
        else if(chk[i]=='}')
        {
            if(st.topElement()=='{')
            {
                st.pop();
            }
            else
            {
                isBalanced=false;
                break;
            }
        }
        else if(chk[i]==']')
        {
            if(st.topElement()=='[')
            {
                st.pop();
            }
            else
            {
                isBalanced=false;
                break;
            }
        }
    }
    if(!st.empty())
    {
        isBalanced=false;
    }
    return isBalanced;
}
int main()
{
    
    string s="[({}])"; //  [()]{}{[()()]()}           9*[7-1+(5+1/2)*3-{(6+3)-8}+4]
    bool result=checkParenthesis(s);
    if(result==true)
    {
        cout<<"valid expression"<<endl;
    }
    else
    {
        cout<<"invalid expression"<<endl;
    }
}