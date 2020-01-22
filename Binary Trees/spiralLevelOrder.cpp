#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *left, *right;
};



int SIZE=100;
struct Node* Stack[100];int top = -1;
struct Node* Stack2[100];int top2=-1;

// Function to check if stack is empty.
int isEmptyStack()
{
if(top==-1)
  return 1;
else
  return 0;
}



int isEmptyStack2()
{
if(top2==-1)
  return 1;
else
  return 0;
}
// Function to add an item to stack.



void push(struct Node* item)
{
  Stack[++top] = item;  
}
void push2(struct Node* item)
{
  Stack2[++top2] = item;  
}
// Function to remove an item from stack.
struct Node * pop()
{
if(isEmptyStack())
{}
  struct Node * temp=Stack[top--];
  return temp;
}

struct Node * pop2()
{
if(isEmptyStack2())
//  return -1;
{}
  struct Node * temp=Stack2[top2--];
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





void popAndPrintStack2()
{
	while(isEmptyStack2()==0)
	{
		struct Node * temp=pop2();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
		push(temp->left);
		if(temp->right!=NULL)
		push(temp->right);
	}
}

void popAndPrintStack()
{
	while(isEmptyStack()==0)
	{
		struct Node * temp=pop();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
		push2(temp->left);
		if(temp->right!=NULL)
		push2(temp->right);
	}
}



void printLevelSpiral(struct Node* root)
{
	
	if(!root)
	return;
	
	push(root);
	
    while(true)
    {
	    if(isEmptyStack()&&isEmptyStack2())
	 	break;
	
	popAndPrintStack();
	popAndPrintStack2();
	
	}
}

int main()
{
	int arr[9]={31,21,13,54,45,16,7,33,47};
	struct Node * root=buildTree(arr,9);
	printInorder(root);
	
	cout<<endl;
	
	
	printLevelSpiral(root);
	
	
	
}
