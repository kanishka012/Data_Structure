#include <iostream>
#include<string.h>
using namespace std;

void replacePi(char input[]) {

	if(input[0]=='\0')
      return;
  	if(input[0]=='p' && input[1]=='i')
    {
      input[0]='3';
      input[1]='.';
      int l=strlen(input);
      int j=l;
      for(int i=l+2;i>0 && j>=0;i--)
      {
        input[i]=input[j];
        j--;
      }
      input[2]='1';
      input[3]='4';
      replacePi(input+4);
      
    }
  	else
      replacePi(input+1);
}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
