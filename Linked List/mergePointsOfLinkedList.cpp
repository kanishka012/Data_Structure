


#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};

struct Node * newNode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

void printList(struct Node * head)
{
	if(!head)
	return;
	else{
		cout<<head->data<<" ";
		printList(head->next);
	}
}

int sizeList(struct Node *head)
{
	int count=0;
	struct Node *temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}


void insertAtBegin(struct Node **headRef,int newData)
{
	if(*headRef==NULL){
		struct Node *temp=newNode(newData);
		*headRef=temp;
	}
	else{
		struct Node *temp=newNode(newData);
		temp->next=*headRef;
		*headRef=temp;
	}
//	return head;
}

void insertAtEnd(struct Node **headRef,int newData)
{
	if(*headRef==NULL){
		struct Node *temp=newNode(newData);
		*headRef=temp;
	}
	else{
		struct Node *node=newNode(newData);
		struct Node *temp=*headRef;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=node;
	}
}


void insertInMiddle(struct Node **headRef,int newData,int position)
{
	int size=sizeList(*headRef);
	if(position>size)
	position=size;

	if(position==0)
	{
      insertAtBegin(headRef,newData);
     }
	else{
		struct Node *node=newNode(newData);
		struct Node *temp=*headRef;
		struct Node *prev=*headRef;
		int posCount=0;
		while(temp!=NULL&&posCount!=position)
		{
			prev=temp;
			temp=temp->next;
			posCount++;
		}
		node->next=prev->next;
		prev->next=node;
	}
}

void deleteFromBegin(struct Node ** headRef)
{
	struct Node *head=*headRef;
	if(!head||head->next==NULL)
	{}
	else{
		*headRef=(*headRef)->next;
	}
}


void deleteFromEnd(struct Node ** headRef)
{
	struct Node *head=*headRef;
	if(!head)
	{}
	else if(head->next==NULL)
	*headRef=NULL;
	else{
		struct Node *temp=*headRef;
		struct Node *prev=*headRef;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
	}
}



void deleteFromMiddle(struct Node ** headRef,int position)
{
	int size=sizeList(*headRef);
	if(position>size)
	position=size;

	if(position==0)
	{
      deleteFromBegin(headRef);
     }
	else if(position==size)
	{
		deleteFromEnd(headRef);
	}
	else{
		struct Node *temp=*headRef;
		struct Node *prev=*headRef;
		int pos=0;
		while(temp->next!=NULL&&pos!=position)
		{
			prev=temp;
			pos++;
			temp=temp->next;
		}
		prev->next=temp->next;
	}
}


void createMergePoint(int n,struct Node ** headRef1,struct Node ** headRef2)
{
	struct Node *temp=*headRef1;
	while(n!=0)
	{
		temp=temp->next;
		n--;
	}
	struct Node *temp2=*headRef2;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
	
}
struct Node* findMergePoint(struct Node* head1, struct Node* head2) 
{
  int s1=sizeList(head1);
  int s2=sizeList(head2);
  if(s1>s2)
  {
  	int diff=s1-s2;
  	while(diff!=0)
  	{
  		head1=head1->next;
  		diff--;
	}
	while(head1!=NULL&&head2!=NULL&&head1!=head2)
	{
		head1=head1->next;
		head2=head2->next;
	}
  }
  else{
  	int diff=s2-s2;
  	while(diff!=0)
  	{
  		head2=head2->next;
  		diff--;
	}
	while(head1!=NULL&&head2!=NULL&&head1!=head2)
	{
		head1=head1->next;
		head2=head2->next;
	}
  }
 return head1;
}

int main()
{
	struct Node *head=NULL;
	for(int i=1;i<7;i++)
	{
		insertAtEnd(&head,i);
	}
	printList(head);
	cout<<endl;
	struct Node *head2=NULL;
	for(int i=1;i<5;i++)
	{
		insertAtEnd(&head2,i*11);
	}

	int mergePoint=4;
	createMergePoint(mergePoint,&head,&head2);
		printList(head2);
	cout<<endl;
	struct Node * merge=findMergePoint(head,head2);
	printList(merge);
	
}

