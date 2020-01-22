#include<bits/stdc++.h>
using namespace std;

int wordsCount(string text)
{
	int count=0;
	text=" "+text+" ";
	int i=1;
	while(text[i]!=0)
	{
		if(text[i]!=' '&&text[i-1]==' ')
		{
			count++;
		}
		i++;
	}
	return count;
}


int main()
{
	string text="    hey this is   me  at       github    ";
    cout<<"NUMBER OF WORDS : "<<wordsCount(text);
}
