#include <iostream>
#define size 10
#define invalid -9999
using namespace std;
class myStack
{public:

    int stack[size];
    int top;


    myStack()
    {
        top = 0;
    }

    bool isEmpty()
    {
        if (top == 0)
        {
            return true;
        }
        else
            return false;
    }
    bool isFull()
    {
        if(top==size)
        {
            return true;
        }
        else 
        return false;
    }
    void push(int element)
    {
        if(isFull())
        {
            cout<<"Stack is full. cannot push"<<endl;
        }
        else
        {
            stack[top]=element;
            top++;
            cout<<"successfully pushed"<<endl;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty.. cannot pop"<<endl;
        }
        else
        {
            top--;
            cout<<"Popped succesfully"<<endl;
        }
    }
    int getTopElement()
    {
        if(isEmpty())
        {
            cout<<"stack is empty..nothing on top"<<endl;
            return invalid;
        }
        else
        {
            return stack[top-1];
        }
    }
   /* void print()
    {
        if(isEmpty())
        {
            cout<<"stack is empty..nothing to print"<<endl;
            
        }
        else
        {
            cout<<"Stack elements:"<<endl;
            for(int i=top-1;i>=0;i--)
            {
                cout<<stack[i]<<endl;
            }
        }
    }*/
};
void print(myStack ms)
    {
        if(ms.isEmpty())
        {
            cout<<"stack is empty..nothing to print"<<endl;
            
        }
        else
        {
            cout<<"Stack elements:"<<endl;
            for(int i=ms.top-1;i>=0;i--)
            {
                cout<<ms.stack[i]<<endl;
            }
        }
    }

int main()
{
    myStack ms;
    cout<<ms.isEmpty()<<endl;
    cout<<ms.isFull()<<endl;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);
    int a=ms.getTopElement();
    cout<<"Top element:"<<a<<endl;
    ms.push(6);
    ms.push(7);
    ms.push(8);
    ms.push(9);
    ms.push(10);
    ms.push(1);

    print(ms);

    ms.pop();
    ms.pop();
    ms.pop();
    ms.pop();
    ms.pop();
    ms.pop();
    ms.pop();
    ms.pop();
    ms.pop();
    ms.pop();
    ms.pop();
    
   a=ms.getTopElement();
    cout<<"Top element:"<<a<<endl;

    print(ms);
}
