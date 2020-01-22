#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
    
	if(n==0)
    {
      output[0][0]=0;
      return 1;
    }
  	int k;
  	int small=subset(input+1,n-1,output);
  	for(int i=0;i<small;i++)
    {
      output[i+small][0]=1+output[i][0];
      output[i+small][1]=input[0];k=2;
      for(int j=1;j<=output[i][0];j++)
      {
        output[i+small][k]=output[i][j];
        k++;
      }
    }
	return 2*small;
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
