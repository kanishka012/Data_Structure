#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) {
     		delete left;
    	}
	if(right) {
     		delete right;
    	}
    }
};

using namespace std;
void array(BinaryTreeNode<int> *root,int *a,int *c)
{
    if(root==NULL)
        return;
    a[*c]=root->data;(*c)++;
    array(root->left,a,c);
    array(root->right,a,c);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    int *arr=new int[1000];
    int c=0;
     array(root,arr,&c) ;
    
    for(int i=0;i<c-1;i++)
        for(int j=0;j<c-i-1;j++)
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
    
    int i=0,j=c-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==sum)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;i++;j--;
        }
        else if(arr[i]+arr[j]<sum)
            i++;
        else
            j--;
    }
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}
