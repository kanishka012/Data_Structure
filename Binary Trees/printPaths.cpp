#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *left, *right;
};

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

void print(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void printPaths(struct Node * root,int i,int arr[100])
{
	if(!root)
	{print(arr,i);i--;}
	else{
		arr[i]=root->data;
		i++;
		printPaths(root->left,i,arr);
		if(root->right!=NULL)
		printPaths(root->right,i,arr);
	}
}

printAllPaths(struct Node * root)
{
	int a[100]={0};
	printPaths(root,0,a);
}
int main()
{
	int arr[11]={5,3,7,1,4,6,9,0,2,8,10};
	struct Node * root=buildTree(arr,11);
	printAllPaths(root);

}
