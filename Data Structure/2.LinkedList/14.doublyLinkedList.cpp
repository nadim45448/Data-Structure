#include <iostream>
using namespace std;
class doublyNode
{
public:
    int value;
    doublyNode *prev;
    doublyNode *next;
    doublyNode(int val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtTail(doublyNode *&head, int val);
void insertAtHead(doublyNode *&head, int val);
void show(doublyNode *n);
int length(doublyNode *n);
void displayReverse(doublyNode *&head);
void insertAtSpecificPosition(doublyNode *&head, int val, int pos);

void insertAtTail(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertAtHead(doublyNode *&head, int val)
{
    // step 1
    doublyNode *newNode = new doublyNode(val);
    // step 2
    head->prev = newNode;
    // step 3
    newNode->next = head;
    // step 4
    head = newNode;
}
void show(doublyNode *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->next != NULL)
        {
            cout << "--->";
        }
        n = n->next;
    }
}
int length(doublyNode *n)
{
    int count = 0;
    while (n != NULL)
    {
        count++;
        n = n->next;
    }
    return count;
}
void displayReverse(doublyNode *&head)
{
    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->prev != NULL)
        {
            cout << "--->";
        }
        temp = temp->prev;
    }
}
void insertAtSpecificPosition(doublyNode *&head, int val, int pos)
{
    doublyNode *newNode = new doublyNode(val);

    if (pos == 1)
    {
        insertAtHead(head, val);
    }
    else
    {
        doublyNode *temp = head;
        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

int main()
{
    doublyNode *head = NULL;

    cout << "1. Insertion at Head" << endl;
    cout << "2. Insertion at Tail" << endl;
    cout << "3. Insertion at Specific Position" << endl;
    cout << "0. Exit" << endl
         << endl;

    cout << "Your choice: ";
    int choice;
    cin >> choice;
    int value, position;

    while (choice != 0)
    {

        switch (choice)
        {
        case 1:
            cout << "Enter the value:";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value:";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter the value:";
            cin >> value;
            cout << "Enter the position:";
            cin >> position;
            insertAtSpecificPosition(head, value, position);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "Next choice: ";
        cin >> choice;
    }

    cout << "Doubly Linked list: ";
    show(head);
    cout << endl;
    cout << "Doubly Linked list(Reversly): ";
    displayReverse(head);
    cout << endl;
    cout << "Length of the Doubly Linked list: " << length(head);
}