#include <iostream>
using namespace std;


void print(string in,string out);
void printAllPossibleCodes(string input) {
    string output="";
    print(input,output);
}
void print(string in,string out)
{
	if(in.size()==0)
    {
      cout<<out<<endl;
      return;
    }
  	string o1,o2;
  	int n=in[0]-48;
  	char a='a'+n-1;
  	o1=out+a;
  	print(in.substr(1),o1);
  	n=((in[0]-48)*10)+(in[1]-48);
    if(n>=10 && n<=26)
    {
      a='a'+n-1;
      o2=out+a;
      print(in.substr(2),o2);
    }
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
