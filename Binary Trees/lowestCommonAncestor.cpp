
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

int lowestCommonAncestor(struct Node* root, int k1, int k2)
{
  if(k1>k2)
  {
    int temp=k1;
    k1=k2;
    k2=temp;
  }
  if(root==NULL)
    return -1;
  else if(root->data>=k1&&root->data<=k2)
    return root->data;
  else if(root->data>=k1&&root->data>=k2)
   return  lowestCommonAncestor( root->left,k1,k2);
  else if(root->data<=k1&&root->data<=k2)
   return  lowestCommonAncestor( root->right,k1,k2);
}




int main()
{
	int arr[7]={31,21,13,54,45,16,7};
	struct Node * root=buildTree(arr,7);
	printInorder(root);
	cout<<"\nLowest Common Anscestor of 13 and 7 : ";
	cout<<lowestCommonAncestor(root,13,7);
}


