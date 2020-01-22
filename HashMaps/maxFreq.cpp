#include<iostream>
using namespace std;

#include<unordered_map>
int highestFrequency(int *input, int n){	   
    unordered_map<int,int>a;
    for(int i=0;i<n;i++)
        a[input[i]]++;
    int max=0,temp;
    for(int i=0;i<n;i++)
        if(a[input[i]]>max)
        {
            max=a[input[i]];
            temp=input[i];
        }
    return temp;
}

int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}


