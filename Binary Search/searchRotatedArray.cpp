#include <iostream>
using namespace std;

int find(int arr[],int si,int ei,int key)
{
	if(si>ei)
		return -1;
	int mid=si+(ei-si)/2;
	if(arr[mid]==key)
		return mid;
	else if (arr[mid]>arr[si])
	{
		if(key>=arr[si] && key<arr[mid])
			return find(arr,si,mid-1,key);
		return find(arr,mid+1,ei,key);	
	}
	else
	{
		if(key>arr[mid] && key<=arr[ei])
			return find(arr,mid+1,ei,key);	
		return find(arr,si,mid-1,key);
	}
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    int key;
    cin>>key;
    cout<<find(arr,0,n-1,key);
}
