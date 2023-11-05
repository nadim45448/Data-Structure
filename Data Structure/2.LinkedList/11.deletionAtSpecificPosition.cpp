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
struct Test
{
    int position[1000];
};

void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void insertAtSpecificPosition(Node *&head, int pos, int val);
int length(Node *n);
void show(Node *n);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void insertionByValue(Node *&head, int searchValue, int value);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int pos);

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
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void insertAtSpecificPosition(Node *&head, int pos, int val)
{
    Node *newNode = new Node(val);
    int i = 1;
    Node *temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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
int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    if (temp == NULL)
    {
        return -1;
    }
    int count = 1;
    while (temp->value != key)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return count;
}
void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int flag = 0;

    int size;
    size = length(head);
    int position[size + 1], k = 1;

    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            position[k] = count;
            k++;
            flag = 1;
        }
        temp = temp->next;
        count++;
    }
    if (flag == 0)
    {
        cout << "The searched value " << key << " is not yet in the list" << endl;
    }
    else
    {
        position[0] = k;
        cout << "The value " << key << " is at position: ";
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
            {
                cout << ",";
            }
        }
    }
}
Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;

    Test t;
    int k = 1;

    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            t.position[k] = count;
            k++;
        }
        temp = temp->next;
        count++;
    }
    t.position[0] = k;
    return t;
}
void insertionByValue(Node *&head, int searchValue, int value)
{
    // step 1: search the position of searched value
    int position = searchByValueUnique(head, searchValue);

    // step 2: insert the value at position+1
    insertAtSpecificPosition(head, position + 1, value);
}
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the Linked List" << endl;
    }
}
void deletionAtTail(Node *&head)
{
    Node *temp = head;
    // step 1
    if (temp != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        // step 2
        Node *delNOde = temp->next;
        // step 3
        temp->next = NULL;
        // step 4
        delete delNOde;
    }
    else
    {
        if (temp == NULL) // head is null
        {
            cout << "There is value in the linked list" << endl;
        }
        else
        { // head is tail
            deletionAtHead(head);
        }
    }
}
void deletionAtSpecificPosition(Node *&head, int pos)
{
    Node *temp = head;
    if (temp != NULL && pos<=length(head))
    {
        if(pos==1)
        {
            deletionAtHead(head);
        }
        else if(pos==length(head))
        {
            deletionAtTail(head); // this can also work in else option
        }
        else
        {
            int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        }
        
    }
    else
    {
        
        if(temp==NULL)
        {
            cout << "There is no value in the linked list" << endl;// LL is empty
        }
        else if(pos>length(head))
        {
            cout<<"position out of boundary"<<endl; //position ouut of range
        }
    }
    show(head);
    cout<<endl;
}
int main()
{
    Node *head = NULL;

    cout << "1. Insertion at Head" << endl;
    cout << "2. Insertion at Tail" << endl;
    cout << "3. Insertion at specific position" << endl;
    cout << "4. Search a value(Unique List)" << endl;
    cout << "5. Search a value(Duplicate enabled List)" << endl;
    cout << "6. Insertion after a specific value(unique list)" << endl;
    cout << "7. Deletion at Head" << endl;
    cout << "8. Deletion at Tail" << endl;
    cout << "9. Deletion at specific position" << endl;
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
            cout << "Enter the position:";
            cin >> position;
            cout << "Enter the value:";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;

        case 4:
            cout << "Enter the value you want to search:";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
            {
                cout << value << " is at position " << position << endl;
            }
            else
            {
                cout << value << " is not yet in the list" << endl;
            }
            break;
        case 5:
            cout << "Enter the value you want to search:";
            cin >> value;
            // searchByValueDuplicate(head,value);
            Test t;
            t = searchByValueDuplicateReturn(head, value);
            if (t.position[0] == 1)
            {
                cout << "The searched value " << value << " is not yet in the list" << endl;
            }
            else
            {
                int size = t.position[0];
                cout << "The value " << value << " is at position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << t.position[i];
                    if (i < size - 1)
                    {
                        cout << ",";
                    }
                }
            }
            cout << endl;

            break;
        case 6:
            cout << "Enter the value to search:";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert:";
            cin >> value;
            insertionByValue(head, searchValue, value);
            break;
        case 7:
            deletionAtHead(head);
            break;
        case 8:
            deletionAtTail(head);
            break;
        case 9:
            cout << "Entetr the position:";
            cin >> position;
            deletionAtSpecificPosition(head, position);
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