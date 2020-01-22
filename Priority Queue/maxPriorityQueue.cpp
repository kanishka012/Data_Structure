#include <iostream>
using namespace std;

#include<vector>
class PriorityQueue {
    vector<int>pq;
    public:
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size()==0;
    }
    int getMax()
    {
        if(isEmpty())
            return 0;
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex=pq.size()-1;
        while(childIndex>0)
        {
            int parentIndex=(childIndex-1)/2;
            if(pq[parentIndex]<pq[childIndex])
            {
                int t=pq[parentIndex];
                pq[parentIndex]=pq[childIndex];
                pq[childIndex]=t;
            }
            else
                break;
            childIndex=parentIndex;
        }
    }
    int removeMax()
    {
        if(isEmpty())
            return 0;
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int leftCI=(2*parentIndex)+1;
        int rightCI=(2*parentIndex)+2;
        while(leftCI<pq.size())
        {
            int maxIndex=parentIndex;
            if(pq[leftCI]>pq[maxIndex])
                maxIndex=leftCI;
            if(rightCI<pq.size() && pq[rightCI]>pq[maxIndex])
                maxIndex=rightCI;
            if(maxIndex==parentIndex)
                break;
            int t=pq[parentIndex];
            pq[parentIndex]=pq[maxIndex];
            pq[maxIndex]=t;
            parentIndex=maxIndex;
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
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
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

