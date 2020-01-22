#include <iostream>
using namespace std;

int countZeros(int n) {
	if(n==0)
      return 0;
  	int small=countZeros(n/10);
  	int r=n%10;
  	if(r==0)
      return 1+small;
  	else
      return small;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
