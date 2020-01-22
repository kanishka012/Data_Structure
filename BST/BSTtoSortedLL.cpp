#include <iostream>
#include <queue>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

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
class Pair
{
  public:
    Node<int>*head;
    Node<int>* tail;
};
Pair *helper(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        Pair *ans=new Pair();
        ans->head=NULL;
        ans->tail=NULL;
        return ans;
    }
    Pair *a=helper(root->left);
    Node<int>*newNode=new Node<int>(root->data);
    if(a->head==NULL)
    {
        a->head=newNode;
        a->tail=newNode;
    }
    else
    {
        a->tail->next=newNode;
        a->tail=newNode;
    }
    Pair *b=helper(root->right);
    if(b->head!=NULL)
    {
        a->tail->next=b->head;
        a->tail=b->tail;
    }
    return a;
}
Node<int>* constructBST(BinaryTreeNode<int>* root)
{
    return helper(root)->head;
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
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}
