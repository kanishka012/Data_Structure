#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	int min;
	struct Node *next;
};

struct Node *head=NULL;
int top=-1;
	
struct Node * newNode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->min=-1;
	temp->next=NULL;
	return temp;
}

int isEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}

int peekMin()
{
  if(isEmpty())
  return -1;
  else
  return head->min;
}

void push(int newData)
{
	if(head==NULL){
		struct Node *temp=newNode(newData);
		temp->min=newData;
		head=temp;
	}
	else{
		struct Node *temp=newNode(newData);
		if(newData<peekMin())
		temp->min=newData;
		else
		temp->min=peekMin();
		temp->next=head;
		head=temp;
	}
	top++;
}



int peek()
{
  if(isEmpty())
  return -1;
  else
  return head->data;	
}


void pop()
{
	if(isEmpty()){
		return;
	}
	else{
		head=head->next;
		top--;
	}
}

int main()
{
	cout<<"in start is stack empty : "<<isEmpty()<<endl;
	for(int i=1;i<7;i++)
	{
		push(i);
	}
	cout<<"top Element : "<<peek()<<endl;
	pop();
	pop();
	cout<<"peek after 2 pops : "<<peek()<<endl;
	cout<<"min now is : "<<peekMin();
	
}
