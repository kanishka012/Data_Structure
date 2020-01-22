//merge sort recursive
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


node* mergeSort(node *head) {
  	if(head->next==NULL)
      return head;
    node *slow=head;
  	node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
      slow=slow->next;
      fast=fast->next->next;
    }
  	node *h1=head;
  	node *h2=slow->next;
  	slow->next=NULL;
  	slow=mergeSort(h1);
  	fast=mergeSort(h2);
  	node *fh=NULL;node *ft=NULL;
  	if(slow->data<=fast->data)
    {
      fh=slow;
      ft=slow;
      slow=slow->next;
    }
  	else if(slow->data>fast->data)
    {
	  fh=fast;
      ft=fast;
      fast=fast->next;
    }
  	while(slow!=NULL && fast!=NULL)
    {
      if(slow->data<=fast->data)
    	{
      	  ft->next=slow;
          ft=ft->next;
          slow=slow->next;
    	}
  	  else if(slow->data>fast->data)
      {
	      ft->next=fast;
          ft=ft->next;
          fast=fast->next;
       }
    }
  	if(slow==NULL)
      ft->next=fast;
    if(fast==NULL)
      ft->next=slow;
  	return fh; 
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
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}

