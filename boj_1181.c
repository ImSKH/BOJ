#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
  char Word[52];
  struct _node *left;
  struct _node *right;
}Node;

Node *addN(Node *root, char S[]){
  if(root==NULL){
    root=(Node*)malloc(sizeof(Node));
    root->left=root->right=NULL;
    strcpy(root->Word,S);
    return root;
  }
  else{
    if(strlen(S)<strlen(root->Word)) root->left=addN(root->left,S);
    else if(strlen(S)>strlen(root->Word)) root->right=addN(root->right,S);
    else if(strlen(S)==strlen(root->Word)){
      int i=0;
      while(root->Word[i]==S[i]) i++;
      if(i>=strlen(S)) return root;
      else{
        if(root->Word[i]>S[i]) root->left=addN(root->left,S);
        else root->right=addN(root->right,S);
      }
    }
  }
  return root;
}

void Show(Node *root){
  if(root==NULL) return;
  Show(root->left);
  printf("%s\n",root->Word);
  Show(root->right);
}

int main(){
  Node *root=NULL;
  int N;
  char S[52];
  scanf("%d\n",&N);
  for(int i=0; i<N; i++){
    fgets(S,52,stdin);
    S[strlen(S)-1]='\0';
    root=addN(root,S);
  }
  Show(root);
}
