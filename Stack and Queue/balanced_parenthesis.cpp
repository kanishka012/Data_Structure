#include <iostream>
using namespace std;

#include<stack>
bool checkBalanced(char *exp) {
	
  	int i=0;
  	stack<char> s;
	while(exp[i]!='\0')
    {
      if(exp[i]=='{' ||exp[i]=='(' ||exp[i]=='[')
        s.push(exp[i]);
      else if(exp[i]=='}' ||exp[i]==')' ||exp[i]==']')
      {
        if(!s.empty())
        {
        	char c=s.top();
        	if(c=='(' && exp[i]==')')
          		s.pop();
			else if(c=='{' && exp[i]=='}')
          		s.pop();
			else if(c=='[' && exp[i]==']')
          		s.pop();
        	else
          		return false;
        }
        else
          return false;
      }
      i++;     
    }
   if(s.empty())
     return true;
   else
     return false;
}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
