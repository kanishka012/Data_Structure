#include<iostream>
using namespace std;

#include<string.h>
#include<unordered_map>
char* uniqueChar(char *str){ 
    unordered_map<char,int>a;
    int n=strlen(str);
    char *s=new char[n+1];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(a.count(str[i])==0)
            s[k++]=str[i];
        a[str[i]]++;
    }
    s[k]='\0';
    return s;
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
