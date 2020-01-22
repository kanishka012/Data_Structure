#include <iostream>
using namespace std;
#include <climits>

class PriorityQueue {
    vector<int> pq;
    
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
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        if(isEmpty())
            return INT_MIN;
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftCI=(2*parentIndex)+1;
        int rightCI=(2*parentIndex)+2;
        int minIndex;
        while(leftCI<pq.size())
        {
            minIndex=parentIndex;
            if(pq[minIndex]>pq[leftCI])
                minIndex=leftCI;
            if(rightCI<pq.size() && pq[minIndex]>pq[rightCI])
                minIndex=rightCI;
            if(minIndex==parentIndex)
                break;
            int t=pq[parentIndex];
            pq[parentIndex]=pq[minIndex];
            pq[minIndex]=t;
            parentIndex=minIndex;
            leftCI=(2*parentIndex)+1;
            rightCI=(2*parentIndex)+2;
        }
        return ans;
    }    
};


int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}

