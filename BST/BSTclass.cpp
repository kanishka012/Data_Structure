#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

#include<limits.h>
class BST {
	BinaryTreeNode<int>*root;
    public:
    BST()
    {
        root=NULL;
    }
    ~BST()
    {
        delete root;
    }
    private:
    bool hasData(int data,BinaryTreeNode<int>*r)
    {
        if(r==NULL)
            return false;
        if(r->data==data)
            return true;
        else if(r->data<data)
            return hasData(data,r->right);
        else
            return hasData(data,r->left);
    }
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>*r)
    {
        if(r==NULL)
        {
            BinaryTreeNode<int>* n=new BinaryTreeNode<int>(data);
            return n;
        }
        if(r->data<data)
        {
            BinaryTreeNode<int>* ans=insert(data,r->right);
            r->right=ans;
        }
        else if(r->data>data)
        {
            BinaryTreeNode<int>* ans=insert(data,r->left);
            r->left=ans;
        }
        return r;
    }
    BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>*r)
    {
        if(r==NULL)
            return NULL;
        if(r->data<data)
        {
            BinaryTreeNode<int>* ans=deleteData(data,r->right);
            r->right=ans;
        }
        else if(r->data>data)
        {
            BinaryTreeNode<int>* ans=deleteData(data,r->left);
            r->left=ans;
        }
        else
        {
            if(r->left==NULL && r->right==NULL)
            {
                delete r;
                return NULL;
            } 
            else if(r->left==NULL) 
            {
                 BinaryTreeNode<int>* temp=r->right;
                 r->right=NULL;
                 delete r;
                 return temp;
            }
            else if(r->right==NULL)     
            {
                 BinaryTreeNode<int>* temp=r->left;
                 r->left=NULL;
                 delete r;
                 return temp;
            }
            else
            {
                BinaryTreeNode <int>*minNode=r->right;
                while(minNode->left!=NULL)
                {
                    minNode=minNode->left;
                }
                BinaryTreeNode <int>*rightMin=minNode;
                r->data=rightMin->data;
                r->right=deleteData(rightMin->data,r->right);
                return r;
            }
        } 
    }
    void print(BinaryTreeNode<int> *r)
    {
        if(r==NULL)
            return;
        cout<<r->data<<":";
        if(r->left!=NULL)
            cout<<"L:"<<r->left->data<<",";
        if(r->right!=NULL)
            cout<<"R:"<<r->right->data;
        cout<<endl;
        print(r->left);
        print(r->right);
    }
    public:
    bool hasData(int data)
    {
        return hasData(data,root);
    }
    void insert(int data)
    {
        BinaryTreeNode<int>* a=insert(data,root);
        root=a;
    }
    void printTree()
    {
        print(root);
    }
    void deleteData(int data)
    {
        BinaryTreeNode<int>* a=deleteData(data,root);
        root=a;
    }
};

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}
