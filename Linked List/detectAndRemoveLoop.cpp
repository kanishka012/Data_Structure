/*
struct Node {
	int data;
	struct Node * next;
};
*/

#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
struct Node *head=NULL;
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




bool IsAccessible(struct Node * source,struct Node* target,int count)
{
while(count!=0)
{
if(target==source)
return true;
source=source->next;
count--;
}
return false;
}


int getElementCount(struct Node * ptr)
{
	int count=1;
	if(ptr==NULL)
	return 0;
	
	struct Node * temp=ptr->next;
	while(temp!=ptr)
	{
		temp=temp->next;
		count++;
	}
	return count;
}

void removeLoop(struct Node * ptr)
{
  struct Node* temp=head;
  int count_Ele=getElementCount(ptr);
  while(IsAccessible(ptr,temp,count_Ele)==false)
  {
  temp=temp->next;
  }
  while(count_Ele!=1)
  {
  temp=temp->next;
  count_Ele--;
  }
  temp->next=NULL;

}


int detectLoopAndRemove(struct Node * head)
{
	if(!head)
	return 0;
	else{
		if(head->next==head)
		return 1;
		struct Node * slow=head;
		struct Node * fast=head->next;
		while(fast!=NULL&&fast->next!=NULL)
		{
			
			slow=slow->next;
			fast=fast->next->next;
			if(fast==slow)
			{removeLoop(slow);
			}
		}
		return 0;
	}
}



 void createLoop(int loopPoint)
{
   struct Node * temp=head;
   int count=0;
   while(count!=loopPoint)
   {
    count++;
    temp=temp->next;
   
   }
   struct Node * t=head;
   while(t->next!=NULL)
   {
   	t=t->next;
   }
   t->next=temp;
}


//POSITION STARTS FROM ZERO ...


int main()
{
	
	for(int i=1;i<=8;i++)
	{
//		insertAtBegin(&head,i);
		insertAtEnd(&head,i);
	}
	
    createLoop(3);
    cout<<detectLoopAndRemove(head)<<endl;
	printList(head);
}



