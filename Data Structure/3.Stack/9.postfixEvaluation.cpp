#include<bits/stdc++.h>
#include"4.myStack.h"
using namespace std;

int postfixEvaluation(string chk)
{
    Stack<int>st;
    for(int i=0;i<chk.length();i++)
    {
        if(chk[i]>='0' && chk[i]<='9')
        {
            st.push(chk[i]-'0');
        }

        else
        {
            int a=st.pop();
            int b=st.pop();
            switch (chk[i])
            {
            case '+':
              st.push(b+a);
                break;
                case '-':
              st.push(b-a);
                break;
                case '*':
              st.push(b*a);
                break;
                case '/':
              st.push(b/a);
                break;
                case '^':
              st.push(pow(b,a));
                break;
            
            default:
                break;
            }
        }
    }
    return st.topElement();
}
int main()
{
    cout<<endl<<postfixEvaluation("971-512/+3*+63+8--4+*");
    
}