#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int check(string t,stack<string> s)
{
	if(s.empty())
	return 1;
	int len=t.length();
	if(t[1]=='/')
	{
		t="<"+t.substr(2,len-3)+">";
		if(t.compare(s.top())==0)
		return 0;
		else
		return 1;
	}
	return 1;
}

int isValid(string text)
{	stack<string> s1;
	int len=text.length();
	for(int i=0;i<len;i++)
	{
		if(text[i]=='<')
		{
			int j=i;
			while(text[j]!='>')
			j++;
			string temp=text.substr(i,i+(j-i+1));
			if(temp[j-1]=='/')
			{
			}
			else{
			if(check(temp,s1))
			s1.push(temp);
			else
			s1.pop();
		    }
			i=i+(j-i-1);
		}
	}
	return s1.empty();
}




int main()
{

	string text="<html><head></head><body></html>";
	int ans=isValid(text);
	cout<<"TEXT INPUT IS : "<<ans<<endl<<"0-> NOT Valid | 1-> Valid";
}
