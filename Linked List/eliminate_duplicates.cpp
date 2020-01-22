//Eliminate duplicates from a sorted linked list
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

node* eliminate_duplicate(node* head)
{
	node *temp=head;
  	node *temp1=head->next;
  	while(temp1!=NULL)
    {
      if(temp->data==temp1->data)
      {
        node *a=temp1;
        temp->next=a->next;
      	temp1=temp1->next;
        delete a;
      }
      else
      {
      	temp=temp->next;
      	temp1=temp1->next;
      }
    }
  	return head;
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
int main(){
    node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}

