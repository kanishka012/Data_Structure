#include <iostream>
#include<algorithm>
using namespace std;

int first(int arr[],int si,int ei,int n,int key)
{
	if(si<=ei)
	{
		int mid=si+(ei-si)/2;
		if((mid==0 || key>arr[mid-1]) && arr[mid]==key)
			return mid;
		else if(arr[mid]<key)
			return first(arr,mid+1,ei,n,key);
		else
			return first(arr,si,mid-1,n,key);
	}
	return -1;
}
int last(int arr[],int si,int ei,int n,int key)
{
	if(si<=ei)
	{
		int mid=si+(ei-si)/2;
		if((mid==n-1 || key<arr[mid+1]) && arr[mid]==key)
			return mid;
		else if(arr[mid]>key)
			return last(arr,si,mid-1,n,key);
		else
			return last(arr,mid+1,ei,n,key);
	}
	return -1;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    sort(arr,arr+n);
    int key;
    cin>>key;
    int x=first(arr,0,n-1,n,key);
	int y=last(arr,0,n-1,n,key);
	cout<<"First occurence:"<<x<<endl;
	cout<<"Last occurence:"<<y<<endl;
}
