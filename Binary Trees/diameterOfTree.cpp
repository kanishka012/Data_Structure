
#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *left, *right;
};


int diameter(struct Node * tree);


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


int main()
{
	int arr[7]={31,21,13,54,45,16,7};
	struct Node * root=buildTree(arr,7);
	printInorder(root);
	cout<<"\nDiameter Of Tree  is :"<<endl;
     cout << diameter(root) << endl;

}



int func(Node * root, Node * base,int * temp)
{
if(!root)
return 0;
int l=func(root->left,base,temp);
int r=func(root->right,base,temp);
int d=l+r+1;
if(d>*temp)
*temp=d;
if(root==base)
return *temp;
else
return l>r ? l+1:r+1;
}


int diameter(Node* node)
{
    int temp=0;
   return func(node,node,&temp);
}
