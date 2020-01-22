#include <iostream>
#include<string.h>
using namespace std;

void pairStar(char input[]) {
 
  if(input[0]=='\0')
      return;
  if(input[0]==input[1])
  {
    int l=strlen(input);
    int j=l;
    for(int i=j+1;i>=0 && j>=0;i--,j--)
      input[i]=input[j];
    input[1]='*';
  }
  pairStar(input+1);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
