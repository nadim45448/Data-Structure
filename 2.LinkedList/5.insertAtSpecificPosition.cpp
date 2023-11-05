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
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; // 1 2 3 4
    }
    temp->next = newNode;
}
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void show(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->next != NULL)
        {
            cout << "->";
        }

        n = n->next;
    }
}
void insertAtSpecificPosition(Node *&head, int pos, int val)
{
    //Node *newNode=new Node(val);
    int i=1;
    Node *temp=head;
    while (i<pos-1)
    {
        temp=temp->next;
        i++;
        
    }
    Node *newNode=new Node(val);
    newNode->next=temp->next;
    temp->next=newNode;
    
}
int length(Node *n)
{
    int count = 0;
    while (n != NULL)
    {
        count++;
        n = n->next;
    }
    return count;
}

int main()
{
    Node *head = NULL;
    cout << "1. Insertion at Head" << endl;
    cout << "2. Insertion at Tail" << endl;
    cout << "3. Insertion at specific position" << endl;
    cout << "0. Exit" << endl<< endl;
    
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
            cout << "Enter the position:";
            cin >> position;
            cout << "Enter the value:";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "Next choice: ";
        cin >> choice;
    }
    cout << "Linked list: ";
    show(head);
    cout << endl;
    cout << "Length of the Linked list: " << length(head);
}