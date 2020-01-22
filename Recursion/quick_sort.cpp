#include<iostream.h>
using namespace std;

void qs(int a[],int si,int ei);
int partition(int a[],int si,int ei);
void quickSort(int input[], int size) {
	qs(input,0,size-1);
}
void qs(int a[],int si,int ei)
{
  if(si>=ei)
    return;
  int c=partition(a,si,ei);
  qs(a,si,c-1);
  qs(a,c+1,ei);
}
int partition(int a[],int si,int ei)
{
  int i,j,c=0;
  int x=a[si];
  for(i=si+1;i<=ei;i++)
    if(a[i]<=x)
      c++;
  int temp=x;
  a[si]=a[si+c];
  a[si+c]=temp;
  i=si;j=ei;
  while(i<si+c && j>si+c)
  {
    if(a[i]>x && a[j]<=x)
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;j--;
    }
    else if(a[i]<=x)
      i++;
    else if(a[j]>x)
      j--;
  }
  return si+c;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


