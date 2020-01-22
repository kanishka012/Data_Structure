
#include<bits/stdc++.h> 
using namespace std; 
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    Node (int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  

void printPostOrder(struct Node *root) 
{ 
    
    if (!root) 
        return;  
    stack<Node *> s1, s2; 
    s1.push(root); 
    Node* node; 
    while (!s1.empty()) { 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node); 
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 
    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout << node->data << " "; 
    } 
	
} 
  
int main() 
{ 
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    printPostOrder(root); 
    return 0; 
} 
