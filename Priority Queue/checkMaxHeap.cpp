#include <iostream>
using namespace std;

bool func(int arr[],int i,int n)
{
    int l=2*i+1;
    int r=2*i+2;
    if(l<n)
    {
        if(arr[l]<=arr[i])
        {
            if(r<n)
            {
                if(arr[r]<=arr[i])
                    return true;
            }
            else
                return true;
        }
    }
    return false;
}
bool checkMaxHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--)
    {
        if(func(arr,i,n)==false)
            return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}

