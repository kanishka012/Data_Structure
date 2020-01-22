#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int i,int size)
{
	int l=2*i+1;
	int r=2*i+2;
	int min;
	if(l<size&&v[l]<v[i])
	min=l;
	else
	min=i;
	if(r<size&&v[r]<v[min])
	min=r;
	
	if(min!=i)
	{
		swap(v[i],v[min]);
		heapify(v,min,size);
	}
}

void buildHeap(vector<int> &v)
{
	int n=v.size();
	n=n/2;
	for(int i=n/2;i>=0;i--)
	{
		heapify(v,i,v.size());
	}
}


void print(vector<int> v,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void heapSort(vector<int> &v, int size)
{
	cout<<"-> ";

    if(size>=1)
	{	
		swap(v[0],v[size-1]);
    	size--;
		heapify(v,0,size);
		heapSort(v,size);
    }
}

void insert_(int ele,vector<int> &v)
{
	v.push_back(ele);
	buildHeap(v);
}


void delete_(int ele,vector<int> &v)
{
	vector<int>::iterator p=find(v.begin(), v.end(),ele);
	if(p!=v.end())
	{
		v.erase(p);
		buildHeap(v);
	}
	else
	cout<<" Could Not Find ELE : "<<ele<<endl;
}



int main()
{
	int size;
	cin>>size;
	vector<int> v;
	for(int i=0;i<size;i++)
	{
		int num;
		cin>>num;
		v.push_back(num);
	}
	buildHeap(v);
	cout<<"Build Min Heap In One :"<<endl;
	print(v,size);
	
	insert_(12,v);
	cout<<"Build Min Heap After Insertion 1 Element :"<<endl;
	print(v,v.size());
	
	delete_(12,v);
	cout<<"Build Min Heap After Deleting 1 Element :"<<endl;
	print(v,v.size());
	
	heapSort(v,v.size());
	cout<<"\nBuild after sort \n";
	print(v,v.size());
}
