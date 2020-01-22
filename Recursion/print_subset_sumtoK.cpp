#include <iostream>
using namespace std;

void print(int in[],int n,int k,int out[]);
void printSubsetSumToK(int input[], int size, int k) {
    
  	int output[size]={0};
    print(input,size,k,output);
}
void print(int in[],int n,int k,int out[])
{
  if(n==0)
  {
    if(k==0)
    {
      int i;
      for(i=1;i<out[0];i++)
        cout<<out[i]<<" ";
      cout<<out[i]<<endl;
      return;
    }
    else
      return;
  }
  int o2[1000];
  for(int i=0;i<=out[0];i++)
    o2[i]=out[i];
  print(in+1,n-1,k,out);
  o2[0]+=1;
  int a=o2[0];
  o2[a]=in[0];
  print(in+1,n-1,k-in[0],o2);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
