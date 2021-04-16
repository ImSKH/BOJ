#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
  char ch;
  struct _node *left;
  struct _node *right;
}Node;

Node *makeN(char data){
  Node *node=(Node *)malloc(sizeof(Node));
  node->ch=data;
  node->left=node->right=NULL;
  return node;
}

void search(Node *root,char rootdata,char leftchild, char rightchild){
  if(root==NULL) return;
  else if(root->ch==rootdata){
    if(leftchild!='.') root->left=makeN(leftchild);
    if(rightchild!='.') root->right=makeN(rightchild);
  }
  else{
    search(root->left, rootdata,leftchild, rightchild);
    search(root->right, rootdata,leftchild, rightchild);
  }
}

Node *addN(Node *root, char rootdata, char leftchild, char rightchild){
  if(root==NULL){
    if(rootdata!='.') root=makeN(rootdata);
    if(leftchild!='.') root->left=makeN(leftchild);
    if(rightchild!='.') root->right=makeN(rightchild);
  }
  else search(root,rootdata,leftchild,rightchild);
  return root;
}

void preorder(Node *root){
  if(root==NULL) return;
  printf("%c",root->ch);
  preorder(root->left);
  preorder(root->right);
} 

void inorder(Node *root){
  if(root==NULL) return;
  inorder(root->left);
  printf("%c",root->ch);
  inorder(root->right);
}

void postorder(Node *root){
  if(root==NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%c",root->ch);
}

int main(){
  int N;
  char r[10];
  scanf("%d\n",&N);
  Node *root=NULL;
  for(int i=0; i<N; i++){
    fgets(r,10,stdin);
    root=addN(root,r[0],r[2],r[4]);
  }
  preorder(root);
  printf("\n");
  inorder(root);
  printf("\n");
  postorder(root);
}
