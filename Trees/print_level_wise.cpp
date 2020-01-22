#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <queue>

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pending;
  	pending.push(root);
    int i=0;
  	while(!pending.empty())
    {
      TreeNode<int>*front=pending.front();
      cout<<front->data<<":";
      pending.pop();
      int a=front->children.size()-1;
      for(i=0;i<a;i++)
      {
         TreeNode<int>* child=front->children[i];
         cout<<child->data<<",";
         pending.push(child);
      }
      if(front->children.size()>=1)
      {
	  	TreeNode<int>* child=front->children[a];
      	cout<<child->data;
      	pending.push(child);
      }
      cout<<endl;
    }
  
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}
