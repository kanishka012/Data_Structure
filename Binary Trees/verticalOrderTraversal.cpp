#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *left, *right;
};


struct List{
	int data;
	struct List * next;
};

struct hdHash{
	int hd;
	struct List * head;
};
struct hdHash * arr[100];
int top=-1;


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



int exists(int hd)
{
	if(top==-1)
	return -1;
	else{
		for(int i=0;i<=top;i++)
		{
			if(arr[i]->hd==hd)
			return i;
		}
		return -1;
	}
}

void insertInHd(struct Node * root,int hd)
{
	int x=exists(hd);
	if(x==-1)
	{
	  struct List * temp=(struct List *)malloc(sizeof(struct List));
	  temp->data=root->data;
	  temp->next=NULL;
	  top++;
	  arr[top]=(struct hdHash *)malloc(sizeof(struct hdHash));
	  arr[top]->hd=hd;
	  arr[top]->head=temp;	
	}
	else{
	  struct List *temp=(struct List *)malloc(sizeof(struct List));
	  temp->data=root->data;
	  temp->next=NULL;
	  
	  struct List* t=arr[x]->head;
	  while(t->next!=NULL)
	  t=t->next;
	  t->next=temp;
	  
	}
}

void assignHd(struct Node * parent,int parentHd)
{
	if(!parent)
	return;
	else
	{
		insertInHd(parent,parentHd);
		assignHd(parent->left,parentHd-1);
		assignHd(parent->right,parentHd+1);
	}
}


void printList(struct List * head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}


void 	printHdTable(){
	for(int i=0;i<=top;i++)
	{
		cout<<"For HD "<<arr[i]->hd<<" : ";
		printList(arr[i]->head);
	}
}

bool compareHD(hdHash* i1, hdHash* i2) 
{ 
    return (i1->hd < i2->hd); 
} 


void printVerticalOrder(struct Node * root)
{
	int rootHd=0;
	assignHd(root,rootHd);
	cout<<endl;
	sort(arr,arr+top,compareHD);
	printHdTable();
}

int main()
{
	int arr[7]={31,21,13,54,45,16,7};
	struct Node * root=buildTree(arr,7);
	printInorder(root);
	printVerticalOrder(root);

	
	
	
}
