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


struct Node * findNode(struct Node * root,int val)
{
	if(!root)
	return NULL;
	else if(root->data==val)
	{
		return root;
	}
	else{
		if(root->data>val)
		{	struct Node * temp=findNode(root->left,val);
			if(temp)
			return temp;
	    }
	    else{
		struct Node * temp2=findNode(root->right,val);
		if(temp2)
		return temp2;
		}
	}
}


struct Node * getParent(struct Node * root,struct Node * temp)
{
//		cout<<root->data<<endl;
	if(!root)
	return NULL;
	if(root->left==temp||root->right==temp)
	return root;
	else{
//		cout<<"here"<<temp->data;
		if(root->data>temp->data)
		{   struct Node * temp1=getParent(root->left,temp);
			if(temp1)
			return temp1;
	    }
	    else{
		struct Node * temp2=getParent(root->right,temp);
		if(temp2)
		return temp2;
		}
	}
}


int isLeaf(struct Node *temp)
{
	if(temp->left==NULL&&temp->right==NULL)
	return 1;
	else
	return 0;
}

int isOneChildNode(struct Node *temp)
{
	if((temp->left==NULL&&temp->right!=NULL)||(temp->right==NULL&&temp->left!=NULL))
	return 1;
	else
	return 0;
}

struct Node * findMin(struct Node * root)
{
	if(root==NULL)
	return NULL;
	else if(root->left==NULL)
	return root;
	else
	return findMin(root->left);
}





void deleteOneChildNode(struct Node * root,struct Node * temp)
{
			struct Node* parent=getParent(root,temp);
			if(parent==NULL)
			return;
			if(parent->left==temp)
			{
				if(temp->left==NULL)
				parent->left=temp->right;
				else
				parent->left=temp->left;
			}
			else if(parent->right==temp)
			{
				if(temp->left==NULL)
				parent->right=temp->right;
				else
				parent->right=temp->left;
			}
}



void deleteLeafChild(struct Node* root,struct Node * temp)
{
			struct Node* parent=getParent(root,temp);
//			cout<<parent->data;
			if(parent==NULL)
			return;
			if(parent->left==temp)
			parent->left=NULL;
			else if(parent->right==temp)
			parent->right=NULL;
}



void deleteTwoChildNode(struct Node * root,struct Node * temp)
{
	struct Node * minRight=findMin(temp->right);
	temp->data=minRight->data;
	if(isLeaf(minRight))
		deleteLeafChild(root,minRight);
	else 
		deleteOneChildNode(root,minRight);	
}



void deleteNode(struct Node * root,int value)
{
	if(!root)
	return;
	else{
		struct Node * temp=findNode(root,value);
//		cout<<"--"<<temp->data<<endl;
		if(temp==NULL)
		{cout<<"Value Not present !";
		return;
		}
		if(isLeaf(temp))
			deleteLeafChild(root,temp);
		else if(isOneChildNode(temp))
		    deleteOneChildNode(root,temp);
		else
			deleteTwoChildNode(root,temp);
		
	}
}


int main()
{
	int arr[7]={31,21,13,54,45,16,7};
	struct Node * root=buildTree(arr,7);
	printInorder(root);
	
	
	
	deleteNode(root,31);
	cout<<endl;
	printInorder(root);
	
	
	
	
	
}
