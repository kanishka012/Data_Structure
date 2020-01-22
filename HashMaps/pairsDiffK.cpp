#include<iostream>
using namespace std;


#include<unordered_map>
#include<iostream>
using namespace std;
void printPairs(int *input, int n, int k) {
    unordered_map<int,int>a;
    for(int i=0;i<n;i++)
        a[input[i]]++;
    for(int i=0;i<n;i++)
    {
        if(k==0)
        {
            int x=(a[input[i]]*(a[input[i]]-1))/2;
            for(int j=0;j<x;j++)
            {    
                cout<<input[i]<<" "<<input[i]<<endl;
            }
        }
        else
        {
            int x=a[input[i]+k];
            int y=a[input[i]-k];
            int z=a[input[i]];
            for(int j=0;j<x*z;j++)
            {    
                cout<<input[i]<<" "<<input[i]+k<<endl;
            }
            for(int j=0;j<y*z;j++)
            {    
                cout<<input[i]-k<<" "<<input[i]<<endl;
            }
            
        }
        a[input[i]]=0;
    }   
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
