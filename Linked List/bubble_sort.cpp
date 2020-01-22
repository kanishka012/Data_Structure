//bubble sort iterative
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

int len(node *head)
{
  node *t=head;
  int l=0;
  while(t!=NULL)
  {
    t=t->next;
    l++;
  }
  return l;
}
node* bubble_sort_LinkedList_itr(node* head)
{
    for(int i=0;i<len(head);i++)
    {
      node *prev=NULL;
      node *curr=head;
      while(curr->next!=NULL)
      {
        if(curr->data<curr->next->data)
        {
          prev=curr;
          curr=curr->next;
        }
        else
        {
          if(prev!=NULL)
          {
            node *next=curr->next;
            prev->next=next;
            curr->next=next->next;
            next->next=curr;
            prev=next;
          }
          else
          {
            node *next=curr->next;
            curr->next=next->next;
            next->next=curr;
            prev=next;
            head=prev;
          }
        }
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
int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}
