#include <iostream>
using namespace std;

#include<stack>
#include<string.h>
int countBracketReversals(char input[]){
	
	int i=0;
  	stack<char> s;
  	int len=strlen(input);
  	if(len%2!=0)
      return -1;
  	else
    {
  		while(input[i]!='\0')
    	{
      		if(input[i]=='{')
        		s.push(input[i]);
      		else
      		{
 				if(s.empty())
                {
                  s.push(input[i]);
                }
              	else
                {
                  if(s.top()=='{')
                    s.pop();
                  else
                    s.push(input[i]);
                }
      		}
          	i++;
    	}
      	int count=0;
      	while(!s.empty())
        {
      		char c1=s.top();
      		s.pop();
          	char c2=s.top();
          	s.pop();
          	if(c1==c2)
              count++;
          	else
              count+=2;
        }
      	return count;
    }
}

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}