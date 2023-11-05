#include<iostream>
using namespace std;
class Node
{
    public:
    int value;
    Node *next;
    Node(int val)
    {
        value=val;
        next=NULL;
    }

};

void insertAtTail(Node *&head,int val);
void insertAtHead(Node *&head, int val);
int length(Node *head);
void insertAtSpecificPosition(Node *&head, int pos, int val);
void show(Node *head);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);


void insertAtTail(Node *&head,int val)
{
    Node *newNode=new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void insertAtHead(Node *&head, int val)
{
    Node *newNode=new Node(val);
    newNode->next=head;
    head=newNode;

}
int length(Node *n)
{
    int count=0;
    while (n!=NULL)
    {
     count++;
     n=n->next; 
    }
    return count;
  
}
void insertAtSpecificPosition(Node *&head, int pos, int val)
{
    Node *newNode=new Node(val);
    int i=1;
    Node *temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;

    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void show(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next!=NULL)
        {
            cout<<"->";
        }
        n=n->next;
    }

}
int searchByValueUnique(Node *&head, int key)
{
    Node *temp=head;
    if(temp==NULL)
    {
        return -1;
    }
    int count=1;
    while(temp->value!=key)
    {
        if(temp->next==NULL)
        {
            return -1;
        }
        temp=temp->next;
        count++;
    }
    return count;

}
void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp=head;

    int size;
    size=length(head);
    int position[size+1],k=1;// to store the duplicate position of searched value from index 1.

    int count=1;
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->value==key)
        {
            //cout<<count<<" ";
            position[k]=count;
            k++;
            flag=1;
            
        }
        temp=temp->next; 
        count++; //5
    }
    if(flag==0){
        cout<<"The searched value "<<key<<" is not yet in the list"<<endl;
    }
    else 
    {
        position[0]=k;// 0th index store the size of array;
        cout<<"The value "<<key<<" is at position: ";
        for(int i=1;i<position[0];i++)
        {
            cout<<position[i];
            if(i<position[0]-1)
            {
                cout<<",";
            }
        }
    }
}
int main()
{
    Node *head=NULL;

    cout << "1. Insertion at Head" << endl;
    cout << "2. Insertion at Tail" << endl;
    cout << "3. Insertion at specific position" << endl;
    cout << "4. Search a value(Unique List)" << endl;
    cout << "5. Search a value(Duplicate enabled List)" << endl;
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

        case 4: 
            cout << "Enter the value you want to search:";
            cin >> value;
            position=searchByValueUnique(head,value);
            if(position!=-1)
            {
                cout<<value<<" is at position "<<position<<endl;
            }
            else
            {
                cout<<value<<" is not yet in the list"<<endl;
            }
            break;
        case 5: 
            cout << "Enter the value you want to search:";
            cin >> value;
            searchByValueDuplicate(head,value);
            cout<<endl;
            
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
    //cout << "Length of the Linked list: " << length(head);

}