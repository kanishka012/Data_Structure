#include <iostream>
#include<algorithm>
using namespace std;

int binarySearch(int arr[], int size, int key) {
  	int left=0,right=size-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]<key)
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    int key;
    cin>>key;
    sort(arr,arr+n);
    int ans = binarySearch(arr,n,key);
    cout<< ans << endl;
}
