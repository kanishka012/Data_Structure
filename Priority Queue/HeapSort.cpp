#include <iostream>
using namespace std;

void removeMin(int input[],int n);
void inplaceHeapSort(int input[], int n){
    for(int i=1;i<n;i++)
    {
        int childIndex=i;
        while(childIndex>0)
        {
            int parentIndex=(childIndex-1)/2;
            if(input[parentIndex]>input[childIndex])
            {
                int t=input[parentIndex];
                input[parentIndex]=input[childIndex];
                input[childIndex]=t;
            }
            else
                break;
            childIndex=parentIndex;
        }
    }
    int size=n;
    for(int i=0;i<n;i++)
    {
        removeMin(input,size);
        size--;
    }
}
void removeMin(int input[],int n)
{
    int t=input[0];
    input[0]=input[n-1];
    input[n-1]=t;
    n--;
    int parentIndex=0;
    int leftCI=(2*parentIndex)+1;
    int rightCI=(2*parentIndex)+2;
    while(leftCI<n)
    {
        int minIndex=parentIndex;
        if(input[leftCI]<input[minIndex])
            minIndex=leftCI;
        if(rightCI<n && input[rightCI]<input[minIndex])
            minIndex=rightCI;
        if(minIndex==parentIndex)
            break;
        int t1=input[parentIndex];
        input[parentIndex]=input[minIndex];
        input[minIndex]=t1;
        parentIndex=minIndex;
        leftCI=(2*parentIndex)+1;
        rightCI=(2*parentIndex)+2;
    }
}


int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	return 0;
}

