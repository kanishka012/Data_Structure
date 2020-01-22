#include <iostream>
#include <string>
using namespace std;


int returnPermutations(string input, string output[]){
	if(input.size()==1)
    {
      output[0]=input[0];
      return 1;
    }
  	string small=input.substr(1);
  	int smallOutput=returnPermutations(small,output);
  	int j=0,k=smallOutput;
  	int len=output[0].size();
  	while(j<len)
    {
      for(int i=0;i<smallOutput;i++)
      {
    	output[k]=output[i];
        k++;
      }
      j++;
    }
  	j=0;int c=0;
  	while(j<=len)
    {
      for(int i=0;i<smallOutput;i++)
      {
        output[c]=output[c].substr(0,j)+input[0]+output[c].substr(j);
        c++;
      }
      j++;
    }
  
  return k;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
