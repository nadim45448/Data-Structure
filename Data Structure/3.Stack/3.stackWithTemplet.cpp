#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Node
{
public:
    T value;
    Node *prev;
    Node *next;
    Node(T val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};
template<typename ST>
class Stack
{
public:
    Node<ST> *head;
    Node<ST> *top;
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    void push(ST val)
    {
        Node<ST> *newNode =new Node<ST>(val);
        if(head==NULL)
        {
            head=top=newNode;
            return;
        }
        else
        {
            top->next=newNode;
            newNode->prev=top;
            top=newNode;
        }
    }

    ST pop()
    {
        Node<ST> *delNode;
        delNode = top;
        ST popElement;
        if(head==NULL)
        {
            cout<<"Stack underflow"<<endl;
            return popElement;
        }
        if(head==top)
        {
            head=top=NULL;
            
        }
        else
        {
            top=delNode->prev;
            top->next=NULL;
        }
        popElement=delNode->value;
        delete delNode;
        return popElement;
       
    }
    ST topElement()
    {
        ST t;
        if(head==NULL)
        {
            cout << "nothing on top" << endl;
            return t;
        }
        else
        {
            return top->value;
        }
    }

    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
   Stack<char> st;
    Stack<double>st1; //Stack<double> st1=new Stack<double>()


   st.push('a');
    st.push('b');
    st.push('c');
    cout<<st.topElement()<<endl;
    st.pop();
//    // st.pop();
//     //cout<<st.topElement()<<endl;
    while(!st.empty())
    {
        cout<<st.pop()<<endl;
    }


    st1.push(5.5);
    st1.push(7.5);
    st1.push(8.5);
    cout<<st1.topElement()<<endl;
    st1.pop();
    st1.pop();
    cout<<st1.topElement()<<endl;

    // stack of pair
    Stack<pair<int, char>> stt;
  
    stt.push(make_pair(1,'a'));
    stt.push(make_pair(2,'b'));
    stt.push(make_pair(3,'c'));
    while(!stt.empty())
    {
        pair<int,char>chk;
        chk=stt.pop();
        cout<<chk.first<<"|"<<chk.second<<endl;
    }
    if(!stt.empty())
    {
        pair<int,char>top;
        top=stt.topElement();
        cout<<top.first<<"|"<<top.second<<endl;
    }
   
    
    





}