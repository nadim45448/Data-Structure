#include<bits/stdc++.h>
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
void insertAtTail(Node* &head, int val)
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
        temp=temp->next; //1 2 3 4
    }
    temp->next=newNode;

}
void insertAtHead(Node* &head,int val)
{
    Node *newNode=new Node(val);
    newNode->next=head;
    head=newNode;
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
int length(Node *n)
{
    int count=0;
    while(n!=NULL)
    {
        count++;
        n=n->next;

    }
    return count;
}

int main()
{
    Node *head=NULL;
    cout<<"1. Insert at head"<<endl;
    cout<<"2. Insert at tail"<<endl;
    cout<<"0. Exit"<<endl<<endl;
    cout<<"Your choice: ";
    int choice;
    cin>>choice;
    int value;
    while (choice!=0)
    {
        cout<<"Enter the value:";
        cin>>value;
        switch (choice)
        {
        case 1:
        insertAtHead(head,value);
            break;
        case 2:
        insertAtTail(head,value);
        break;

        
        default:
        cout<<"Invalid choice"<<endl;
            break;
        }
        cout<<"Next choice: ";
        cin>>choice;
    
    }
    cout<<"Linked list: ";
    show(head);
    cout<<endl;
    cout<<"Length of the Linked list: "<<length(head);
    


}