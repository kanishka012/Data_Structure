#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
  if(num==0 || num==1)
  {
    output[0]="";
    return 1;
  }
  int smallno=num/10;
  int smallOutput=keypad(smallno,output);
  string a[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  int n=num%10;
  int b=a[n].size(),j=1;
  int k=smallOutput;
  while(j<b)
  {
   	for(int i=0;i<smallOutput;i++)
    {
      output[k]=output[i];
      k++;
    }
    j++;
  }
  j=0;k=0;
  while(j<b)
  {
  	for(int i=0;i<smallOutput;i++)
  	{
    	output[k]+=a[n][j];
        k++;
  	}
    j++;
  }
  return b*smallOutput;
}



int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
