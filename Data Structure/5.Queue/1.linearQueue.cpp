#include <bits/stdc++.h>
#define size 10
#define invalid -999
using namespace std;
class MyQueue
{
public:
    int queue[size];
    int front, rear;
    MyQueue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int element)
    {
        /* if(isFull())
         {
             cout<<"Queue already full...cannot enqueue"<<endl;
         }*/
        if (isEmpty())
        {
            front = rear = 0;
            queue[rear] = element;
        }
        else
        {
            rear++;
            queue[rear] = element;
        }
    }
    void dequeue()
    {
        /* if (isEmpty())
         {
             cout << "Queue already empty...cannot dequeue" << endl;
         } */
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    int getFrontElement()
    {
        if (isEmpty())
        {
            // cout << "Queue empty... nothing in front" << endl;
            return invalid;
        }
        else
        {
            return queue[front];
        }
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Nothing to print" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
    }
};

int main()
{
    MyQueue mq;

    bool repeat = true;
    bool empty, full;
    int element, frontElement;

    while (repeat)
    {
        cout << "What do you want to do?" << endl;
        cout << "1. Check Empty" << endl;
        cout << "2. Check Full" << endl;
        cout << "3. Enqueue an element" << endl;
        cout << "4. Dequeue an element " << endl;
        cout << "5. Check Front  element " << endl;
        cout << "6. Print Queue" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cout << "Enter tour choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            empty = mq.isEmpty();
            if (empty == true)
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Queue is not empty" << endl;
            }
            break;
        case 2:
            full = mq.isFull();
            if (full == true)
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                cout << "Queue is not full" << endl;
            }
            break;

        case 3:
            full = mq.isFull();
            if (full == true)
            {
                cout << "Queue is full. Cannot enqueue" << endl; // overflow
            }
            else
            {
                cout << "Enter an element to enqueue:";
                cin >> element;
                mq.enqueue(element);
            }
            break;

        case 4:
            empty = mq.isEmpty();
            if (empty == true)
            {
                cout << "Queue is empty. Cannot dequeue" << endl; // underflow
            }
            else
            {
                mq.dequeue();
            }
            break;

        case 5:
            frontElement = mq.getFrontElement();
            if (frontElement == invalid)
            {
                cout << "Queue is empty. Nothing on front" << endl;
            }
            else
            {
                cout << "Front element: " << frontElement << endl;
            }
            break;

        case 6:

            mq.print();

            break;
        case 7:
            repeat = false;
            break;

        default:
            cout << "Invalild choice" << endl;
            break;
        }
        cout << endl;
    }
}