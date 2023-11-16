#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};
class Stack
{
    Node *head;
    Node *top;

public:
    
    Stack()
    {
        head = NULL;
        top = NULL;
    }
int count = 0;
    // PUSH
    void push(int val)
    {
        Node *newNode = new Node(val); // newNode creation
        // head is null
        if (head == NULL)
        {
            head = newNode;
            top = newNode;
            count++;
        }
        else
        {
            top->next = newNode;
            newNode->prev = top;
            top = newNode;
            count++;
        }
    }

    // POP
    void pop()
    {
        Node *delNode;
        delNode = top;
        

        //there is no element in the stack
        if (head == NULL && top == NULL)
        {
            cout << "There is no value in the stack. Nothing to pop" << endl;
            return; 
          
        }
        // there is one element in the stack
        if (top == head)
        {
            head = NULL;
            top = NULL;
        }
        else
        {
          
            top=delNode->prev;
            top->next = NULL;
        }

      
        delete delNode;
        count--;
       
    }

    // // Empty
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
            return false;
    }
    int topValue()
    {
        if (head == NULL)
        {
            cout << "nothing on top" << endl;
            return -999;
        }
        else
            return top->value;
    }

    int size()
    {
        return count;
    }

    // print
    void show()
    {
        while (top != NULL)
        {
            cout << top->value << endl;
            top = top->prev;
        }
    }
};

int main()
{
    Stack st;


    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.topValue()<<endl;
    st.pop();
    st.pop();
    cout<<st.topValue()<<endl;
//      cout<<"length:"<<st.size()<<endl;
//     st.push(4);
//     st.push(5);
//     st.pop();
//    st.show();
//     cout<<"length:"<<st.size()<<endl;


  
    
   
}