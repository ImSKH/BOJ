#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  int data;
  struct _node *left;
  struct _node *right;
}Node;

Node *newNode(int data){
  Node *newN=(Node*)malloc(sizeof
  (Node));
  newN->data=data;
  newN->left=newN->right=NULL;
  return newN;
}

Node *addNode(Node *root, int data){
  if(root==NULL) root=newNode(data);
  else if(data<root->data) root->left=addNode(root->left,data);
  else root->right=addNode(root->right,data);

  return root;
}

void show(Node *root){
  if(root==NULL) return;
  show(root->left);
  show(root->right);
  printf("%d\n",root->data);
}

int main(){
  Node *root=NULL;
  int D;
  while(scanf("%d",&D)!=EOF){
    //scanf("%d",&D);
    root=addNode(root,D);
  }
  show(root);
}
