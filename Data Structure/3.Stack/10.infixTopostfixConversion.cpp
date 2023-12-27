#include<bits/stdc++.h>
#include"4.myStack.h"
using namespace std;
int precisionCalc(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
        return -1;
}

string infixToPostfix(string chk)
{
    Stack<char>st;
    string result; // postfix expression
    for(int i=0;i<chk.length();i++)
    {
        if(chk[i]>='0' && chk[i]<='9') // 'a' to 'z' && 'A' to 'Z'
        {
            result+=chk[i];
        }
        else if(chk[i]=='(')
        {
            st.push(chk[i]);
        }
        else if(chk[i]==')')
        {
            while (!st.empty() && st.topElement()!='(')
            {
                result+=st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precisionCalc(st.topElement())>=precisionCalc(chk[i]))
            {
                result+=st.pop();
            }
            st.push(chk[i]);
            
        }
    }

    while(!st.empty())
    {
        result+=st.pop();
    }
    return result;
}
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
    string infix="(4*(3+5))-(2+0)"; // (7+(4*5))-(2+0)      9*[7-1+(5+1/2)*3-{(6+3)-8}+4]
    string postfix;
    postfix=infixToPostfix(infix);
    cout<<endl<<postfix<<endl<<endl<<postfixEvaluation(postfix);
}