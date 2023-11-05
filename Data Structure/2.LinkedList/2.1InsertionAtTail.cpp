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
void InsertionAtTail(Node* &head, int val)
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
void show(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->next;
    }
}
int main()
{
    Node *head = NULL;
    bool choice = true;
    while (choice)
    {
    Flag:
        int val;
        cout << "enter value:";
        cin >> val;
        InsertionAtTail(head, val);
        flag:
        cout << "DO you want to continue?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            goto Flag;
            break;

        case 2:
            choice = false;
            break;

        default:
            cout << "Invalid choice" << endl;
            goto flag;

        }
    }

    show(head);
}
