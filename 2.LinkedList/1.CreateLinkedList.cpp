#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
};
void display(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->value;
        if(n->next!=NULL)
            cout<<"->";
       n= n->next;
    }

}


int main()
{
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();
    Node *fourth=new Node();
    Node *fifth=new Node();
    Node *sixth=new Node();

    head->value=1000;
    second->value =1050;
    third->value=2000;
    fourth->value=1020;
    fifth->value=3000;
    sixth->value=11;

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=NULL;
cout<<head->next->next->value;
     //display(head);
}
