#include<iostream>
using namespace std;
#include <vector>
#include<unordered_map>

vector<int> longestSubsequence(int *arr, int n){
    unordered_map<int,bool>a;
    for(int i=0;i<n;i++)
        a[arr[i]]=true;
    int max=0,start;
    for(int i=0;i<n;i++)
    {
        int len=0,s=0;
        if(a[arr[i]])
        {
            int k=arr[i];
            s=k;
            while(a.count(k)>0)
            {
                a[k]=false;
                len++;
                k++;
            }
            k=arr[i]-1;
            while(a.count(k)>0)
            {
                a[k]=false;
                s=k;
                len++;
                k--;
            }
            if(len>max)
            {
                max=len;
                start=s;
            }
            else if(len==max)
            {
            for(int j=0;j<n;j++)
            {
                if(arr[j]==s)
                {
                    max=len;
                    start=s;
                    break;
                }
                if(arr[j]==start)
                {
                    break;
                }
            }
            }
        }
    }
    
    vector<int>v;
    for(int i=start;i<start+max;i++)
        v.push_back(i);
    return v;   
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	vector<int> output = longestSubsequence(input, n);
	for(int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}
