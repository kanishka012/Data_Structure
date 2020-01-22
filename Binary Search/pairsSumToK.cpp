#include <iostream>
#include<algorithm>
using namespace std;

void printPairs(int arr[], int size, int sum) {
  	int left=0,right=size-1;
	while(left<right){
		if(arr[left]+arr[right]==sum)
			cout<<arr[left]<<" "<<arr[right]<<endl;
		if(arr[left]+arr[right]>sum)
			right--;
		else
			left++;
			
	}
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    sort(arr,arr+n);
    int sum;
    cin>>sum;
    printPairs(arr,n,sum);
}
