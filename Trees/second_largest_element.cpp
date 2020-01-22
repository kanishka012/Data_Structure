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
#include <climits>

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

class Pair
{
  public:
  TreeNode<int>* max;
  TreeNode<int>* sm;
  Pair()
  {
    max=NULL;
    sm=NULL;
  }
};
Pair * helper(TreeNode<int> *root)
{
  Pair *ans=new Pair();
  ans->max=root;
  for(int i=0;i<root->children.size();i++)
  {
     Pair *temp=helper(root->children[i]);
    
     if(ans->max->data<temp->max->data)
     {
       TreeNode<int>*x=ans->max;
       ans->max=temp->max;
       if(ans->sm==NULL && temp->sm==NULL)
         ans->sm=x;
       else if(ans->sm==NULL)
       {
         if(x->data>temp->sm->data)
           ans->sm=x;
         else
           ans->sm=temp->sm;
       }	
       else if(temp->sm==NULL)
       	ans->sm=x;
       else
       {
         if(x->data>temp->sm->data)
         	  ans->sm=x;
         else
           	ans->sm=temp->sm;
       }  
     }
     else if(ans->max->data>temp->max->data)
     {
       if(ans->sm==NULL && temp->sm==NULL)
         ans->sm=temp->max;
       else if(ans->sm==NULL)
           ans->sm=temp->max;
       else if(temp->sm==NULL)
         if(ans->sm->data<temp->max->data)
         	ans->sm=temp->max;  
       else
         if(ans->sm->data<temp->max->data)
         ans->sm=temp->max;    
     }
    
     //cout<<ans->max->data<<" "<<ans->sm->data<<endl;
  }
  return ans;
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
  Pair *b=helper(root);
  return b->sm;
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}
