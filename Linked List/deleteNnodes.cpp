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

node* skipMdeleteN(node  *head, int M, int N) {
    node *t1=head;
  	node* t2=head;
  	while(t1!=NULL && t2!=NULL)
    {
      int c1=1;
      while(c1<M && t1!=NULL)
      {
        t1=t1->next;
        c1++;
      }
      if(t1!=NULL && M!=0)
        t2=t1->next;
      else if(M==0)
        t2=t1;
      else
        break;
      int c2=1;
      while(c2<N && t2!=NULL)
      {
        node *a=t2;
        t2=t2->next;
        c2++;
        delete a;
      }
      if(t2!=NULL && N!=0)
      {
        node *a=t2;
        t2=t2->next;
        t1->next=t2;
        delete a;
        t1=t1->next;
      }
      else if(N==0)
      {
        t1=t2;
      }
      else
      {
        t1->next=t2;
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
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}
