//Implement code to swap two elements of a Linked List. You need to swap the nodes not the data
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


node* swap_nodes(node *head,int i,int j)
{ 
  int a=0,b=0;
  node *p1=NULL;
  node *c1=head;
  node *p2=NULL;
  node *c2=head;
  if(i>j)
  {
    int temp=i;
    i=j;
    j=temp;
  }
  while(a!=i)
  {
    p1=c1;
    c1=c1->next;
    a++;
  }
  while(b!=j)
  {
    p2=c2;
    c2=c2->next;
    b++;
  }
  if((i==0 || j==0) &&(abs(i-j)!=1))
  {
    /*c1->next=c2->next;
    c2->next=p2;
    p2->next=c1;*/
    p1=c1->next;
    p2->next=c1;
    c1->next=c2->next;
    c2->next=p1;
    head=c2;
  }
  else if((i!=0 && j!=0) &&(abs(i-j)==1))
  {
    p1->next=c2;
    c1->next=c2->next;
    c2->next=c1;
  }
  else if((i==0 ||j==0)&&(abs(i-j)==1))
  {
    c1->next=c2->next;
    c2->next=c1;
    head=c2;
  }
  else
  {
    p1->next=c2;
    p2->next=c1;
    p2=c1->next;
    c1->next=c2->next;
    c2->next=p2;
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

int main()
{
    int i,j;
    node* head =takeinput();
    cin>>i;
    cin>>j;
    head=swap_nodes(head,i,j);
    print(head);
    return 0;
}

