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

struct Node* insertLevelOrder(int arr[], struct Node* root, 
                       int i, int n) 
{ 
    // Base case for recursion 
    if (i < n) 
    { 
        Node* temp = newNode(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = insertLevelOrder(arr, 
                   root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = insertLevelOrder(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
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


struct Node * mirrorIT(struct Node *root)
{
	if(!root)
	return NULL;
	else{
		struct Node *temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirrorIT(root->left);
		mirrorIT(root->right);
		return root;
	}
}


bool check(struct Node * p1,struct Node * p2)
{
	if(p1==NULL&&p2==NULL)
	return true;
	if(p1!=NULL&&p2!=NULL)
	{
		if(p1->data==p2->data&&check(p1->left,p2->left)&&check(p1->right,p2->right))
		return true;
	}
	return false;
}


bool isPallendromic(struct Node * root)
{
	if(!root)
	return true;
	else{
		
		
		struct Node * temp=mirrorIT(root->right);
		return check(root->left,temp);
	}
}


int main()
{
	int arr[7]={1,2,2,3,4,4,3};
	struct Node *root=NULL;
	 root=insertLevelOrder(arr,root,0,7);
	printInorder(root);
	
	cout<<"\nIS PALLINDROMIC :"<<isPallendromic(root);
	
}
