#include <iostream>
using namespace std;
#include <queue>
#include<stack>
void reverseQueue(queue<int> &q) {
	// Write your code here
 	stack<int>s;
	while(!q.empty())
    {
      int a=q.front();
      q.pop();
      s.push(a);
    }
  	while(!s.empty())
    {
      int a=s.top();
      q.push(a);
      s.pop();
    }
}

int main() {
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	q.push(val);
    }
    reverseQueue(q);
    while(!q.empty()) {
    	cout << q.front() << " ";
    	q.pop();
    }
}
