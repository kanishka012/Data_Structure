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

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

using namespace std;

int count(BinaryTreeNode<int>*root)
{
    if(root==NULL)
        return 0;
    int a=count(root->left);
    int b=count(root->right);
    return a+b+1;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    if(root==NULL)
        return;
    stack<BinaryTreeNode<int> *>s1,s2;
    int a=count(root);
    int b=0;
    BinaryTreeNode<int> *curr1=root;
    BinaryTreeNode<int> * curr2=root;
    
    while(b<a-1)
    {
        while(curr1!=NULL)
            {
                s1.push(curr1);
                curr1=curr1->left;
            }
            
            while(curr2!=NULL)
            {
                s2.push(curr2);
                curr2=curr2->right;
            }
        int l=s1.top()->data,m=s2.top()->data;
        if(l+m==s)
        {
            cout<<l<<" "<<m<<endl;
            curr1=s1.top()->right;
            curr2=s2.top()->left;
            s1.pop();s2.pop();b++;b++;
             
        }
        else if(l+m>s)
        {
            curr2=s2.top()->left;b++;
            s2.pop();
            
        }
        else
        {
            curr1=s1.top()->right;b++;
            s1.pop();
             
        }
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		BinaryTreeNode<int> *first = q.front();
		q.pop();
		if(first == NULL) {
			if(q.empty()) {
				break;
			}
			cout << endl;
			q.push(NULL);
			continue;
		}
		cout << first -> data << " ";
		if(first -> left != NULL) {
			q.push(first -> left);
		}
		if(first -> right != NULL) {
			q.push(first -> right);
		}
	}
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}
