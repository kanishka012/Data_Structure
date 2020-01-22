#include <iostream>
#include <string>
using namespace std;


void print(int n,string output);
void printKeypad(int num){
  int r=num%10;
  string c[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  int s=c[r].size();
  string a="";
  for(int i=0;i<s;i++)
  {
    a+=c[r][i];
  	print(num/10,a);
    a="";
  }
}
void print(int n,string output)
{
  if(n==0)
  {
    cout<<output<<endl;
    return;
  }
  int r=n%10;
  string c[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  int s=c[r].size();
  for(int i=0;i<s;i++)
  	print(n/10,c[r][i]+output);
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
