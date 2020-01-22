#include <iostream>
using namespace std;


void print(int input[],int n,int output[],int m);
void printSubsetsOfArray(int input[], int size) {
    int output[10];
  	print(input,size,output,0);
  	
}
void print(int input[],int n,int output[],int m)
{
  if(n==0)
  {
    for(int i=0;i<m;i++)
      cout<<output[i]<<" ";
   	cout<<endl;
    return;
  }
  int newoutput[m+1],i;
  for(i=0;i<m;i++)
    newoutput[i]=output[i];
  newoutput[i]=input[0];
  print(input+1,n-1,output,m);
  print(input+1,n-1,newoutput,m+1);
  
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
