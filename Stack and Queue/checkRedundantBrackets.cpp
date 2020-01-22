#include <iostream>
using namespace std;


#include<stack>
bool checkRedundantBrackets(char *input) {
	// Write your code here
    stack<int>s;	
    int i=0,c=0;
  	while(input[i]!='\0')
    {
      if(input[i]!=')')
        s.push(input[i]);
      else
      {
        c=0;
        while(s.top()!='(')
        {
          s.pop();
          c++;
        }
        
        if(c==0)
          return true;
        s.pop();
      }
      i++;
    }
    return false;
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
