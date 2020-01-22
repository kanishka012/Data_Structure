#include<bits/stdc++.h>
using namespace std;


int array[100]={0};

void insert(int temp,int i)
{
	if(array[i]==0)
	array[i]=temp;
	else{
	  if(array[i]>temp)
	  insert(temp,2*i+1);	
	  else
	  insert(temp,2*i+2);
	}
}

void buildTree(int t[], int n)
{
  if(n==0)
  {}
  else{
    int i=0;
     int root=t[0];
     i++;
     insert(root,0);
    while(i!=n)
    {
    	int temp=t[i];
    	insert(temp,0);
    	i++;
	}
}
}

void printData(int i)
{
	if(array[i]==0)
	return;
	else{
		printData(2*i+1);
		cout<<array[i]<<" ";
		printData(2*i+2);
	}
}

void printInorder()
{
	printData(0);
}


int main()
{
	int arr[7]={31,21,13,54,45,16,7};
	buildTree(arr,7);
	printInorder();
}
