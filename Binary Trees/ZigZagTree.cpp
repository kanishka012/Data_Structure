#include <iostream>
#include <queue>
#include <stack>

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
};

using namespace std;

void zigZagOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int> *>s1;       //RIGHT TO LEFT
	stack<BinaryTreeNode<int> *>s2;  	  //LEFT TO RIGHT
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            BinaryTreeNode<int>*t=s1.top();
            s1.pop();
            cout<<t->data<<" ";
            if(t->left!=NULL)
                s2.push(t->left);
            if(t->right!=NULL)
                s2.push(t->right);
        }
        cout<<endl;
         while(!s2.empty())
        {
            BinaryTreeNode<int>*t=s2.top();
            s2.pop();
            cout<<t->data<<" ";
            if(t->right!=NULL)
                s1.push(t->right);
             if(t->left!=NULL)
                s1.push(t->left);
        }
        cout<<endl;
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
    zigZagOrder(root);
}
