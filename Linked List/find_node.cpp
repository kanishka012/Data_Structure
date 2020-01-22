#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

int indexOfNIter(Node *head, int n) {
   /*Node *temp=head;
  	int i=0;
  while(temp!=NULL)
  {
    if(temp->data==n)
    {
      return i;
    }
    temp=temp->next;
    i++;
  }
  return -1;*/
  
  //Using Recurssion
  if(head==NULL)
    return -1;
  if(head->data==n)
    return 0;
  int small=indexOfNIter(head->next,n);
  if(small!=-1)
  	return small+1;
  else
    return small;
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int n;
    cin >> n;
    cout << indexOfNIter(head, n);
    
}

