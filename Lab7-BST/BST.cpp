#include <iostream>
#include <cmath>
using namespace std;

struct node {
  char key;
  int value ;
  
  struct node *left=NULL;
  
   struct node *right=NULL;
};

char tranverse(node * root ,string s , int* i){
  // cout<< *i <<"= i";
  cout<< root->key<<endl;

  
  if(root->left==NULL && root->right ==NULL){
    int character =root->key;
    return character;
  }
  else if( s[*i]=='1'){
    *i=*i+1;
    tranverse(root->right,s, i);

  }else {
    tranverse(root->left,s, i);
  }

}
void decode_huff(node * root, string s) {
  int i=0;
  node * node=root;
     while (i< s.length()){
    cout<<  tranverse(node,s,&i);



     }
    
}
// Inorder traversal
void traverseInOrder(struct node *root) {

if( root == NULL){
  return;
}
traverseInOrder(root->left);
cout << root->key << " ";
traverseInOrder(root->right);

}

// Finding minimum in the node
struct node *findMin(struct node *root) {
  if(root==NULL){
    cout << " tree is empty ";
  }else if ( root->left =NULL ){
    return root;

  }
  return findMin( root->left);

}

// Insert a node
struct node *insertNode(struct node *node, char key, int value) {
if(node == NULL) {
		node = new struct node;
		node->key = key;
    node->value=value;
		node->left = node->right = NULL;
	}
	else if(value <= node->value)
		node->left = insertNode(node->left,key,value);
	else 
		node->right = insertNode(node->right,key,value);
	return node;
}
// Deleting a node
struct node *deleteNode(struct node *root, char key) {
  if(root==NULL){
    return root;
  }else if ( root->key > key){
    root->left=deleteNode(root->left,key);
  }else if ( root->key < key){
    root->right=deleteNode(root->right,key);
  }else {
    if(root->left==NULL && root->right==NULL){
      delete root;
      root=NULL;
    }else if (root->left==NULL){
      node* temp=root;
      root=root->right;
      delete temp;
    }else if (root->right==NULL){
      node* temp=root;
      root=root->left;
      delete temp;
    }else {
      node* temp=findMin(root->right);
      root->key=temp->key;
      root->right=deleteNode(root->right,temp->key);
    }
  }
  return root;
 
}

// Driver code
int main() {
  struct node *root = NULL;
  int n=1;
  int k=1;

  int operation;
  char operand;
  cin >> operation;

  while (operation != -1) {
    k++;
    n++;
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand, 10+  pow(-1,n)*k );
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  cout<< endl;
  decode_huff(root ,"1100");
}