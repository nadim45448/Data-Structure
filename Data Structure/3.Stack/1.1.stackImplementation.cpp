#include <iostream>
#define size 10
#define invalid -9999
using namespace std;
class myStack
{
public:
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
        if (top == size)
        {
            return true;
        }
        else
            return false;
    }
    void push(int element)
    {
        stack[top] = element;
        top++;
        cout << "successfully pushed" << endl;
    }
    void pop()
    {
            top--;
            cout << "Popped succesfully" << endl;
        
    }
    int getTopElement()
    {
        if (isEmpty())
        {
            
            return invalid;
        }
        else
        {
            return stack[top - 1];
        }
    }
    void print()
    {
            cout << "Stack elements:" << endl;
            for (int i = top - 1; i >= 0; i--)
            {
                cout << stack[i] << endl;
            }
       
    }
};

int main()
{
    myStack ms;

    bool repeat = true;
    bool empty, full;
    int element, topElement;
    while (repeat)
    {
        cout << "What do you want to do?" << endl;
        cout << "1. Check Empty" << endl;
        cout << "2. Check Full" << endl;
        cout << "3. Push an element" << endl;
        cout << "4. Pop an element " << endl;
        cout << "5. Check Top  element " << endl;
        cout << "6. Print stack" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            empty = ms.isEmpty();
            if (empty == true)
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }

            break;
        case 2:
            full = ms.isFull();
            if (full == true)
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }

            break;
        case 3:
            full = ms.isFull();
            if (full == true)
            {
                cout << "Stack is full. Cannot push" << endl;//overflow
            }
            else
            {
                cout << "Enter an elementb to push:";
                cin >> element;
                ms.push(element);
            }
            break;
        case 4:
            empty = ms.isEmpty();
            if (empty == true)
            {
                cout << "Stack is empty. Cannot pop" << endl;//underflow
            }
            else
            {
                ms.pop();
            }
            break;
        case 5:
            topElement = ms.getTopElement();
            if (topElement == invalid)
            {
                cout << "Stack is empty. Nothing on top" << endl;
            }
            else
            {
                cout << "Top element: " << topElement << endl;
            }
            break;
        case 6:
            empty = ms.isEmpty();
            if (empty == true)
            {
                cout << "Stack is empty. Nothing to print" << endl;
            }
            else
            {
                ms.print();
            }

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
