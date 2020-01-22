#include <iostream>
#include<string.h>
using namespace std;

bool helper(char input[],int start,int end)
{
    int l=strlen(input);
  	if(start==end && l%2!=0)
      return true;
  	if(start==end+1 && l%2==0)
      return true;
  	if(input[start]==input[end])
      helper(input,start+1,end-1);
  	else
      return false;
}

bool checkPalindrome(char input[]) {
  int l=strlen(input);	  
  if(l==0 ||l==1)
      return true;
  	return helper(input,0,l-1);
}


int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
