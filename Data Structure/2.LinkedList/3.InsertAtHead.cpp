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
void InsertAtTail(Node* &head, int val)
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

void InsertAtHead(Node* &head, int val)
{
    // step1 new node creation
    Node *newNode=new Node(val);

    // step2 update of newNode ->next
    newNode->next=head;

    //update of head
    head=newNode;

}
void show(Node *n)
{
    cout<<endl;
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next!=NULL)
        {
            cout<<"->";
        }
        n=n->next;

    }
      cout<<endl;
}
int main()
{
    Node *head=NULL;
    cout<<"1. Insertion at head"<<endl;
    cout<<"2. Insertion at tail"<<endl;
    cout<<"3. Exit"<<endl;
    int val;
    int choice=2;
    while(choice==1 || choice==2)
    {
        cout<<"Enter the value:";
        cin>>val;
        if(choice==1)
        {
            InsertAtHead(head,val);
        }
        else if(choice==2)
        {
            InsertAtTail(head,val);

        }


        cout<<"Next choice:";
        cin>>choice;

    }
    // InsertAtTail(head,3);
    // InsertAtTail(head,7);



    show(head);

    // InsertAtHead(head,1);
    // InsertAtHead(head,8);
    // show(head);

}
