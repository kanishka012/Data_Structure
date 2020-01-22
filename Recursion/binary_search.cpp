#include <iostream>
using namespace std;


int helper(int in[],int s,int e,int x);
int binarySearch(int input[], int size, int element) {
    
  	int start=0,end=size-1;
  int a=helper(input,start,end,element);
}
int helper(int in[],int s,int e,int x)
{
  if(s>e)
    return -1;
  int mid=(s+e)/2;
  if(in[mid]==x)
    return mid;
  else if(in[mid]>x)
    return helper(in,s,mid-1,x);
  else
    return helper(in,mid+1,e,x);
}
int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
