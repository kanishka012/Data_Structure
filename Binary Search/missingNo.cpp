#include <iostream>
using namespace std;

int find(int arr[],int n)
{
	int si=0,ei=n-1;
	int mid;
	while(si<=ei)
	{
		mid=si+(ei-si)/2;
		if(arr[mid]!=(mid+1) && arr[mid-1]==mid)
			return mid+1;
		else if(arr[mid]!=mid+1)
			ei=mid-1;
		else
			si=mid+1;	
	}
	return -1;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    cout<<find(arr,n);
}
