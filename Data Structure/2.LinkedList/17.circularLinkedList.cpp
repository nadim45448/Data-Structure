#include <iostream>
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
void insertionAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head; // newNode->next=temp->next
    temp->next = newNode;
}
void insertionAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next=head;
    // head=newNode;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    head = newNode;
}
void deletionAtHead(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        Node *delNode=temp;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=delNode->next;
        head=delNode->next;
        delete delNode;
        
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
    if (temp != NULL && temp->next != head)
    {
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        // step 2
        Node *delNode = temp->next;
        // step 3
        temp->next = delNode->next;
        // step 4
        delete delNode;
    }
    else
    {
        if (temp == NULL) // head is null
        {
            cout << "There is no value in the linked list" << endl;
        }
        else
        { // head is tail
            deletionAtHead(head);
        }
    }
}
void dsiplay(Node *&head)
{
   if(head==NULL)
   {
    cout<<"Linked List is empty"<<endl;
        return;
   }
   
    Node *temp = head;

    //approach 1
    do
    {
        cout<<temp->value;
        temp=temp->next;
        if(temp!=head)
        {
            cout<<"-->";
        }
        
    } while (temp!=head);
    cout<<endl;
    
     //approach 2
    /*while (temp->next != head)
    {
        cout << temp->value;
        if (temp->next != head)
        {
            cout << "-->";
        }
        temp = temp->next;
    }
    cout<<temp->value;*/
}
int length(Node *&head)
{
    Node *temp=head;
    int count=0;
    
    do{
       
        count++;
        temp=temp->next;
    }while(temp!=head);
    return  count;
}
int main()
{
    Node *head = NULL;

    cout << "1. Insertion at Head" << endl;
    cout << "2. Insertion at Tail" << endl;
    cout << "3. Insertion at specific position" << endl;
    cout << "4. Deletion at Head" << endl;
    cout << "5. Deletion at Tail" << endl;
    cout << "6. Deletion at specific position" << endl;
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
            insertionAtHead(head, value);
            break;
        case 2:
            cout << "Enter the value:";
            cin >> value;
            insertionAtTail(head, value);
            break;
        case 4:
            deletionAtHead(head);
            break;
        case 5:
            deletionAtTail(head);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "Next choice: ";
        cin >> choice;
        
    }
    cout << "Linked list: ";
        dsiplay(head);
        cout << endl;
        cout << "Length of the Linked list: " << length(head);
}