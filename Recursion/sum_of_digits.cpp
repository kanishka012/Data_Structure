#include <iostream>
using namespace std;

int sumOfDigits(int n) {
	if(n==0)
      return 0;
  	int small=sumOfDigits(n/10);
  	int r=n%10;
  	return r+small;
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
