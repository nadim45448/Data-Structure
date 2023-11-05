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
    int position[100];
};

int length(Node *n);
void show(Node *n);
void insertionAtHead(Node *&head, int val);
void insertionAtTail(Node *&head, int val);
void insertionAtSpecificPosition(Node *&head, int pos, int val);
int searchByUniqueValue(Node *&head, int key);
void searchByDuplicateValue(Node *&head, int key);
Test searchByDuplicateValueReturn(Node *&head, int key);
void insertionByValue(Node *&head, int searchValue, int val);
void deletionAtHead(Node *&head);
void deletionAtTail(Node *&head);
void deletionAtSpecificPosition(Node *&head, int pos);
void deletionByValue(Node *&head, int val);
void deletionByDuplicateValue(Node *&head, int val);

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
void insertionAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    newNode->next = temp;
    head = newNode;
}
void insertionAtTail(Node *&head, int val)
{
    Node *temp = head;
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertionAtSpecificPosition(Node *&head, int pos, int val)
{
    Node *temp = head;
    Node *newNode = new Node(val);
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int searchByUniqueValue(Node *&head, int key)
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
void searchByDuplicateValue(Node *&head, int key)
{
    Node *temp = head;
    int flag = 0;
    int size = length(head);
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
Test searchByDuplicateValueReturn(Node *&head, int key)
{
    Node *temp = head;
    Test t;
    int count = 1, k = 1;
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
void insertionByValue(Node *&head, int searchValue, int val)
{
    int position = searchByUniqueValue(head, searchValue);
    insertionAtSpecificPosition(head, position + 1, val);
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
    if (temp != NULL && temp->next != NULL)
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "There is no value in the list" << endl;
        }
        else
        {
            deletionAtHead(head);
        }
    }
}
void deletionAtSpecificPosition(Node *&head, int pos)
{
    Node *temp = head;
    if (pos == 1)
    {
        deletionAtHead(head);
    }
    else if (pos == length(head))
    {
        deletionAtTail(head);
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
void deletionByValue(Node *&head, int val)
{
    int position = searchByUniqueValue(head, val);
    if (position == -1)
    {
        cout << val << " not found in the linked list" << endl;
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
}
void deletionByDuplicateValue(Node *&head, int val)
{
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == val)
        {
            int position = searchByUniqueValue(temp, val);
            if (position != -1)
            {
                deletionAtSpecificPosition(temp, position);
            }
           
        }
         temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;

    cout << "1. Insertion at Head" << endl;
    cout << "2. Insertion at Tail" << endl;
    cout << "3. Insertion at specific position" << endl;
    cout << "4. Search a value (Unique List)" << endl;
    cout << "5. Search a value (Duplicate List)" << endl;
    cout << "6. Insertion after a specific value (Unique List)" << endl;
    cout << "7. Deletion at Head" << endl;
    cout << "8. Deletion at Tail" << endl;
    cout << "9. Deletion at specific position" << endl;
    cout << "10. Deletion by Value (Unique List)" << endl;
    cout << "11. Deletion by Value (Duplicate List)" << endl;
    cout << "0. Exit" << endl
         << endl;

    cout << "Enter your 1st choice:";
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
            insertionAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value:";
            cin >> value;
            insertionAtTail(head, value);
            break;
        case 3:
            cout << "Enter the position:";
            cin >> position;
            cout << "Enter the value:";
            cin >> value;
            insertionAtSpecificPosition(head, position, value);
            break;
        case 4:
            cout << "Enter the value you want to search:";
            cin >> value;
            position = searchByUniqueValue(head, value);
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
            // searchByDuplicateValue(head,value);
            Test t;
            t = searchByDuplicateValueReturn(head, value);
            if (t.position[0] == 1)
            {
                cout << "The value is not yet in the list" << endl;
            }
            else
            {
                int size = t.position[0];
                cout << "The value is at position:";
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
        case 10:
            cout << "Enter the value to delete:";
            int delValue;
            cin >> delValue;
            deletionByValue(head, delValue);
            break;
        case 11:
            cout << "Enter the value to delete:";
            int delValueDuplicate;
            cin >> delValueDuplicate;
            deletionByDuplicateValue(head, delValueDuplicate);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "Next choice:";
        cin >> choice;
    }

    cout << endl
         << "Linked list:";
    show(head);
    cout << endl;
    cout << "The length of the linked list:" << length(head);
}