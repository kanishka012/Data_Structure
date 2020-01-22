#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *left, *right;
};




int front=-1, rear=-1;
struct Node * array[100];

// Method to add an item to the queue.
void enqueue(struct Node* item)
{
  if(front==-1&&rear==-1)
    front=rear=0;
  array[rear]=item;
  rear++;
}

// Method to remove an item from queue.
struct Node * dequeue()
{
  if(front==rear)
    return NULL;
  struct Node * item=array[front];
  front++;
  return item;
}

int isEmpty()
{
	if(front==rear)
	return 1;
	else
	return 0;
}



int SIZE=100;
struct Node* Stack[100];int top = -1;


// Function to check if stack is empty.
int isEmptyStack()
{
if(top==-1)
  return 1;
else
  return 0;
}

// Function to add an item to stack.
void push(struct Node* item)
{

  
  Stack[++top] = item;  
}

// Function to remove an item from stack.
struct Node * pop()
{
if(isEmptyStack())
//  return -1;
{}
  struct Node * temp=Stack[top--];
  return temp;
}






struct Node * newNode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
}
void insert(struct Node * temp,struct Node *root)
{
	if(!root)
	{
		root=temp;
	}
	else if(root->left==NULL&&root->data>temp->data)
	{
		root->left=temp;
	}
	else if(root->right==NULL&&root->data<temp->data)
	{
		root->right=temp;
	}
	else{
		if(root->data>temp->data)
		insert(temp,root->left);
		else if(root->data<temp->data)
		insert(temp,root->right);
	}
}

struct Node* buildTree(int t[], int n)
{
  if(n==0)
    return NULL;
    int i=0;
     struct Node *root=newNode(t[0]);
     i++;
    while(i!=n)
    {
    	struct Node *temp=newNode(t[i]);
    	insert(temp,root);
    	i++;
	}
  
  return(root);
}


void printInorder(struct Node * root)
{
	if(!root)
	return;
	else{
		printInorder(root->left);
		cout<<root->data<<" ";
		printInorder(root->right);
	}
}



void printLevelOrder(struct Node * root)
{
	if(isEmpty())
	return;
	else{
//		struct Node *root=pop();
		 
		 if(root->right!=NULL)
	      push(root->right);
	    if(root->left!=NULL)
	      push(root->left);
	    
	    
	    if(root->right!=NULL)
	    printLevelOrder(root->right);
	    if(root->left!=NULL)
	    printLevelOrder(root->left);
		if(root->left!=NULL)
	    cout<<(pop()->data)<<"-";
	    if(root->right!=NULL)
	    cout<<(pop()->data)<<"-";
	    
	}
}

void printLevel(struct Node* root)
{
	if(!root)
	return;
	if(root->right!=NULL)
	enqueue(root->right);
	if(root->left!=NULL)
	enqueue(root->left);
	
	push(root);
	printLevel(dequeue());
}

int main()
{
	int arr[9]={31,21,13,54,45,16,7,33,47};
	struct Node * root=buildTree(arr,9);
	printInorder(root);
	
	cout<<endl;
	
	
	printLevel(root);
	
	while(isEmptyStack()==0)
	{
		cout<<pop()->data<<" ";
	}
	
	
	
	
}
