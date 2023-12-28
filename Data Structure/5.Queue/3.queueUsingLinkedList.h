#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

class Queue
{
    public:
    Node *front;
    Node *rear;
    Queue()
    {
        front=NULL;
        rear=NULL;
    }

    void push(int val) // enqueue-->push
    {
        Node *newNode=new Node(val);
        if(front==NULL)
        {
            front=newNode;
            rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=rear->next;
    }

    int pop() //dequeue-->pop
    {
        if(rear==NULL)
        {
            return -1;
        }
        Node *delNode;
        int chk;
        delNode=front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        chk=delNode->value;
        delete delNode;
        return chk;

    }

    // peek --> front(),back()
    int getFrontElement()
    {
        int chk;
        chk=front->value;
        return chk;
    }
    int back()
    {
         int chk;
        chk=rear->value;
        return chk;
    }
    bool empty()
    {
        if(front==NULL && rear==NULL)
        {
            return true;
        }
        else
         return false;
    }
};
