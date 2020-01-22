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


/*TreeNode<int>* maxSumNode(TreeNode<int> *root){
  	//IST APPROACH
 TreeNode<int> *ans=root;
  int sum=root->data;
  for(int i=0;i<root->children.size();i++)
  {
    sum+=root->children[i]->data;
  }
  for(int i=0;i<root->children.size();i++)
  {
    TreeNode<int> *x=maxSumNode(root->children[i]);
    int xsum=x->data;
    for(int j=0;j<x->children.size();j++)
      xsum+=x->children[j]->data;
    if(xsum>sum)
    {
      sum=xsum;ans=x;
    }
  }
  return ans;

}*/

//II APPROACH
class Pair
{
  public:
  TreeNode<int> *node;
  int sum;
  Pair(TreeNode<int> *n,int s)
  {
    node=n;
    sum=s;
  }
};
Pair * helper(TreeNode<int>*root);
TreeNode<int>* maxSumNode(TreeNode<int> *root){
  Pair *b=helper(root);
  return b->node;
}
Pair * helper(TreeNode<int>*root)
{
 	Pair *ans=new Pair(root,root->data);
  	for(int i=0;i<root->children.size();i++)
      ans->sum+=root->children[i]->data;
  	for(int i=0;i<root->children.size();i++)
    {
      Pair *x=helper(root->children[i]);
      if(x->sum>ans->sum)
      {
        ans=x;
      }
    }
  	return ans;
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}


