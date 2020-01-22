#include <iostream>
#include <string>
using namespace std;

void print(string input,string output);
void printPermutations(string input){
	string output="";
  	print(input,output);
}
void print(string input,string output)
{
  if(input.size()==0)
  {
     cout<<output<<endl;
     return;
  }
  
  for(int i=0;i<input.size();i++)
  {
    string out=output;
    out+=input[i];
    string small=input.substr(0,i)+input.substr(i+1);
    print(small,out);
  }
}
int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
