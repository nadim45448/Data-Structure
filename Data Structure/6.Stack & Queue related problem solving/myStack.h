#include <bits/stdc++.h>
using namespace std;
template <typename T>
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
template <typename ST>
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
        Node<ST> *newNode = new Node<ST>(val);
        if (head == NULL)
        {
            head = top = newNode;
            return;
        }
        else
        {
            top->next = newNode;
            newNode->prev = top;
            top = newNode;
        }
    }

    ST pop()
    {
        Node<ST> *delNode;
        delNode = top;
        ST popElement;
        if (head == NULL)
        {
            //cout << "Stack underflow" << endl;
            return popElement;
        }
        if (head == top)
        {
            head = top = NULL;
        }
        else
        {
            top = delNode->prev;
            top->next = NULL;
        }
        popElement = delNode->value;
        delete delNode;
        return popElement;
    }
    ST topElement()
    {
        ST t;
        if (head == NULL)
        {
           // cout << "nothing on top" << endl;
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

    ST mid()
    {
        ST error;
        if (head == NULL)
        {
            return error;
        }
        Node<ST> *slow = head;
        Node<ST> *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->value;
    }
};