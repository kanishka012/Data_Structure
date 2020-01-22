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

using namespace std;
void printNodes(BinaryTreeNode<int>*root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        cout<<root->data<<endl;
        return ;
    }
    printNodes(root->left,k-1);
    printNodes(root->right,k-1);
}
int print(BinaryTreeNode<int>*root,int node,int k)
{
    if(root==NULL)
        return -1;
    if(root->data==node)
    {
        printNodes(root,k);
        return 0;
    }
    int ld=print(root->left,node,k);
    if(ld==-1)
    {
        int rd=print(root->right,node,k);
        if(rd==-1)
            return -1;
        else
        {
            if(rd+1==k)
                cout<<root->data<<endl;
            else
                printNodes(root->left,k-(rd+1)-1);
            return 1+rd;
        }
    }
    else
    {
        if(ld+1==k)
            cout<<root->data<<endl;
        else
        {
            printNodes(root->right,k-(ld+1)-1);
        }
        return 1+ld;
    }
    
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int a=print(root,node,k);
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
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
