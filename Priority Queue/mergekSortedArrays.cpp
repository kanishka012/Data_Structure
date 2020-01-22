#include <iostream>
using namespace std;
#include <vector>

class Triplet
{
    public:
    int elem;
    int arrayI;
    int elemI;
};
class PriorityQueue {
    vector<Triplet> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		I// Priority Queue is empty
        }
        return pq[0].elem;
    }
    
    void insert(Triplet element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex].elem < pq[parentIndex].elem) {
                Triplet temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    Triplet removeMin() {
        if(isEmpty())
        {
            Triplet a;
            a.elem=0;
            a.arrayI=-1;
            a.elemI=-1;
            return a;
        }
        Triplet ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftCI=(2*parentIndex)+1;
        int rightCI=(2*parentIndex)+2;
        int minIndex;
        while(leftCI<pq.size())
        {
            minIndex=parentIndex;
            if(pq[minIndex].elem>pq[leftCI].elem)
                minIndex=leftCI;
            if(rightCI<pq.size() && pq[minIndex].elem>pq[rightCI].elem)
                minIndex=rightCI;
            if(minIndex==parentIndex)
                break;
            Triplet t=pq[parentIndex];
            pq[parentIndex]=pq[minIndex];
            pq[minIndex]=t;
            parentIndex=minIndex;
            leftCI=(2*parentIndex)+1;
            rightCI=(2*parentIndex)+2;
        }
        return ans;
    } 
};
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    PriorityQueue pq1;
    int j=0;
    for(int i=0;i<input.size();i++)
    {
        Triplet new1;
        new1.elem=input[i]->at(j);
        new1.arrayI=i;
        new1.elemI=j;
        pq1.insert(new1);
    }
    vector<int>v;
    int flag=1;
    while(true)
    {
        Triplet t=pq1.removeMin();
        v.push_back(t.elem);
        Triplet a;
        a.arrayI=t.arrayI;
        a.elemI=t.elemI+1;
        if(a.elemI<input[a.arrayI]->size())
        {
            a.elem=input[a.arrayI]->at(a.elemI);
            pq1.insert(a);
        }  
        else
        {
            if(flag==input.size())
                break;
            flag++;
        }
    }
    while(!pq1.isEmpty())
    {
        Triplet t=pq1.removeMin();
        v.push_back(t.elem);
    }
    return v;
}


int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}

