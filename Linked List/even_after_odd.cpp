//Arrange elements in a Linked List such that all even numbers are placed after odd numbers
#include <iostream>
using namespace std;
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};


node* arrange_LinkedList(node* head)
{
    node* oddh=NULL;
  	node *oddt=NULL;
    node *evenh=NULL;
    node *event=NULL;
  	while(head!=NULL)
    {
      if(head->data%2!=0)
      {
      	if(oddh==NULL)
      	{
        	oddh=head;
          	oddt=head;
          	head=head->next;
      	}  
        else
        {
          oddt->next=head;
          oddt=oddt->next;
          head=head->next;
        }
      }
      else
      {
        if(evenh==NULL)
      	{
        	evenh=head;
          	event=head;
          	head=head->next;
      	}  
        else
        {
          event->next=head;
          event=event->next;
          head=head->next;
        }
      }
    }
    if(oddt==NULL)
		return evenh;
  	else
        oddt->next=NULL;
  	if(event==NULL)
        return oddh;
  	else
        event->next=NULL;
  	oddt->next=evenh;
  	return oddh;
}
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
