#include <iostream>
using namespace std;


int getCodes(string input, string output[10000]) {
   
  if(input[0]=='\0')
  {
    output[0]="";
    return 1;
  }
  string o1[1000],o2[1000];
  int r1=getCodes(input.substr(1),o1);
  int r2=0;
    int n=input[0]-48;
  char c='a'+n-1;
  for(int i=0;i<r1;i++)
  	o1[i]=c+o1[i];
  int i,j;
  for(i=0;i<r1;i++)
    output[i]=o1[i];
  j=i;
  n=(input[0]-48)*10+(input[1]-48);
  c='a'+n-1;
  if(n>=10 && n<=26)
  {
    r2=getCodes(input.substr(2),o2);
   	for(int i=0;i<r2;i++)
  		o2[i]=c+o2[i];
  	for(i=0;i<r2;i++)
  	{ 
    	output[j]=o2[i];
    	j++;
  	}
  }
  return r1+r2;
  
}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
