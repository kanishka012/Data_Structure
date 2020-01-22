//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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

class Pair
{
  public:
  node *head;
  node *tail;
};
Pair rev(node* head)
{
  Pair ans;
  ans.tail=head;
  node *prev=NULL;
  node *curr=head;
  node *next=NULL;
  while(curr!=NULL)
  {
    next=curr->next; 
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  ans.head=prev;
  //ans.tail=head;
  return ans;
}
node* kReverse(node*head,int n)
{
    node *h1=head;
  	node *t1=head;
  	int count=1;
  	while(count!=n && t1->next!=NULL)
    {
      t1=t1->next;count++;
    }
  	node *h2;
  	if(t1!=NULL)
    {
        h2=t1->next;
        t1->next=NULL;
    }
  	Pair a=rev(h1);
  	h1=a.head;
  	t1=a.tail;
  	if(h2!=NULL)
		h2=kReverse(h2,n);
  	t1->next=h2;
  	return h1;
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
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}
