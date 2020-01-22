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

int PalliAns(struct Node *fast,struct Node * slow,struct Node **front,int *odd)
{
	if((fast)->next==NULL||(fast)->next->next==NULL)
	{
		if((fast)->next==NULL)
		*odd=1;
		else
		*odd=0;
		*front=(slow)->next;
	return 1;
     }
	else{
		slow=(slow)->next;
		fast=(fast)->next->next;
		int chk =PalliAns(fast,slow,front,odd);
		if(chk==0)
		return 0;
		if(*odd)
		{
			*odd=0;
			return 1;
		}
		if((slow)->data==(*front)->data)
		{
//			cout<<(slow)->data<<"---"<<(*front)->data<<endl;
			(*front)=(*front)->next;
			return 1;
		}
		else{
			cout<<(slow)->data<<"---"<<(*front)->data;
			return 0;
		}
	}
}


int isPalli(struct Node *head)
{
	struct Node *slow=head;
	struct Node *fast=head;
	struct Node *front=head;
	int odd=0;
	return PalliAns(fast,slow,&front,&odd);
}

//POSITION STARTS FROM ZERO ...


int main()
{
	struct Node *head=NULL;
	for(int i=1;i<8;i++)
	{
		insertAtBegin(&head,i);
	}
	insertAtEnd(&head,13);
	for(int i=1;i<8;i++)
	{
		insertAtEnd(&head,i);
	}
	cout<<"Is Pallindrome : "<<isPalli(head)<<endl;
	printList(head);
}
