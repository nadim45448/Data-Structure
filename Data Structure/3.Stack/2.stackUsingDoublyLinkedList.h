#include <bits/stdc++.h>
#define invalid -1;
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
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }

    // PUSH
    void push(int val)
    {
        // step 1: newNode creation
        Node *newNode = new Node(val);

        // step 2: check whether head is null or not. if head is null, that's mean stack is empty.
        if (head==NULL)
        {
            head = top = newNode;
            count++;
            cout<<"1st element pushed "<<top->value<<endl;

            return;
        }
       
        
            top->next = newNode;
            newNode->prev = top;
            top = newNode; // top=top->next
            cout<<count+1<<"st element pushed "<<top->value<<endl;
            count++;
        
    }
    // POP
    int pop()
    {
        Node *delNode ;
        delNode= top;
        int popValue = -1;
        if (head == NULL) // there is no element on the stack.
        {
            cout << "stack is empty. Nothing to pop" << endl; // underflow
            return popValue;
        }
        if (top == head) // there is only 1 value in the stack
        {
            head=NULL;
            top=NULL;
            count--;
            cout<<"head pop"<<endl;
        }
        else // there is more than one value in the stack
        {
            delNode->prev = top;
            top->next = NULL;
            cout<<"top pop"<<endl;
        }
        popValue = delNode->value;
        delete delNode;
        count--;
        return popValue;
    }

   /*
  // EMPTY
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

    // GET TOP ELEMENT
    int topElement()
    {
        if (head == NULL)
        {
            cout << "Stack is empty. Nothing on top" << endl;
            return invalid;
        }
        else
        {
            return top->value;
        }
    }
    // SIZE CALCULATION
    int size()
    {
        return count;
    }
    */
};
