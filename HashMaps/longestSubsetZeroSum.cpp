#include<iostream>
using namespace std;

#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int size)
{
    unordered_map<int,int>a;
    int sum=0,max=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
        if(a.count(sum)>0)
        {
            int l=i-a[sum];
            if(l>max)
                max=l;
        }
        else
        {
            a[sum]=i;
        }
    }
    return max;
}
int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}


