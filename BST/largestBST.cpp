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
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};
#include<limits.h>
using namespace std;
class large
{
    public:
    int min;
    int max;
    int height;
    bool isBST;
};
large * helper(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
        large *x=new large();
        x->min=INT_MAX;
        x->max=INT_MIN;
        x->height=0;
        x->isBST=true;
        return x;
    }
    large *x=helper(root->left);
    large *y=helper(root->right);    
    large *ans=new large();
    ans->min=min(root->data,min(x->min,y->min));
    ans->max=max(root->data,max(x->max,y->max));
    if(x->isBST && y->isBST)
    {
        if(root->data>x->max && root->data<=y->min)
        {
            ans->height=max(x->height,y->height)+1;
            ans->isBST=true;
        }
        else
        {
            ans->isBST=false;
            ans->height=max(x->height,y->height);
        }
        
    }
    else
    {
        ans->isBST=false;
        ans->height=max(x->height,y->height);
    }
    return ans;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return helper(root)->height;
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
    cout << largestBSTSubtree(root);
    delete root;
}
