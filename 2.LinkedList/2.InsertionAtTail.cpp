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
void InsertAtTail(Node* &head,int val)
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

void display(Node *n)
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

int main()
{
    Node *head=NULL;
//    InsertAtTail(head,1);
//    InsertAtTail(head,2);
//    InsertAtTail(head,5);
//    InsertAtTail(head,8);
bool choice=true;
while(choice)
{
    int val;
    cout<<"Enter the value: ";
    cin>>val;
    InsertAtTail(head,val);
    cout<<endl<<"Do you want to continue?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl;
    int option;
    cin>>option;
    switch(option)
    {
    case 1:
        choice=true;
        break;
    case 2:
        choice=false;
        break;
    default:
        cout<<"Invalid choice"<<endl;
        break;

    }

}
    display(head);
}
