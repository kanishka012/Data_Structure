//Check if a linked list is a palindrome
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

bool check_palindrome(node* head)
{
    node *temp1=head;
  	int c=0;
  	while(temp1!=NULL)
    {
      temp1=temp1->next;
      c++;
    }
  	temp1=head;
  	int i=0;
  	node *temp2=head;
  	while(i<c/2)
    {
     	 temp2=temp2->next;
      	 i++;
    }
  	temp2=temp2->next;
  	node *prev=NULL;
  	node *curr=temp2;
  	node *nex=NULL;
  	while(curr!=NULL)
    {
     	nex=curr->next;
      	curr->next=prev;
      	prev=curr;
      	curr=nex;
    }
  	temp2=prev;
  	while(temp2!=NULL)
    {
      	if(temp1->data!=temp2->data)
          	return false;
      	temp1=temp1->next;
      	temp2=temp2->next;
    }
  	return true;
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
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}
