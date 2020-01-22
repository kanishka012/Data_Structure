#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;


int stringToNumber(char input[]) {
	if(input[0]=='\0')
      return 0;
  	int a=input[0]-48;
    int l=strlen(input);
  	return a*(pow(10,l-1)) + stringToNumber(input+1);
}



int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
