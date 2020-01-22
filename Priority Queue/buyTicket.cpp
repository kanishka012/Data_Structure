#include <iostream>
#include <vector>
using namespace std;
#include<queue>

int buyTicket (int *arr, int n, int k){
    queue<int>ind;
    priority_queue<int>pq;
    for(int i=0;i<n;i++)
    {
        ind.push(i);
        pq.push(arr[i]);
    }
    int t=0;
    while(true)
    {
        int a=ind.front();
        ind.pop();
        if(arr[a]==pq.top())
        {
            t++;
            if(a==k)
            {
                return t;
            }
            pq.pop();
        }
        else
        {
            ind.push(a);
        }
    }
}


int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}

