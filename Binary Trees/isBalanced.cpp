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
};

using namespace std;

class Pair
{
  public:
  int height;
  bool isBalance;
};
Pair* helper(BinaryTreeNode<int> *root)
{
  Pair *a=new Pair();
  if(root==NULL)
  {
    a->height=0;
    a->isBalance=true;
    return a;
  }
  Pair *b=helper(root->left);
  Pair *c=helper(root->right);
  if(b->isBalance==true && c->isBalance==true)
  {
    if(abs(b->height-c->height)<=1)
    {
  			a->isBalance=true;
      		if(b->height>c->height)
      			a->height=b->height+1;
    		else
      			a->height=c->height+1;
    }
     else
     {
     	 a->isBalance=false;
       	 a->height=0;
     }
     
    
  }
  else
  {
    a->isBalance=false;
    a->height=0;
  }
  return a;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
  Pair *a=helper(root);
  return a->isBalance;
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
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
}