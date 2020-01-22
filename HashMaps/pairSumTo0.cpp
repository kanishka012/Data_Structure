#include<iostream>
using namespace std;

#include<unordered_map>

void PairSum(int *input, int n) {
    unordered_map<int,int>a;
    for(int i=0;i<n;i++)
    {
        if(a[-input[i]]>0)
        {
           for(int j=0;j<a[-input[i]];j++)
           {
               if(input[i]>0)
                   cout<<-input[i]<<" "<<input[i]<<endl;
               else
                   cout<<input[i]<<" "<<-input[i]<<endl;
           }
        }
        a[input[i]]++;
    }
}

int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}
