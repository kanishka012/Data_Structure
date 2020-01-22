#include <iostream>
using namespace std;

int countRotations(int arr[],int si,int ei)
{
	if(si>ei)
		return 0;
	if(si==ei)
		return si;
	int mid=si+(ei-si)/2;
	if(mid<ei && arr[mid+1]<arr[mid])	
		return mid+1;
	if(mid>si && arr[mid]<arr[mid-1])
		return mid;
	if(arr[mid]<arr[ei])
		return countRotations(arr,si,mid-1);
	return countRotations(arr,mid+1,ei);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    cout<<countRotations(arr,0,n-1);
}
