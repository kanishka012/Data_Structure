#include<iostream>
using namespace std;


int allIndexes(int input[], int size, int x, int output[]) {
  //1Method
  /*if(size==0)
    return 0;
  int ans=allIndexes(input+1,size-1,x,output);
  for(int i=0;i<ans;i++)
    	output[i]+=1;
  if(input[0]==x)
  {
    for(int i=ans;i>0;i--)
      output[i]=output[i-1];
    output[0]=0;
    return ans+1;
  }
  else
    return ans;*/
  
  
  //2Method
  if(size==0)
    return 0;
  int ans=allIndexes(input,size-1,x,output);
  if(input[size-1]==x)
  {
    output[ans]=size-1;
    return ans+1;
  }
  else
    return ans;
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


