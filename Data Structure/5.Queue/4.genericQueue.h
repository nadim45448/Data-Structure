#include <bits/stdc++.h>
using namespace std;
template<typename N>
class Node
{
public:
    N value;
    Node *next;
    Node(N val)
    {
        value = val;
        next = NULL;
    }
};
template <typename Q>
class Queue
{
    public:
    Node<Q> *front;
    Node<Q> *rear;
    Queue()
    {
        front=NULL;
        rear=NULL;
    }

    void push(Q val) // enqueue-->push
    {
        Node<Q> *newNode=new Node<Q>(val);
        if(front==NULL)
        {
            front=newNode;
            rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=rear->next;
    }

    Q pop() //dequeue-->pop
    {
        Q chk;
        if(rear==NULL)
        {
            return chk;
        }
        Node<Q> *delNode;
        
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
    Q getFrontElement()
    {
        Q chk;
        chk=front->value;
        return chk;
    }
    Q back()
    {
         Q chk;
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
