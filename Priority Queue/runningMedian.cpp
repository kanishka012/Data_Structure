#include <iostream>
using namespace std;
#include<math.h>
#include<queue>

void findMedian(int arr[], int n){
    priority_queue<int>max;
    priority_queue<int,vector<int>,greater<int>>min;
    max.push(arr[0]);
    cout<<arr[0]<<endl;
    for(int i=1;i<n;i++)
    {
       if(arr[i]<=max.top())
       {
           max.push(arr[i]);
           if((max.size()-min.size())>1)
              {
                  int a=max.top();
                  max.pop();
                  min.push(a);
              }
       }
       else
       {
           min.push(arr[i]);
           if((min.size()-max.size())>1)
           {
                  int a=min.top();
                  min.pop();
                  max.push(a);
            }
       }
        if((min.size()+max.size())%2==0)
            cout<<(max.top()+min.top())/2<<endl;
        else
        {
            if(min.size()<max.size())
                cout<<max.top()<<endl;
            else
                cout<<min.top()<<endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);
    
    delete [] arr;
    
}

