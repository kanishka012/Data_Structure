#include <iostream>
using namespace std;

void merge1(int input[],int si,int ei)
{
  if(si>=ei)
    return;
  int mid=(si+ei)/2;
  merge1(input,si,mid);
  merge1(input,mid+1,ei);
  int i=si,j=mid+1;
  int arr[ei+1],k=0;
  while(i<=mid && j<=ei)
  {
    if(input[i]<=input[j])
    {
      arr[k]=input[i];
      k++;i++;
    }
    else
    {
      arr[k]=input[j];
      k++;j++;
    }
  }
  while(i<=mid)
  {
    arr[k]=input[i];
    k++;i++;
  }
  while(j<=ei)
  {
    arr[k]=input[j];
    k++;j++;
  }
  k=0;
  for(i=si;i<=ei;i++,k++)
    input[i]=arr[k];
  //return;
 // merge1(input,si,ei); 
}

void mergeSort(int input[], int size){
	// Write your code here
	merge1(input,0,size-1);    
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
