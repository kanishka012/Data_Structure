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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    
  	if(root1->data==root2->data)
    {
      if(root1->children.size()==root2->children.size())
      {
      	for(int i=0;i<root1->children.size();i++)
      	{
        	bool a=isIdentical(root1->children[i],root2->children[i]);
          	if(a==false)
              return false;
      	}
        return true;
      }
      else
        return false;
    }
  return false;

}

int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    if(isIdentical(root1, root2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
