#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {
 //recursion handles 1 to n-1 integers
  /*
  if(size==0)
    return -1;
  if(input[size-1]==x)
    return size-1;
  int small=lastIndex(input,size-1,x);
  return small;*/

  
  //recursion handles 2 to n integers
  if(size==0)
    return -1;
  int small=lastIndex(input+1,size-1,x);
  if(small==-1)
  {
    if(input[0]==x)
      return 0;
	else
      return -1;
  }
  else
    return small+1;
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
    
    cout << lastIndex(input, n, x) << endl;

}


